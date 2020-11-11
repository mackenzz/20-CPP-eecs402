//
//  ReadPatternClass.cpp
//  eecs402 project3
//
//  Created by Zijin Zhang on 11/1/20.
//  Copyright © 2020 Zijin Zhang. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "ReadPatternClass.h"
#include "constants.h"
using namespace std;

string ** ReadPattern:: convertArray()
{
    patternArray = new string *[ARRAY_INITIIAL_HEIGHT];
    string patternHeightString;
    string patternWidthString;
    
    ifstream inPatternFile;
    inPatternFile.open(patternFile.c_str());
    
    if (inPatternFile.fail())
    {
        cout << "Unable to open the pattern file!" << endl;
        return 0;
    }
    
    inPatternFile >> patternWidthString;
    inPatternFile >> patternHeightString;
    
    istringstream issWidth(patternWidthString);
    issWidth >> widthPattern;
    istringstream issHeight(patternHeightString);
    issHeight >> heightPattern;
    
    string word;
    for (int i = 0; i < heightPattern; ++i)
    {
        patternArray[i] = new string[widthPattern];
        for (int j = 0; j < widthPattern; j++)
        {
            word = "";
            inPatternFile >> word;
            patternArray[i][j] = word;
        }
        
    }
    
    inPatternFile.close();
    return patternArray;
};
