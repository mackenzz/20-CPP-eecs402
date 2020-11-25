//
//  constants.h
//  eecs402 project3
//
//  Created by Zijin Zhang on 11/1/20.
//  Copyright © 2020 Zijin Zhang. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

#ifndef constants_h
#define constants_h

const string PPM_FIRST_LINE = "P3";
const string PPM_SECOND_LINE = "600 450";

const string CHOICE_ADD_RECTANGLE = "1";
const string CHOICE_ADD_PATTERN = "2";
const string CHOICE_INSERT_IMAGE = "3";
const string CHOICE_WRITE_CURRENT = "4";
const string CHOICE_EXIT = "5";

const string RED = "1";
const string GREEN = "2";
const string BLUE = "3";
const string BLACK = "4";
const string WHITE = "5";

const int RED_INT = 1;
const int GREEN_INT = 2;
const int BLUE_INT = 3;
const int BLACK_INT = 4;
const int WHITE_INT = 5;

const string METHOD_LEFT_RIGHT = "1";
const string METHOD_LEFT_DIMENSION = "2";
const string METHOD_CENTER = "3";

//const int DYNAMIC_INNITIAL = 450;
const int NUM_RGB = 3;
const string MIN_RGB = "0";
const string MAX_RGB = "255";

const int ARRAY_INITIIAL_HEIGHT = 450;
const int ARRAY_INITIIAL_WIDTH = 600;

const string PATTERN_DOMINANCE = "1";



#endif /* constants_h */

