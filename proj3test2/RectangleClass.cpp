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

bool RectangleClass:: isValidRowCol(
                                    int point[2]
                                    )
{
    bool isValid = false;
    if (point[0] >= 0 && point[1] >= 0 &&
        point[0] < ARRAY_INITIIAL_HEIGHT &&
        point[1] < ARRAY_INITIIAL_WIDTH)
    {
        isValid = true;
    }
    
    return isValid;
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
    string lineStr2;
    // Initialize upperLeft and lowerRight array
    bool isValid = false;
    
    
    if (this->method == METHOD_LEFT_RIGHT)
    {
        
        cout << "Enter upper left corner row and column: ";
        cin >> upperLeft[0] >> upperLeft[1];
        if (!cin.fail())
        {
            isValid = true;
        }
        
        while (!isValid) {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "The row and column should be int. "
            << "Please enter again: ";
            cin >> upperLeft[0] >> upperLeft[1];
            if (!cin.fail())
            {
                isValid = true;
            }

        }
        
        isValid = false;
        
        cout << "Enter lower right corner row and column: ";
        cin >> lowerRight[0] >> lowerRight[1];
        if (!cin.fail())
        {
            isValid = true;
        }
        
        while (!isValid) {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "The row and column should be int. "
            << "Please enter again: ";
            cin >> lowerRight[0] >> lowerRight[1];
            if (!cin.fail())
            {
                isValid = true;
            }
        }
        

        
    }
    
    else if (this->method == METHOD_LEFT_DIMENSION)
    {
        isValid = false;
        cout << "Enter upper left corner row and column: ";
        cin >> upperLeft[0] >> upperLeft[1];
        if (!cin.fail())
        {
            isValid = true;
        }
        
        while (!isValid) {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "The row and column should be int. "
            << "Please enter again: ";
            cin >> lowerRight[0] >> lowerRight[1];
            if (!cin.fail())
            {
                isValid = true;
            }
        }

        
        
        int numHeight = 0;
        int numWidth = 0;
        
        isValid = false;
        cout << "Enter int for number of rows: ";
        cin >> numHeight;
        if (!cin.fail())
        {
            isValid = true;
        }
        
        while (!isValid) {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "The number of rows should be an int. "
            << "Please enter again: ";
            cin >> numHeight;
            if (!cin.fail())
            {
                isValid = true;
            }
        }
        
        
        
        
        isValid = false;
        
        cout << "Enter int for number of columns: ";
        cin >> numWidth;
        if (!cin.fail())
        {
            isValid = true;
        }
        
        while (!isValid) {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "The number of columns should be an int. "
            << "Please enter again: ";
            cin >> numWidth;
            if (!cin.fail())
            {
                isValid = true;
            }
        }
        
        

        
        lowerRight[0] = upperLeft[0] + numHeight;
        lowerRight[1] = upperLeft[1] + numWidth;
         
    }
    
    
    else if (this->method == METHOD_CENTER)
    {
        int centerRow = 0;
        int centerCol = 0;
        int halfRows = 0;
        int halfCols = 0;
        
        isValid = false;
        cout << "Enter rectangle center row and column: ";
        cin >> centerRow >> centerCol;
        if (!cin.fail())
        {
            isValid = true;
        }
        
        while (!isValid) {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "The row and column should be int. "
            << "Please enter again: ";
            cin >> centerRow >> centerCol;
            if (!cin.fail())
            {
                isValid = true;
            }
        }
        
        
        
        isValid = false;
        
        cout << "Enter int for half number of rows: ";
        cin >> halfRows;
        if (!cin.fail())
        {
            isValid = true;
        }
        
        while (!isValid) {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "The number of columns should be an int. "
            << "Please enter again: ";
            cin >> halfRows;
            if (!cin.fail())
            {
                isValid = true;
            }
        }
        
        
        
        isValid = false;
        
        cout << "Enter int for half number of columns: ";
        cin >> halfCols;
        if (!cin.fail())
        {
            isValid = true;
        }
        
        while (!isValid) {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "The number of columns should be an int. "
            << "Please enter again: ";
            cin >> halfCols;
            if (!cin.fail())
            {
                isValid = true;
            }
        }
        

        upperLeft[0] = centerRow - halfRows;
        lowerRight[0] = centerRow + halfRows;
        upperLeft[1] = centerCol - halfCols;
        lowerRight[1] = centerCol + halfRows;
    }
    
    
}













