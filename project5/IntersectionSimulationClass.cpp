#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "IntersectionSimulationClass.h"
#include "random.h"
#include "EventClass.h"

void IntersectionSimulationClass::readParametersFromFile(
     const string &paramFname
     )
{
  bool success = true;;
  ifstream paramF;

  paramF.open(paramFname.c_str());

  //Check that the file was able to be opened...
  if (paramF.fail())
  {
    success = false;
    cout << "ERROR: Unable to open parameter file: " << paramFname << endl;
  }
  else
  {
    //Now read in all the params, according to the specified format of
    //the text-based parameter file.
    if (success)
    {
      paramF >> randomSeedVal;
      if (paramF.fail() ||
          randomSeedVal < 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set random generatsor seed" << endl;
      }
    }

    if (success)
    {
      paramF >> timeToStopSim;
      if (paramF.fail() ||
          timeToStopSim <= 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set simulation end time" << endl;
      }
    }

    if (success)
    {
      paramF >> eastWestGreenTime >> eastWestYellowTime;
      if (paramF.fail() ||
          eastWestGreenTime <= 0 ||
          eastWestYellowTime <= 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set east-west times" << endl;
      }
    }

    if (success)
    {
      paramF >> northSouthGreenTime >> northSouthYellowTime;
      if (paramF.fail() ||
          northSouthGreenTime <= 0 ||
          northSouthYellowTime <= 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set north-south times" << endl;
      }
    }

    if (success)
    {
      paramF >> eastArrivalMean >> eastArrivalStdDev;
      if (paramF.fail() ||
          eastArrivalMean <= 0 ||
          eastArrivalStdDev < 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set east arrival distribution" << endl;
      }
    }

    if (success)
    {
      paramF >> westArrivalMean >> westArrivalStdDev;
      if (paramF.fail() ||
          westArrivalMean <= 0 ||
          westArrivalStdDev < 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set west arrival distribution" << endl;
      }
    }

    if (success)
    {
      paramF >> northArrivalMean >> northArrivalStdDev;
      if (paramF.fail() ||
          northArrivalMean <= 0 ||
          northArrivalStdDev < 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set north arrival distribution" << endl;
      }
    }

    if (success)
    {
      paramF >> southArrivalMean >> southArrivalStdDev;
      if (paramF.fail() ||
          southArrivalMean <= 0 ||
          southArrivalStdDev < 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set south arrival distribution" << endl;
      }
    }

    if (success)
    {
      paramF >> percentCarsAdvanceOnYellow;
      if (paramF.fail() ||
          percentCarsAdvanceOnYellow < 0 ||
          percentCarsAdvanceOnYellow > 100)
      {
        success = false;
        cout << "ERROR: Unable to read/set percentage yellow advance" << endl;
      }

      //Use the specified seed to seed the random number generator
      setSeed(randomSeedVal);
    }

    paramF.close();
  }

  //Let the caller know whether things went well or not by printing the
  if (!success)
  {
    cout << "ERROR: Parameter file was NOT read in successfully, so the " <<
            "simulation is NOT setup properly!" << endl;
    isSetupProperly = false;
  }
  else
  {
    cout << "Parameters read in successfully - simulation is ready!" << endl;
    isSetupProperly = true;
  }
}




void IntersectionSimulationClass::printParameters() const
{
  cout << "===== Begin Simulation Parameters =====" << endl;
  if (!isSetupProperly)
  {
    cout << "  Simulation is not yet properly setup!" << endl;
  }
  else
  {
    cout << "  Random generator seed: " << randomSeedVal << endl;
    cout << "  Simulation end time: " << timeToStopSim << endl;

    cout << "  East-West Timing -" <<
            " Green: " << eastWestGreenTime <<
            " Yellow: " << eastWestYellowTime <<
            " Red: " << getEastWestRedTime() << endl;

    cout << "  North-South Timing -" <<
            " Green: " << northSouthGreenTime <<
            " Yellow: " << northSouthYellowTime <<
            " Red: " << getNorthSouthRedTime() << endl;

    cout << "  Arrival Distributions:" << endl;
    cout << "    East - Mean: " << eastArrivalMean <<
            " StdDev: " << eastArrivalStdDev << endl;
    cout << "    West - Mean: " << westArrivalMean <<
            " StdDev: " << westArrivalStdDev << endl;
    cout << "    North - Mean: " << northArrivalMean <<
            " StdDev: " << northArrivalStdDev << endl;
    cout << "    South - Mean: " << southArrivalMean <<
            " StdDev: " << southArrivalStdDev << endl;

    cout << "  Percentage cars advancing through yellow: " <<
            percentCarsAdvanceOnYellow << endl;
  }
  cout << "===== End Simulation Parameters =====" << endl;
}







void IntersectionSimulationClass::scheduleArrival(
     const string &travelDir
     )
{
    int arriveType = EVENT_UNKNOWN;
    int dirTime = 0;
    double mean;
    double stdDev;
    int timeIntervalArrive = 0;


    if (travelDir == EAST_DIRECTION)
    {
        cout << "Time: " << eastCurrTime << " Scheduled ";
        mean = eastArrivalMean;
        stdDev = eastArrivalStdDev;
        timeIntervalArrive = getPositiveNormal(mean, stdDev);
        eastCurrTime += timeIntervalArrive;
        arriveType = EVENT_ARRIVE_EAST;
        dirTime = eastCurrTime;
    }
    else if (travelDir == WEST_DIRECTION)
    {
        cout << "Time: " << westCurrTime << " Scheduled ";
        mean = westArrivalMean;
        stdDev = westArrivalStdDev;
        timeIntervalArrive = getPositiveNormal(mean, stdDev);
        westCurrTime += timeIntervalArrive;
        arriveType = EVENT_ARRIVE_WEST;
        dirTime = westCurrTime;
    }
    else if (travelDir == NORTH_DIRECTION)
    {
        cout << "Time: " << northCurrTime << " Scheduled ";
        mean = northArrivalMean;
        stdDev = northArrivalStdDev;
        timeIntervalArrive = getPositiveNormal(mean, stdDev);
        northCurrTime += timeIntervalArrive;
        arriveType = EVENT_ARRIVE_NORTH;
        dirTime = northCurrTime;
    }
    else // if (travelDir == SOUTH_DIRECTION)
    {
        cout << "Time: " << southCurrTime << " Scheduled ";
        mean = southArrivalMean;
        stdDev = southArrivalStdDev;
        timeIntervalArrive = getPositiveNormal(mean, stdDev);
        southCurrTime += timeIntervalArrive;
        arriveType = EVENT_ARRIVE_SOUTH;
        dirTime = southCurrTime;
    }

    // Schedule an arrive event and insert into the eventList
    EventClass eventArrive = EventClass(dirTime, arriveType);
    eventList.insertValue(eventArrive);
    cout << eventArrive << endl;
    
}




// *******************************************
void IntersectionSimulationClass::scheduleLightChange(
     )
{
//  cout << "THIS FUNCTION NEEDS TO BE IMPLEMENTED" << endl;
    
    cout << "Time: " << currentTime << " Scheduled ";

    // Scheduel the event
    if (currentLight == LIGHT_GREEN_EW)
    {
        // If current light is GREEN_EW, next event scheduled: YELLOW_EW
        currentTime += eastWestGreenTime;
        EventClass eventLightInit = EventClass(
                                               currentTime,
                                               EVENT_CHANGE_YELLOW_EW
                                               );
        eventList.insertValue(eventLightInit);
        cout << eventLightInit << endl;
        
    }
    
    else if (currentLight == LIGHT_YELLOW_EW)
    {
        // If current light is YELLOW_EW, next event scheduled: GREEN_NS
        currentTime += eastWestYellowTime;
        EventClass eventLightInit = EventClass(
                                               currentTime,
                                               EVENT_CHANGE_GREEN_NS
                                               );
        eventList.insertValue(eventLightInit);
        cout << eventLightInit << endl;
    }
    
    else if (currentLight == LIGHT_GREEN_NS)
    {
        // If current light is GREEN_NS, next event scheduled: YELLOW_NS
        currentTime += northSouthGreenTime;
        EventClass eventLightInit = EventClass(
                                               currentTime,
                                               EVENT_CHANGE_YELLOW_NS
                                               );
        eventList.insertValue(eventLightInit);
        cout << eventLightInit << endl;
    }
    
    else if (currentLight == LIGHT_YELLOW_NS)
    {
        // If current light is YELLOW_EW, next event scheduled: GREEN_NS
        currentTime += northSouthYellowTime;
        EventClass eventLightInit = EventClass(
                                               currentTime,
                                               EVENT_CHANGE_GREEN_EW
                                               );
        
        eventList.insertValue(eventLightInit);
        cout << eventLightInit << endl;
    }
    
    
}

// *******************************************












bool IntersectionSimulationClass::handleNextEvent(
     )
{
//    cout << "THIS FUNCTION NEEDS TO BE IMPLEMENTED" << endl;

    
    // Arrange time interval in this function
    // different events are scheduled in between
    string direction;
    EventClass currEvent;
    bool isBeforeEndTime = true;
    CarClass outCar;

    
    // The ealier event in a sorted list occurs at the front
    eventList.removeFront(currEvent);
    cout << "\nHandling " << currEvent << endl;
    int currType = currEvent.getType();
    
    if (currEvent.getTimeOccurs() >= timeToStopSim)
    {
        isBeforeEndTime = false;
    }
    
    //**************** Arive Event ****************
    // Arrange next "Arrive"
    if (currType == EVENT_ARRIVE_EAST || currType == EVENT_ARRIVE_WEST ||
        currType == EVENT_ARRIVE_NORTH || currType == EVENT_ARRIVE_SOUTH)
    {
        // Initiate time params for different events
        if (currType == EVENT_ARRIVE_EAST)
        {
      
            //Car time before adding timeIntervalArrive
            direction = EAST_DIRECTION;
            CarClass car(direction, eastCurrTime);
            eastQueue.enqueue(car);
            cout << car << " - queue length: "
                 << eastQueue.getNumElems() << endl;
            

        }
        else if (currType == EVENT_ARRIVE_WEST)
        {
            direction = WEST_DIRECTION;
            CarClass car(direction, westCurrTime);
            westQueue.enqueue(car);
            cout << car << " - queue length: "
                 << westQueue.getNumElems() << endl;
            
        }
        else if (currType == EVENT_ARRIVE_NORTH)
        {
            direction = NORTH_DIRECTION;
            CarClass car(direction, northCurrTime);
            northQueue.enqueue(car);
            cout << car << " - queue length: "
            << northQueue.getNumElems() << endl;

        }
        else // if (currType == EVENT_ARRIVE_SOUTH)
        {
            direction = SOUTH_DIRECTION;
            CarClass car(direction, southCurrTime);
            southQueue.enqueue(car);
            cout << car << " - queue length: "
            << southQueue.getNumElems() << endl;
            
        }
        
        // Schedule next arrive event
        scheduleArrival(direction);
        
    }
    //**************** Change Light Event ****************
    else if (currType == EVENT_CHANGE_YELLOW_NS)
    {
        cout << "Advancing cars on north-south green" << endl;
        int northAdvance = 0;
        int southAdvance = 0;
        //****************
        int numNorthGreen = northQueue.getNumElems();
        if (numNorthGreen > maxNorthQueueLength)
        {
            maxNorthQueueLength = numNorthGreen;
        }
        if (northQueue.getNumElems() > 0)
        {
            for (int i = 0; i < numNorthGreen; i++)
            {
                // outCar is used as place holder for deueue
                if (i >= northSouthGreenTime)
                {
                    break;
                }
                
                northQueue.dequeue(outCar);
                cout << "  Car #" << outCar.getId()
                     << " advances north-bound" << endl;
                numTotalAdvancedNorth += 1;
                northAdvance += 1;
            }
        }
        else // no car is waiting in the queue
        {
            cout << "No north-bound cars waiting to advance on green\n";
        }
        
        // Clear south queue
        int numSouthGreen = southQueue.getNumElems();
        if (numSouthGreen > maxSouthQueueLength)
        {
            maxSouthQueueLength = numSouthGreen;
        }
        
        if (southQueue.getNumElems() > 0)
        {
            for (int i = 0; i < numSouthGreen; i++)
            {
                if (i >= northSouthGreenTime)
                {
                    break;
                }
                
                southQueue.dequeue(outCar);
                cout << "  Car #" << outCar.getId()
                     << " advances south-bound" << endl;
                numTotalAdvancedSouth += 1;
                southAdvance += 1;
            }
        }
        else
        {
            cout << "No south-bound cars waiting to advance on green\n";
        }
        
        cout << "North-bound cars advanced on green: " << northAdvance
        << " Remaining queue: " << northQueue.getNumElems() << endl;
        cout << "South-bound cars advanced on green: " << southAdvance
        << " Remaining queue: " << southQueue.getNumElems() << endl;
        
        
        //****************
        
        // Arrange next light change: CHANGE_YELLO_NS
        currentLight = LIGHT_YELLOW_NS;
        scheduleLightChange();
        
    }
    //**************** Light Change Event ****************
    else if (currType == EVENT_CHANGE_YELLOW_EW)
    {
        cout << "Advancing cars on east-west green" << endl;
        int eastAdvance = 0;
        int westAdvance = 0;
        
        //****************
        int numEastGreen = eastQueue.getNumElems();
        if (numEastGreen > maxEastQueueLength)
        {
            maxEastQueueLength = numEastGreen;
        }
        if(eastQueue.getNumElems() > 0)
        {
            for (int i = 0; i < numEastGreen; i++)
            {
                if (i >= eastWestGreenTime)
                {
                    break;
                }
                // outCar is used as place holder for deueue
                eastQueue.dequeue(outCar);
                eastAdvance += 1;
                cout << "  Car #" << outCar.getId()
                     << " advances east-bound" << endl;
                numTotalAdvancedEast += 1;
                
            }
        }
        else
        {
            cout << "No east-bound cars waiting to advance on green\n";
        }
        
        // Advance cars in west direction during GREEN_EW
        int numWestGreen = westQueue.getNumElems();
        if (numWestGreen > maxWestQueueLength)
        {
            maxWestQueueLength = numWestGreen;
        }
        if (westQueue.getNumElems() > 0)
        {
            for (int i = 0; i < numWestGreen; i++)
            {
                if (i >= eastWestGreenTime)
                {
                    break;
                }
                
                westQueue.dequeue(outCar);
                westAdvance += 1;
                cout << "  Car #" << outCar.getId()
                     << " advances west-bound" << endl;
                numTotalAdvancedWest += 1;
            }
        }
        else
        {
            cout << "No west-bound cars waiting to advance on green\n";
        }
        
        cout << "East-bound cars advanced on green: " << eastAdvance
        << " Remaining queue: " << eastQueue.getNumElems() << endl;
        cout << "West-bound cars advanced on green: " << westAdvance
        << " Remaining queue: " << westQueue.getNumElems() << endl;
        
        //****************
        // Schedule the next CHANG_YELLO_EW event and change Light color
        currentLight = LIGHT_YELLOW_EW;
        scheduleLightChange();
    }
    
    else if (currType == EVENT_CHANGE_GREEN_EW)
    {
        cout << "Advancing cars on north-south yellow" << endl;
        int northAdvance = 0;
        int southAdvance = 0;
        
        //****************
        int randAdvanceYellow = 0;
        int numNorthYello = northQueue.getNumElems();
        if (numNorthYello > maxNorthQueueLength)
        {
            maxNorthQueueLength = numNorthYello;
        }
        // Clear the north queue when it wishes to advance
        if (northQueue.getNumElems() > 0)
        {
            for (int i = 0; i < numNorthYello; i++)
            {
                if (i >= northSouthYellowTime)
                {
                    break;
                }
                
                randAdvanceYellow = getUniform(1, 100);
                
                if (randAdvanceYellow <= percentCarsAdvanceOnYellow)
                {
                    cout << "  Next north-bound car will advance on yellow\n";
                    northQueue.dequeue(outCar);
                    northAdvance += 1;
                    cout << "  Car #" << outCar.getId()
                         << " advances north-bound" << endl;
                    numTotalAdvancedNorth += 1;
                }
                else
                {
                    cout <<
                    "  Next north-bound car will NOT advance on yellow\n";
                    break;
                }
                
            }
        }
        else
        {
            cout << "  No north-bound cars waiting to advance on yellow\n";
        }


        // Clear south queue
        // Clear the west queue when it wishes to advance
        int numSouthYello = southQueue.getNumElems();
        if (numSouthYello > maxSouthQueueLength)
        {
            maxSouthQueueLength = numSouthYello;
        }
        if (southQueue.getNumElems() > 0)
        {
            for (int i = 0; i < numSouthYello; i++)
            {
                if (i >= northSouthGreenTime)
                {
                    break;
                }
                
                randAdvanceYellow = getUniform(1, 100);
                if (randAdvanceYellow <= percentCarsAdvanceOnYellow)
                {
                    cout << "  Next south-bound car will advance on yellow\n";
                    southQueue.dequeue(outCar);
                    southAdvance += 1;
                    cout << "  Car #" << outCar.getId()
                         << " advances south-bound" << endl;
                    numTotalAdvancedSouth += 1;
                }
                else
                {
                    cout <<
                    "  Next south-bound car will NOT advance on yellow\n";
                    break;
                }
            }
        }
        else
        {
            cout << "  No south-bound cars waiting to advance on yellow\n";
        }
        
        cout << "North-bound cars advanced on yellow: " << northAdvance
        << " Remaining queue: " << northQueue.getNumElems() << endl;
        cout << "South-bound cars advanced on yellow: " << southAdvance
        << " Remaining queue: " << southQueue.getNumElems() << endl;
        
        //****************
        currentLight = LIGHT_GREEN_EW;
        scheduleLightChange();
        
        
    }
    else if (currType == EVENT_CHANGE_GREEN_NS)
    {
        cout << "Advancing cars on east-west yellow" << endl;
        int eastAdvance = 0;
        int westAdvance = 0;
        //****************
        int randAdvanceYellow = 0;
        
        // Clear the east queue when it wishes to advance
        int numEastYello = eastQueue.getNumElems();
        if (numEastYello > maxEastQueueLength)
        {
            maxEastQueueLength = numEastYello;
        }
        if (eastQueue.getNumElems() > 0)
        {
            for (int i = 0; i < numEastYello; i++)
            {
                if (i >= eastWestYellowTime)
                {
                    break;
                }
                
                randAdvanceYellow = getUniform(1, 100);
                if (randAdvanceYellow <= percentCarsAdvanceOnYellow)
                {
                    cout << "  Next east-bound car will advance on yellow\n";
                    eastQueue.dequeue(outCar);
                    eastAdvance += 1;
                    cout << "  Car #" << outCar.getId()
                         << " advances east-bound" << endl;
                    numTotalAdvancedEast += 1;
                }
                else
                {
                    cout <<
                    "  Next east-bound car will NOT advance on yellow\n";
                    break;
                }
                
            }
        }
        else
        {
            cout << "  No east-bound cars waiting to advance on yellow\n";
        }

        // Clear west queue
        // Clear the west queue when it wishes to advance
        int numWestYello = westQueue.getNumElems();
        if (numWestYello > maxWestQueueLength)
        {
            maxWestQueueLength = numWestYello;
        }
        if (westQueue.getNumElems() > 0)
        {
            for (int i = 0; i < numWestYello; i++)
            {
                if (i >= eastWestYellowTime)
                {
                    break;
                }
                
                randAdvanceYellow = getUniform(1, 100);
                if (randAdvanceYellow <= percentCarsAdvanceOnYellow)
                {
                    cout << "  Next west-bound car will advance on yellow\n";
                    westQueue.dequeue(outCar);
                    westAdvance += 1;
                    cout << "  Car #" << outCar.getId()
                         << " advances west-bound" << endl;
                    numTotalAdvancedWest += 1;
                }
                else
                {
                    cout <<
                    "  Next west-bound car will NOT advance on yellow\n";
                    break;
                }
                
            }
        }
        else
        {
            cout << "  No west-bound cars waiting to advance on yellow\n";
        }
        
        cout << "East-bound cars advanced on yellow: " << eastAdvance
        << " Remaining queue: " << eastQueue.getNumElems() << endl;
        cout << "West-bound cars advanced on yellow: " << westAdvance
        << " Remaining queue: " << westQueue.getNumElems() << endl;
        
        
        //****************
        currentLight = LIGHT_GREEN_NS;
        scheduleLightChange();
    }
    
    
    
    
    
    
//    eventList.printForward();
//    cout << "eastQueue: ";
////    eastQueue.print();
//    cout << eastQueue.getNumElems();
//    cout << endl;
//    cout << "westQueue: ";
////    westQueue.print();
//    cout << westQueue.getNumElems();
//    cout << endl;
//    cout << "northQueue: ";
////    northQueue.print();
//    cout << northQueue.getNumElems();
//    cout << endl;
//    cout << "southQueue: ";
////    southQueue.print();
//    cout << southQueue.getNumElems();
//    cout << endl;
    
    
    
    
    
    
//    if (currentTime > timeToStopSim)
//    {
//        isBeforeEndTime = false;
//    }
    
    return isBeforeEndTime;
}










void IntersectionSimulationClass::printStatistics(
     ) const
{
  cout << "===== Begin Simulation Statistics =====" << endl;
  cout << "  Longest east-bound queue: " << maxEastQueueLength << endl;
  cout << "  Longest west-bound queue: " << maxWestQueueLength << endl;
  cout << "  Longest north-bound queue: " << maxNorthQueueLength << endl;
  cout << "  Longest south-bound queue: " << maxSouthQueueLength << endl;
  cout << "  Total cars advanced east-bound: " <<
          numTotalAdvancedEast << endl;
  cout << "  Total cars advanced west-bound: " <<
          numTotalAdvancedWest << endl;
  cout << "  Total cars advanced north-bound: " <<
          numTotalAdvancedNorth << endl;
  cout << "  Total cars advanced south-bound: " <<
          numTotalAdvancedSouth << endl;
  cout << "===== End Simulation Statistics =====" << endl;
}



