//
//  proj3.cpp
//  eecs402 project3
//
//  Created by Zijin Zhang on 11/1/20.
//  Copyright © 2020 Zijin Zhang. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "ImgLoadClass.h"
#include "ImgOutputClass.h"
#include "ReadPatternClass.h"
#include "ImgModifyClass.h"
#include "RectangleClass.h"
#include "InputCheck.h"
#include "constants.h"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    string inputFile;
    string patternFile;
    string patternPosition;
    
    // Initialize the choice to be write out current image
    string choice = CHOICE_WRITE_CURRENT;
    istringstream iss;
    string lineStr;
    int patternHeight = 0;
    int patternWidth = 0;
    string colorStr;
    int colorInt = 0;

    string imgToAdd;
    int insertHeight = 0;
    int insertWidth = 0;
    string isFilledStr = "";
    bool isFilled = false;
    string method;


    string colorTrans;
    string inputWords;

    
    string outFile;
    
    // Ask for string of input file 
    cout << "Enter string for PPM image file name to load: ";
    cin >> inputFile;
    
    
    // Initialize 2D array in size of input image
    string **inputArray = new string *[ARRAY_INITIIAL_HEIGHT];
    for (int i = 0; i < ARRAY_INITIIAL_HEIGHT; i++)
    {
        inputArray[i] = new string[ARRAY_INITIIAL_WIDTH * NUM_RGB];
    }
    // Generate 2D array of input image
    ImgLoad inputImgLoad(inputFile);
    inputArray = inputImgLoad.loadToBuffer();
    // Error checking for not able to open file
    if (!inputArray)
    {
        return 0;
    }

    // Initialize the output array
    string **outputArray = new string *[ARRAY_INITIIAL_HEIGHT];
    for (int i = 0; i < ARRAY_INITIIAL_HEIGHT; i++)
    {
        outputArray[i] = new string[ARRAY_INITIIAL_WIDTH * NUM_RGB];
    }
    
    
    
    while (choice != CHOICE_EXIT)
    {
        cout << "1.  Annotate image with rectangle" << endl
        << "2.  Annotate image with pattern from file" << endl
        << "3.  Insert another image" << endl
        << "4.  Write out current image" << endl
        << "5.  Exit the program" << endl
        << "Enter int for main menu choice: ";
        cin >> choice;
        
        
        // Error checking for a wrong typed-in choice.
        while (choice != CHOICE_ADD_PATTERN &&
               choice != CHOICE_INSERT_IMAGE &&
               choice != CHOICE_ADD_RECTANGLE &&
               choice != CHOICE_WRITE_CURRENT &&
               choice != CHOICE_EXIT)
        {
            cout << "An integer of 1, 2, 3, 4 or 5 is expected to enter"
                 << "please enter again: ";
            cin >> choice;
        }
        
   
        
        
        // Choice 2: Annotate image with pattern from file
        if (choice == CHOICE_ADD_PATTERN)
        {
            cout << "Enter string for file name containing pattern: ";
            cin >> patternFile;
            
            inputWords = "Enter upper left corner of pattern row: ";
            InputCheck rowCol1;
            patternHeight = rowCol1.rowColCheck(inputWords);
            
            inputWords = "Enter upper left corner of pattern column: ";
            InputCheck rowCol2;
            patternWidth = rowCol2.rowColCheck(inputWords);
            
            
            InputCheck color;
            colorInt = color.colorCheck();

            // Output the changed image array
            ImgModify ImgPattern(inputFile);
            outputArray = ImgPattern.addPattern(patternFile, patternHeight,
                                  patternWidth, colorInt, outFile, inputArray);
            inputArray = outputArray;

        }
        
        
        // Choice 3: Insert another image
        else if (choice == CHOICE_INSERT_IMAGE)
        {
            cout << "Enter string for file name of PPM image to insert: ";
            cin >> imgToAdd;
            
            inputWords = "Enter upper left corner to insert image row: ";
            InputCheck rowCol1;
            insertHeight = rowCol1.rowColCheck(inputWords);

            inputWords = "Enter upper left corner to insert image column: ";
            InputCheck rowCol2;
            insertWidth = rowCol2.rowColCheck(inputWords);
            
            
            
//            cout << "Enter upper left corner to insert image "
//                 << "row and column: ";
//            cin >> lineStr;
//            iss.str(lineStr);
//            iss >> insertHeight;
//            iss.clear();
//            
//            cout << "Enter upper left corner to insert image column: ";
//            cin >> lineStr;
//            iss.str(lineStr);
//            iss >> insertWidth;
//            iss.clear();
            
            
            InputCheck color;
            colorInt = color.colorCheck();
            
            
            // Output the changed image array
            ImgModify ImgInsert(inputFile);
            outputArray = ImgInsert.addImg(imgToAdd, insertHeight,
                             insertWidth, outFile, colorInt, inputArray);

            inputArray = outputArray;
            
        }
        
        
        // Choice 1: Annotate image with rectangle
        else if (choice == CHOICE_ADD_RECTANGLE)
        {
            
            cout << "1.  Specify upper left and lower right"
            << "corners of rectangle" << endl;
            cout << "2.  Specify upper left corner and"
            "dimensions of rectangle" << endl;
            cout << "3.  Specify extent from center of rectangle"
            << endl;
            
            RectangleClass rectangle;
            rectangle.askForMethod();
            rectangle.optionMenu();
            
            InputCheck color;
            colorInt = color.colorCheck();
            
            
            
            cout << "1.  No" << endl << "2.  Yes" << endl;
            cout << "Enter int for rectangle fill option: ";
            cin >> isFilledStr;
            
            while (isFilledStr != "2" && isFilledStr != "1")
            {
                cout << "The fill option should be an integer 1 or 2. "
                << "Please enter again: ";
                cin >> isFilledStr;
            }
            
            if (isFilledStr == "2")
            {
                isFilled = true;
            }
            else if (isFilledStr == "1")
            {
                isFilled = false;
            }
            
            
            ImgModify ImgRec(inputFile);
            outputArray = ImgRec.addRectangle(rectangle.upperLeft,
                                              rectangle.lowerRight,
                                              colorInt,
                                              isFilled,
                                              outFile,
                                              inputArray);
            
            inputArray = outputArray;

        }
        
        
        // Choice 4: Write out current image
        else if (choice == CHOICE_WRITE_CURRENT)
        {
            cout << "Enter string for PPM file name to output: ";
            cin >> outFile;
            ImgOutput outImg(inputArray,
                             outFile,
                             ARRAY_INITIIAL_HEIGHT,
                             ARRAY_INITIIAL_WIDTH);
            outImg.outputToImg();
        }
        
        
        
    
    }
    

    // Choice 5: Exit the program
    if (choice == CHOICE_EXIT)
    {
        cout << "Thank you for using this program!" << endl;
        delete[] inputArray;
    }


    return 0;
}
