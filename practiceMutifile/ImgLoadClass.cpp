//
//  ImgLoadClass.cpp
//  eecs402 project3
//
//  Created by Zijin Zhang on 11/1/20.
//  Copyright © 2020 Zijin Zhang. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include "ImgLoadClass.h"
#include "constants.h"
using namespace std;

string ** ImgLoad:: loadToBuffer()
{
    imageArray = new string * [ARRAY_INITIIAL_HEIGHT];
    bool isValidImg = false;
    ifstream inFile;
    string entry;
    string line1;
    string line3;
    istringstream iss;
    
    inFile.open(fileName.c_str());
    if (inFile.fail())
    {
        cout << "Unable to open the image file!" << endl;
        return 0;
    }
    else
    {
        isValidImg = true;
        inFile >> line1;
        if (line1 != PPM_FIRST_LINE)
        {
            cout << "Error found when trying to read magic number -"
            << "expected" << PPM_FIRST_LINE << "but found" << line1
            << endl;
            return 0;
        }
        inFile >> widthString;
        istringstream issWidth(widthString);
        issWidth >> width;
        inFile >> heightString;
        istringstream issHeight(heightString);
        issHeight >> height;
        inFile >> line3;
        
        for (int i = 0; i < height; ++i)
        {
            // Initialize the second level entry of imageArray
            imageArray[i] = new string[width * NUM_RGB];
            for (int j = 0; j < width * NUM_RGB; j++)
            {
                entry = "";
                inFile >> entry;
                imageArray[i][j] = entry;
            }
        }
    }
    
    inFile.close();
    return imageArray;
}
