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
#include <cstring>
#include "constants.h"
using namespace std;

#ifndef _IMGMODIFYCLASS_H_
#define _IMGMODIFYCLASS_H_

#include <stdio.h>

// The class is used to modify the input image
class ImgModify {
private:
    string inputFile;
    int width;
    int height;
    string blackWhiteRGB(int blackOrWhite);
    
public:
    // Constructor
    ImgModify(
              string inputFile
              )
    {
        this->inputFile = inputFile;
    };
    
    // The function is to annotate the input image with a rectangle
    string **addRectangle(
                      int upperLeft[2],
                      int lowerRight[2],
                      int color,
                      bool isFilled,
                      string outputFile,
                      string **imageArray
                      );
    
    // The function is to annotate the image with a pattern, which is a
    // rectangle containing a description of a shape
    string **addPattern(
                    string patternFile,
                    int startHeight,
                    int startWidth,
                    int color,
                    string outputFile,
                    string **imageArray
                    );
    
    // The function is to insert another PPM image at a specified location
    string **addImg(
                string imgToAdd,
                int startHeight,
                int startWidth,
                string outputFile,
                int colorTrans,
                string **inputArray
                );
    
    string **borderChange(
                        string **imageArray,
                        int color,
                        int upperLeft[2],
                        int lowerRight[2]
                        );
    
};

#endif /* ImgModifyClass_h */
