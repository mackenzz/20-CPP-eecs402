//
//  InputCheck.cpp
//  project3r
//
//  Created by Zijin Zhang on 11/25/20.
//  Copyright © 2020 Zijin Zhang. All rights reserved.
//

#include "InputCheck.h"

InputCheck:: InputCheck()
{
    this->isValid = false;
}

int InputCheck:: colorCheck()
{
    int colorInt;
    bool isValid = false;
    
    cout << "1.  Red" << endl << "2.  Green" << endl << "3.  Blue"
    << endl << "4.  Black" << endl << "5.  White" << endl;
    
    cout << "Enter int for pattern color: ";
    cin >> colorInt;
    
    if (!cin.fail())
    {
        isValid = true;
    }
    
    while (!isValid) {
        cin.clear();
        cin.ignore(200, '\n');
        cout << "The input color should be an int. "
        << "Please enter again: ";
        cin >> colorInt;
        if (!cin.fail())
        {
            isValid = true;
        }
    }
    
    return colorInt;
}


int InputCheck:: rowColCheck(string inputWordds)
{
    int rowCol;
    bool isValid = false;
    
    cout << inputWordds;
    cin >> rowCol;
    
    if (!cin.fail())
    {
        isValid = true;
    }
    
    while (!isValid) {
        cin.clear();
        cin.ignore(200, '\n');
        cout << "The rows or columns entered should be an int. "
        << "Please enter again: ";
        cin >> rowCol;
        if (!cin.fail())
        {
            isValid = true;
        }
    }


    return rowCol;
}


