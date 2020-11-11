//
//  RectangleClass.cpp
//  eecs402 project3
//
//  Created by Zijin Zhang on 11/1/20.
//  Copyright © 2020 Zijin Zhang. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "RectangleClass.h"
#include "constants.h"
using namespace std;
void Rectangle:: ceterToLeft(
                             int centerHeight,
                             int centerWidth,
                             int halfHeight,
                             int halfWidth
                             )
{
    upperLeft[0] = centerHeight - halfHeight;
    upperLeft[1] = centerWidth - halfWidth;
    
    lowerRight[0] = centerHeight + halfWidth;
    lowerRight[1] = centerWidth + halfWidth;
}


void Rectangle:: dimensionShift(
                                int leftHeight,
                                int leftWidth,
                                int numWidth,
                                int numHeight
                                )
{
    upperLeft[0] = leftHeight;
    upperLeft[1] = leftWidth;
    lowerRight[0] = leftHeight + numHeight;
    lowerRight[1] = leftWidth + numWidth;
}

