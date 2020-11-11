//
//  ReadPatternClass.hpp
//  eecs402 project3
//
//  Created by Zijin Zhang on 11/1/20.
//  Copyright © 2020 Zijin Zhang. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "constants.h"
using namespace std;

#ifndef ReadPatternClass_h
#define ReadPatternClass_h

#include <stdio.h>
class ReadPattern {
private:
    string patternFile;
public:
    int heightPattern = 0;
    int widthPattern = 0;
    string **patternArray = new string *[ARRAY_INITIIAL_HEIGHT];
    
    // Constructor
    ReadPattern(
                string patternFile
                )
    {
        this->patternFile = patternFile;
    };
    
    // The function reads the pattern file and returns a 2D array
    string **convertArray();
    
    
};

#endif /* ReadPatternClass_h */
