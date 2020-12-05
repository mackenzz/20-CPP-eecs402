#include <iostream>
#include <string>
using namespace std;

#include "IntersectionSimulationClass.h"
#include "LinkedNodeClass.h"
#include "SortedListClass.h"
#include "FIFOQueueClass.h"
#include "EventClass.h"

//Programmer: Andrew Morgan 
//Date: November 2020 (11/26/2020)
//Purpose: High-level main function to setup a simulation of traffic
//         flow through an intersection.  This is being written to
//         implement project 5 in EECS402.
int main(
     int argc,
     char *argv[]
     )
{
    /* test template classes
    SortedListClass<string> testList;
    //testList.printForward();
    testList.insertValue("12");
    testList.insertValue("abc");
    string testRemove;

    testList.clear();
    testList.printForward();
    
    FIFOQueueClass<string> queue;
    queue.enqueue("abs");
    queue.enqueue("  ");
    cout << queue.getNumElems() << endl;
     */
    
    /* test eventClass
    EventClass eventTest = EventClass(7, 0);
    int timetest;
    timetest = eventTest.getTimeOccurs();
    cout << "time occur: " << timetest << endl;
    */
    
    /* // test CarClss
    cout << "************************" << endl;
    FIFOQueueClass<CarClass> CarQueueTest;
//    CarClass carTest(EAST_DIRECTION, 0);
//    CarClass carTest2(NORTH_DIRECTION, 4);
    CarQueueTest.enqueue(CarClass(EAST_DIRECTION, 0));
    CarQueueTest.enqueue(CarClass(NORTH_DIRECTION, 4));
    CarQueueTest.print();
    cout << "************************" << endl;
    */
    
  bool success = true;
  string specifiedParamFname;
  IntersectionSimulationClass simObj;

  //Check that user specified the necessary command line arg(s)..


  // Uncomment when using Cean lab
  if (argc != 2)
  {
    cout << "Usage: " << argv[0] << " <parameterFile>" << endl;
    success = false;
  }
  else
  {
    specifiedParamFname = string(argv[1]);
  }

     

    



  if (success)
  {
    //Read input parameters and print to screen for reference..
    cout << "Reading parameters from file: " << specifiedParamFname << endl;
    simObj.readParametersFromFile(specifiedParamFname);
    simObj.printParameters();

    if (!simObj.getIsSetupProperly())
    {
      cout << "Cannot run simulation as it is not setup properly!" << endl;
      success = false;
    }
  }

    
    

  if (success)
  {
    //Schedule the initial events that will "seed" the event-driven simulation
    //Initial events
    cout << endl;
    cout << "Schedule simulation seed events" << endl;
    simObj.scheduleSeedEvents();

      
    //When the simulation recognizes it should stop handling events,
    //the call to "handleNextEvent" will return false.  This is
    //expected to occur when the next event's schedule time is 
    //after the end time of the simulation (an input parameter).
    cout << endl;
    cout << "Starting simulation!" << endl;

    bool doKeepRunning = true;
    while (doKeepRunning)
    {
      //Handle the next scheduled event now..
      doKeepRunning = simObj.handleNextEvent();
    }
      
  }

    
    
    
    
  //Indicate whether things went well or not, and, if so, print out the
  //simualtion statistics that were computed during the run.

  if (success)
  {
    cout << "Simulation ran successfully!" << endl;
    simObj.printStatistics();
  }
  else
  {
    cout << "Simulation did NOT run successfully..." << endl;
  }


  return 0;
}
