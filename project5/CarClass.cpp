#include "CarClass.h"

#include <iostream>
using namespace std;

//Assign the static attribute used for auto-assigning unique ids
int CarClass::nextIdVal = 0;

ostream& operator<<(
     ostream& outStream,
     const CarClass &carToPrint
     )
{
    outStream << "Time: " << carToPrint.arrivalTime <<
                 " Car #" << carToPrint.uniqueId <<
                 " arrives " << carToPrint.travelDir << "-bound";

    /*
     "Time: " << carToPrint.arrivalTime <<
     */
    
  return outStream;
}

