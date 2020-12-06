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
    // The outStream is modified a little to match the printed messages
    outStream << "Time: " << carToPrint.arrivalTime <<
                 " Car #" << carToPrint.uniqueId <<
                 " arrives " << carToPrint.travelDir << "-bound";

    
  return outStream;
}

