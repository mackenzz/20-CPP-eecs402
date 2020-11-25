//
//  RectangleClass.hpp
//  project3r
//
//  Created by Zijin Zhang on 11/24/20.
//  Copyright © 2020 Zijin Zhang. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "constants.h"
using namespace std;

#ifndef _RECTANGLECLASS_H_
#define _RECTANGLECLASS_H_

#include <stdio.h>
class RectangleClass {
private:
    string method;
    
public:
    // value to return through parameters
    int upperLeft[2];
    int lowerRight[2];
    // Constructor.
    RectangleClass();
    
    void askForMethod();
    
    // The function is used to modify return two int array upperLeft
    // and upperLeft by parameter reference, so that they can be
    // used in adding rectangles to images.
    void optionMenu();
    
};

#endif /* RECTANGLECLASS_H */
