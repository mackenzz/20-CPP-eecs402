//
//  ImgLoadClass.h
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

#ifndef _IMGLOADCLASS_H_
#define _IMGLOADCLASS_H_
// The class is used to load innput imame.
class ImgLoad {
private:
    string fileName;
    string widthString;
    string heightString;
    
    
public:
    int width;
    int height;
    string **imageArray;
    
    // Constructor
    ImgLoad(
            string fileName
            )
    {
        this->fileName = fileName;
    };
    
    // The function is used to load image to a 2D array. The length of
    // the array is the height of image while length of array[0] is
    // the (width of image * 3), where 3 represents Red, Green, Blue.
    string **loadToBuffer();
};


#endif /* ImgLoadClass_h */
