//
//  RectangleClass.hpp
//  eecs402 project3
//
//  Created by Zijin Zhang on 11/10/20.
//  Copyright © 2020 Zijin Zhang. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "constants.h"
using namespace std;

#ifndef RectangleClass_h
#define RectangleClass_h

#include <stdio.h>

// The class is used to convert a ractangle, which will be
// refined and used in the future
class Rectangle {
public:
    int upperLeft[2];
    int lowerRight[2];
    
    // Constructor
    Rectangle();
    
    // The function is used to convert the method of speciying
    // extent from center of rectangle to left upper and right lower
    void ceterToLeft(
                     int centerHeight,
                     int centerWidth,
                     int halfHeight,
                     int halfWidth
                     );
    
    // The function is used to convert the method of specifying upper left
    // corner and dimensions of rectangle to left upper and right lower
    void dimensionShift(
                        int leftHeight,
                        int leftWidth,
                        int numWidth,
                        int numHeight
                        );
    
};

#endif /* RectangleClass_h */
