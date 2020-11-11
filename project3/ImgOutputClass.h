//
//  ImgOutputClass.h
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

#ifndef ImgOutputClass_h
#define ImgOutputClass_h

// The class is used to output image with image array
class ImgOutput {
private:
    string **imageArray;
    string outputFile;
    int sizeHeight;
    int sizeWidth;

public:
    // Constructor
    ImgOutput(
              string **imageArray,
              string outputFile,
              int sizeHeight,
              int sizeWidth
              )
    {
        this->imageArray = imageArray;
        this->outputFile = outputFile;
        this->sizeHeight = sizeHeight;
        this->sizeWidth = sizeWidth;
    };
    
    // The funnction output image with image array
    bool outputToImg();

};



#endif /* ImgOutputClass_h */
