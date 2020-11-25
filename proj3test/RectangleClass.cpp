//
//  RectangleClass.cpp
//  project3r
//
//  Created by Zijin Zhang on 11/24/20.
//  Copyright © 2020 Zijin Zhang. All rights reserved.
//

#include "RectangleClass.h"
#include "constants.h"


RectangleClass:: RectangleClass()
{
    this->method = "";
}

void RectangleClass:: askForMethod()
{
    string lineStr;
    cout << "Enter int for rectangle specification method: ";
    cin >> lineStr;
    
    while (lineStr != METHOD_LEFT_RIGHT &&
           lineStr != METHOD_LEFT_DIMENSION &&
           lineStr != METHOD_CENTER)
    {
        cout << "An integer of 1, 2 or 3 is expected to enter,"
        << "plesase enter again: " << endl;
        cin >> lineStr;
    }
    
    this->method = lineStr;
}


void RectangleClass:: optionMenu()
{
    istringstream iss;
    string lineStr;
    
    
    if (this->method == METHOD_LEFT_RIGHT)
    {
        cout << "Enter upper left corner row: ";
        cin >> lineStr;
        iss.str(lineStr);
        iss >> upperLeft[0];
        iss.clear();
        cout << "Enter upper left corner column: ";
        cin >> lineStr;
        iss.str(lineStr);
        iss >> upperLeft[1];
        iss.clear();
        cout << "Enter lower right corner row: ";
        cin >> lineStr;
        iss.str(lineStr);
        iss >> lowerRight[0];
        iss.clear();
        cout << "Enter lower right corner column : ";
        cin >> lineStr;
        iss.str(lineStr);
        iss >> lowerRight[1];
        iss.clear();
    }
    else if (this->method == METHOD_LEFT_DIMENSION)
    {
        int numHeight = 0;
        int numWidth = 0;
        cout << "Enter upper left corner row: ";
        cin >> lineStr;
        iss.str(lineStr);
        iss >> upperLeft[0];
        iss.clear();
        cout << "Enter upper left corner column: ";
        cin >> lineStr;
        iss.str(lineStr);
        iss >> upperLeft[1];
        iss.clear();
        cout << "Enter int for number of rows: ";
        cin >> lineStr;
        iss.str(lineStr);
        iss >> numHeight;
        iss.clear();
        cout << "Enter int for number of columns: ";
        cin >> lineStr;
        iss.str(lineStr);
        iss >> numWidth;
        iss.clear();
        
        lowerRight[0] = upperLeft[0] + numHeight;
        lowerRight[1] = upperLeft[1] + numWidth;
    }
    
    else if (this->method == METHOD_CENTER)
    {
        int centerRow = 0;
        int centerCol = 0;
        int halfRows = 0;
        int halfCols = 0;
        
        cout << "Enter rectangle center row: ";
        cin >> lineStr;
        iss.str(lineStr);
        iss >> centerRow;
        iss.clear();
        cout << "Enter rectangle center column: ";
        cin >> lineStr;
        iss.str(lineStr);
        iss >> centerCol;
        iss.clear();
        cout << "Enter int for half number of rows: ";
        cin >> lineStr;
        iss.str(lineStr);
        iss >> halfRows;
        iss.clear();
        cout << "Enter int for half number of columns: ";
        cin >> lineStr;
        iss.str(lineStr);
        iss >> halfCols;
        iss.clear();
        
        upperLeft[0] = centerRow - halfRows;
        lowerRight[0] = centerRow + halfRows;
        upperLeft[1] = centerCol - halfCols;
        lowerRight[1] = centerCol + halfRows;
    }
    
    
}



