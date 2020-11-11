//
//  ImgModifyClass.hpp
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

#ifndef ImgModifyClass_h
#define ImgModifyClass_h

#include <stdio.h>

// The class is used to modify the input image
class ImgModify {
private:
    string inputFile;
    int width;
    int height;
    
public:
    // Constructor
    ImgModify(
              string inputFile
              )
    {
        this->inputFile = inputFile;
    };
    
    // The function is to annotate the input image with a rectangle
    bool addRectangle(
                      int upperLeft[2],
                      int lowerRight[2],
                      int color,
                      bool isFilled,
                      string outputFile
                      );
    
    // The function is to annotate the image with a pattern, which is a
    // rectangle containing a description of a shape
    bool addPattern(
                    string patternFile,
                    int startHeight,
                    int startWidth,
                    int color,
                    string outputFile
                    );
    
    // The function is to insert another PPM image at a specified location
    bool addImg(
                string imgToAdd,
                int startHeight,
                int startWidth,
                string outputFile,
                string colorTrans
                );
};

#endif /* ImgModifyClass_h */
