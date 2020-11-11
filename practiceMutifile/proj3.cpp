//
//  mainProj3.cpp
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
#include "ImgModifyClass.h"
#include "constants.h"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    string inputFile;
    string patternFile;
    string patternPosition;
    
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
    string isFilledStr;
    bool isFilled = false;
    string method;
    int upperLeft[2];
    int lowerRight[2];
    int numWidth = 0;
    int numHeight = 0;
    string centerRow;
    string centerCol;
    string halfRow;
    string halfCol;
    string upperLeft_0;
    string upperLeft_1;
    string lowerRight_0;
    string lowerRight_1;
    string colorTrans;
    int tmp1 = 0;
    int tmp2 = 0;
    int tmp3 = 0;
    int tmp4 = 0;

 
    
    string outFile = "new1.ppm";
    // Initialize output file name
//    int numFiles = 1;
//    string outFile = "new" + to_string(numFiles) + ".ppm";
    
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
    
    
    
    while (choice != CHOICE_EXIT)
    {
        
        cout << "1.  Annotate image with rectangle" << endl
        << "2.  Annotate image with pattern from file" << endl
        << "3.  Insert another image" << endl
        << "4.  Write out current image" << endl
        << "5.  Exit the program" << endl
        << "Enter int for main menu choice: ";
        cin >> choice;
        
        
        if (choice == CHOICE_EXIT)
        {
            // Choice 5: Exit the program
            cout << "Thank you for using this program!" << endl;
            return 0;
        }
        else if (choice == CHOICE_ADD_PATTERN)
        {
            // Choice 2: Annotate image with pattern from file
            cout << "Enter string for file name containing pattern: ";
            cin >> patternFile;
            
            cout << "Enter upper left corner of pattern row: ";
//            patternHeight = stoi(lineStr);
            cin >> lineStr;
            iss.str(lineStr);
            iss >> patternHeight;
            iss.clear();

            
            cout << "Enter upper left corner of pattern column: ";
            cin >> lineStr;
            iss.str(lineStr);
            iss >> patternWidth;
            iss.clear();
            
            
            cout << "1.  Red" << endl << "2.  Green" << endl << "3.  Blue"
            << endl << "4.  Black" << endl << "5.  White" << endl;
            
            cout << "Enter int for pattern color: ";
            cin >> colorStr;
            iss.str(colorStr);
            iss >> colorInt;
            iss.clear();
            
            ImgModify ImgPattern(inputFile);
            ImgPattern.addPattern(patternFile, patternHeight,
                                  patternWidth, colorInt, outFile);

            
            
        }
        else if (choice == CHOICE_INSERT_IMAGE)
        {
            // Choice 3: Insert another image
            cout << "Enter string for file name of PPM image to insert: ";
            cin >> imgToAdd;
            
            cout << "Enter upper left corner to insert image row: ";
            cin >> lineStr;
//            insertHeight = stoi(lineStr);
            iss.str(lineStr);
            iss >> insertHeight;
            iss.clear();
            
            cout << "Enter upper left corner to insert image column: ";
            cin >> lineStr;
            iss.str(lineStr);
            iss >> insertWidth;
            iss.clear();
            
            cout << "1.  Red" << endl << "2.  Green" << endl << "3.  Blue"
            << endl << "4.  Black" << endl << "5.  White" << endl;
            cout << "Enter int for transparecy color: ";
            cin >> colorTrans;
            
            
            ImgModify ImgInsert(inputFile);
            ImgInsert.addImg(imgToAdd, insertHeight,
                             insertWidth, outFile, colorTrans);
            
            
            
        } else if (choice == CHOICE_ADD_RECTANGLE)
        {
            // Choice 1: Annotate image with rectangle
            cout << "1.  Specify upper left and lower right"
            <<"corners of rectangle" << endl;
            cout << "2.  Specify upper left corner and"
            "dimensions of rectangle" << endl;
            cout << "3.  Specify extent from center of rectangle"
            << endl;
            
            cout << "Enter int for rectangle specification method: ";
            cin >> method;
            
            if (method == METHOD_LEFT_RIGHT)
            {
                cout << "Enter upper left corner row: ";
                cin >> upperLeft_0;
                iss.str(upperLeft_0);
                iss >> upperLeft[0];
                iss.clear();
                cout << "Enter upper left corner column: ";
                cin >> upperLeft_1;
                iss.str(upperLeft_1);
                iss >> upperLeft[1];
                iss.clear();
                cout << "Enter lower right corner row: ";
                cin >> lowerRight_0;
                iss.str(lowerRight_0);
                iss >> lowerRight[0];
                iss.clear();
                cout << "Enter lower right corner column : ";
                cin >> lowerRight_1;
                iss.str(lowerRight_1);
                iss >> lowerRight[1];
                iss.clear();
            }
            else if (method == METHOD_LEFT_DIMENSION)
            {
                cout << "Enter upper left corner row: ";
                cin >> upperLeft_0;
                iss.str(upperLeft_0);
                iss >> upperLeft[0];
                iss.clear();
                cout << "Enter upper left corner column: ";
                cin >> upperLeft_1;
                iss.str(upperLeft_1);
                iss >> upperLeft[1];
                iss.clear();
                cout << "Enter int for number of rows: ";
                cin >> upperLeft_0;
                iss.str(upperLeft_0);
                iss >> numHeight;
                iss.clear();
                cout << "Enter int for number of columns: ";
                cin >> upperLeft_1;
                iss.str(upperLeft_1);
                iss >> numWidth;
                iss.clear();
                
                lowerRight[0] = upperLeft[0] + numHeight;
                lowerRight[1] = upperLeft[1] + numWidth;
            
            }
            else if (method == METHOD_CENTER)
            {
                cout << "Enter rectangle center row: ";
                cin >> centerRow;
                iss.str(centerRow);
                iss >> tmp1;
                iss.clear();
                cout << "Enter rectangle center column: ";
                cin >> centerCol;
                iss.str(centerCol);
                iss >> tmp2;
                iss.clear();
                cout << "Enter int for half number of rows: ";
                cin >> halfRow;
                iss.str(halfRow);
                iss >> tmp3;
                iss.clear();
                cout << "Enter int for half number of columns: ";
                cin >> halfCol;
                iss.str(halfCol);
                iss >> tmp4;
                iss.clear();
                
                upperLeft[0] = tmp1 - tmp3;
                lowerRight[0] = tmp1 + tmp3;
                upperLeft[1] = tmp2 - tmp4;
                lowerRight[1] = tmp2 + tmp4;
                
            }
            
            
            
            cout << "1.  Red" << endl << "2.  Green" << endl << "3.  Blue"
            << endl << "4.  Black" << endl << "5.  White" << endl;
            
            cout << "Enter int for rectangle color: ";
            cin >> colorStr;
            iss.str(colorStr);
            iss >> colorInt;
            iss.clear();
            
            cout << "1.  No" << endl << "2.  Yes" << endl;
            cout << "Enter int for rectangle fill option: ";
            cin >> isFilledStr;
            if (isFilledStr == "2")
            {
                isFilled = true;
            }
            else if (isFilledStr == "1")
            {
                isFilled = false;
            }
            
            
            ImgModify ImgRec(inputFile);
            ImgRec.addRectangle(upperLeft, lowerRight, colorInt,
                                isFilled, outFile);

            
        }
        else if (choice == CHOICE_WRITE_CURRENT)
        {
            // Choice 4: Write out current image
//            numFiles += 1;
//            outFile = "new" + numFiles + ".ppm";
            cout << "Enter string for PPM file name to output: ";
            cin >> inputFile;
        }
        else
        {
            // Error checking for wrong input CHOICE
            while (choice != CHOICE_ADD_PATTERN &&
                   choice != CHOICE_INSERT_IMAGE &&
                   choice != CHOICE_ADD_RECTANGLE &&
                   choice != CHOICE_WRITE_CURRENT &&
                   choice != CHOICE_EXIT)
            {
                cout << "Please enter again your choice: ";
                cin >> choice;
            }
        }

    }
    
    // In case the while loop ends with a choice of 5
    if (choice == CHOICE_EXIT)
    {
        // Choice 5: Exit the program
        cout << "Thank you for using this program!" << endl;
    }

    

    
    return 0;
}
