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
//  cout << "THIS FUNCTION NEEDS TO BE IMPLEMENTED" << endl;
    
    // Add car arriving to Queue
    int arriveType = EVENT_UNKNOWN;
    int dirTime = 0;
//    string direction;
//    string car;


    
    // Initialize start arrive time in each direction
    if (currentTime == START_TIME)
    {
        cout << "Time: " << currentTime << " Scheduled ";
        eastCurrTime = getPositiveNormal(eastArrivalMean, eastArrivalStdDev);
        westCurrTime = getPositiveNormal(westArrivalMean, westArrivalStdDev);
        northCurrTime
                = getPositiveNormal(northArrivalMean, northArrivalStdDev);
        southCurrTime
                = getPositiveNormal(southArrivalMean, southArrivalStdDev);
    }
    

    if (travelDir == EAST_DIRECTION)
    {
        arriveType = EVENT_ARRIVE_EAST;
        dirTime = eastCurrTime;
        

    }
    else if (travelDir == WEST_DIRECTION)
    {
        
        arriveType = EVENT_ARRIVE_WEST;
        dirTime = westCurrTime;


    }
    else if (travelDir == NORTH_DIRECTION)
    {

        arriveType = EVENT_ARRIVE_NORTH;
        dirTime = northCurrTime;
        


    }
    else // if (travelDir == SOUTH_DIRECTION)
    {
        
        arriveType = EVENT_ARRIVE_SOUTH;
        dirTime = southCurrTime;
        
    }

    // Schedule an arrive event and insert into the eventList
    EventClass eventArrive = EventClass(dirTime, arriveType);
    eventList.insertValue(eventArrive);
    cout << eventArrive << endl;
    
}





void IntersectionSimulationClass::scheduleLightChange(
     )
{
//  cout << "THIS FUNCTION NEEDS TO BE IMPLEMENTED" << endl;
    cout << "Time: " << currentTime << " Scheduled ";
    // Initialize the start time
    if (currentTime == START_TIME)
    {
        currentTime += eastWestGreenTime;
    }
    
    // Scheduel the event
    if (currentLight == LIGHT_GREEN_EW)
    {
        // If current light is GREEN_EW, next event scheduled: YELLOW_EW
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
        EventClass eventLightInit = EventClass(
                                               currentTime,
                                               EVENT_CHANGE_GREEN_EW
                                               );
        
        eventList.insertValue(eventLightInit);
        cout << eventLightInit << endl;
    }
    
    
}


















bool IntersectionSimulationClass::handleNextEvent(
     )
{
//    cout << "THIS FUNCTION NEEDS TO BE IMPLEMENTED" << endl;

    
    // Arrange time interval in this function
    // different events are scheduled in between
    int timeInterval;
    double mean;
    double stdDev;
    string direction;
    EventClass currEvent;
    bool isBeforeEndTime = true;
    CarClass outCar;

    
    // The ealier event in a sorted list occurs at the front
    eventList.removeFront(currEvent);
    cout << "\nHandling " << currEvent << endl;
    int currType = currEvent.getType();
    
    
    //**************** Arive Event ****************
    // Arrange next "Arrive"
    if (currType == EVENT_ARRIVE_EAST || currType == EVENT_ARRIVE_WEST ||
        currType == EVENT_ARRIVE_NORTH || currType == EVENT_ARRIVE_SOUTH)
    {
        // Initiate time params for different events
        if (currType == EVENT_ARRIVE_EAST)
        {
            mean = eastArrivalMean;
            stdDev = eastArrivalStdDev;
            direction = EAST_DIRECTION;
            timeInterval = getPositiveNormal(mean, stdDev);
            
            CarClass car(direction, eastCurrTime + timeInterval);
            eastQueue.enqueue(car);
            cout << car << " - queue length: "
                 << eastQueue.getNumElems() << endl;
            
            cout << "Time: " << eastCurrTime << " Scheduled ";
            eastCurrTime += timeInterval;
            
            

        }
        else if (currType == EVENT_ARRIVE_WEST)
        {
            mean = westArrivalMean;
            stdDev = westArrivalStdDev;
            direction = WEST_DIRECTION;
            timeInterval = getPositiveNormal(mean, stdDev);
            
            CarClass car(direction, westCurrTime + timeInterval);
            westQueue.enqueue(car);
            cout << car << " - queue length: "
            << westQueue.getNumElems() << endl;
            
            cout << "Time: " << westCurrTime << " Scheduled ";
            westCurrTime += timeInterval;
            
            
        }
        else if (currType == EVENT_ARRIVE_NORTH)
        {
            mean = northArrivalMean;
            stdDev = northArrivalStdDev;
            direction = NORTH_DIRECTION;
            timeInterval = getPositiveNormal(mean, stdDev);
            
            CarClass car(direction, northCurrTime);
            northQueue.enqueue(car);
            cout << car << " - queue length: "
            << northQueue.getNumElems() << endl;
            
            cout << "Time: " << northCurrTime << " Scheduled ";
            northCurrTime += timeInterval;
            
        }
        else // if (currType == EVENT_ARRIVE_SOUTH)
        {
            mean = southArrivalMean;
            stdDev = southArrivalStdDev;
            direction = SOUTH_DIRECTION;
            timeInterval = getPositiveNormal(mean, stdDev);
            
            CarClass car(direction, southCurrTime);
            southQueue.enqueue(car);
            cout << car << " - queue length: "
            << southQueue.getNumElems() << endl;
            
            cout << "Time: " << southCurrTime << " Scheduled ";
            southCurrTime += timeInterval;
            
        }
        
        // Schedule next arrive event
        scheduleArrival(direction);
        
    }
    //**************** Change Light Event ****************
    else if (currType == EVENT_CHANGE_YELLOW_NS)
    {
        // clear the cars in east and north during GREEN_NS (previous light)
        // Add time interval of current light event
        currentTime += northSouthYellowTime;
        
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
                numTotalAdvancedNorth += 1;
            }
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
                numTotalAdvancedSouth += 1;
            }
        }
        //****************
        
        // Arrange next light change: CHANGE_YELLO_NS
        currentLight = LIGHT_YELLOW_NS;
        scheduleLightChange();
        
    }
    //**************** Light Change Event ****************
    else if (currType == EVENT_CHANGE_YELLOW_EW)
    {
        // Advance cars in east direction during GREEN_EW
        currentTime += eastWestYellowTime;
        
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
                numTotalAdvancedEast += 1;
                
            }
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
//                westQueue.dequeue(CarClass());
                numTotalAdvancedWest += 1;
            }
        }
        
        //****************
        // Schedule the next CHANG_YELLO_EW event and change Light color
        currentLight = LIGHT_YELLOW_EW;
        scheduleLightChange();
    }
    
    else if (currType == EVENT_CHANGE_GREEN_EW)
    {
        // Advance cars in east direction during YELLOW_NS
        currentTime += eastWestGreenTime;
        
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
                    northQueue.dequeue(outCar);
                    numTotalAdvancedNorth += 1;
                }
                else
                {
                    break;
                }
                
            }
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
                    southQueue.dequeue(outCar);
                    numTotalAdvancedSouth += 1;
                }
                else
                {
                    break;
                }
            }
        }

        
        //****************
        currentLight = LIGHT_GREEN_EW;
        scheduleLightChange();
        
        
    }
    else if (currType == EVENT_CHANGE_GREEN_NS)
    {
        // Advance cars in east direction during YELLOW_EW
        currentTime += northSouthGreenTime;
        
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
                    eastQueue.dequeue(outCar);
                    numTotalAdvancedEast += 1;
                }
                else
                {
                    break;
                }
                
            }
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
                    westQueue.dequeue(outCar);
                    numTotalAdvancedWest += 1;
                }
                else
                {
                    break;
                }
                
            }
        }

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
    
    
    
    
    
    
    if (currentTime > timeToStopSim)
    {
        isBeforeEndTime = false;
    }
    
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



