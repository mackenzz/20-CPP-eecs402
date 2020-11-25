//
//  ImgModifyClass.cpp
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
#include "ImgModifyClass.h"
#include "ImgLoadClass.h"
#include "ImgOutputClass.h"
#include "ReadPatternClass.h"
#include "constants.h"
using namespace std;


string blackWhiteRGB(int blackOrWhite)
{
    string valueRGB;
    
    if (blackOrWhite == BLACK_INT)
    {
        valueRGB = MIN_RGB;
    }
    else if (blackOrWhite == WHITE_INT)
    {
        valueRGB = MAX_RGB;
    }
    
    return valueRGB;
}




string **ImgModify:: addRectangle(
                              int upperLeft[2],
                              int lowerRight[2],
                              int color,
                              bool isFilled,
                              string outputFile,
                              string **imageArray
                              )
{
    // Initialize sign for different color to merge different situation
    string sign;
    string valueRGB;
    if (color == RED_INT || color == GREEN_INT || color == BLUE_INT)
    {
        sign = "RGB";
    }
    else if (color == BLACK_INT || WHITE_INT)
    {
        sign = "blackOrWhite";
        if (color == BLACK_INT)
        {
            valueRGB = MIN_RGB;
        }
        else if (color == WHITE_INT)
        {
            valueRGB = MAX_RGB;
        }
    }
    
    // First scenario: the added rectagle is not filled
    if (!isFilled)
    {
        // upperLeft = [height of upper left, height of lower right]
        for (int i = upperLeft[0]; i < lowerRight[0]; i++)
        {
            // upperLeft[1] = [width of upper left, width of lower right]
            for (int j = upperLeft[1] * NUM_RGB;
                 j < (lowerRight[1] + 1) * NUM_RGB; j++)
            {
                if (sign == "RGB")
                {
                    if (j % NUM_RGB == (color - 1)){
                        // Change "red" in RGB of upper and lower border
                        imageArray[upperLeft[0]][j] = MAX_RGB;
                        imageArray[lowerRight[0]][j] = MAX_RGB;
                        // Change "red" in RGB of left and right border
                        imageArray[i][upperLeft[1] * NUM_RGB + color - 1]
                        = MAX_RGB;
                        imageArray[i][lowerRight[1] * NUM_RGB + color - 1]
                        = MAX_RGB;
                    }
                    else
                    {
                        // Initialize int as help for modified indexes
                        // we want to set the columnn not in the position of
                        // current color we are at to be zero
                        // e.g. if we are set RED, then we are setting G=B=0
                        int addIndex1 = color % NUM_RGB;
                        int addIndex2 = (color + 1) % NUM_RGB;
                        // Change "green" and "blue" in RGB to zero
                        imageArray[upperLeft[0]][j] = MIN_RGB;
                        imageArray[lowerRight[0]][j] = MIN_RGB;
                        imageArray[i][upperLeft[1] * NUM_RGB + addIndex1]
                        = MIN_RGB;
                        imageArray[i][upperLeft[1] * NUM_RGB + addIndex2]
                        = MIN_RGB;
                        imageArray[i][lowerRight[1] * NUM_RGB + addIndex1]
                        = MIN_RGB;
                        imageArray[i][lowerRight[1] * NUM_RGB + addIndex2]
                        = MIN_RGB;
                    }
                }
                
                
                else if (sign == "blackOrWhite")
                {
                    // Black: change RGB of every border to zero
                    imageArray[upperLeft[0]][j] = valueRGB;
                    imageArray[lowerRight[0]][j] = valueRGB;
                    imageArray[i][upperLeft[1] * NUM_RGB] = valueRGB;
                    imageArray[i][lowerRight[1] * NUM_RGB] = valueRGB;
                    imageArray[upperLeft[0]][j] = valueRGB;
                    imageArray[lowerRight[0]][j] = valueRGB;
                    imageArray[i][upperLeft[1] * NUM_RGB + 1] = valueRGB;
                    imageArray[i][upperLeft[1] * NUM_RGB+ 2] = valueRGB;
                    imageArray[i][lowerRight[1] * NUM_RGB + 1] = valueRGB;
                    imageArray[i][lowerRight[1] * NUM_RGB + 2] = valueRGB;
                }

            }
        }
    }
    // Second scenario: the added rectagle is filled
    else
    {
        // Traverse every entry in rectangle and change the RGB
        for (int i = upperLeft[0]; i < lowerRight[0]; i++)
        {
            for (int j = upperLeft[1] * NUM_RGB;
                 j < (lowerRight[1] + 1) * NUM_RGB; j++)
            {
                if (sign == "RGB")
                {
                    // Red in RGB: the mod of width is 0
                    if (j % NUM_RGB == color - 1)
                    {
                        imageArray[i][j] = MAX_RGB;
                        
                    }
                    // Blue and green in RGB: the mod of width is 1 or 2
                    else
                    {
                        imageArray[i][j] = MIN_RGB;
                    }
                }

                else if (sign == "blackOrWhite")
                {
                    imageArray[i][j] = valueRGB;
                }

            }
        }
    }
    
//    ImgOutput testOutput(imageArray, outputFile,
//                         inputImg.height, inputImg.width);
    // Free the memory of imageArray after using it
//    delete [] imageArray;
    return imageArray;
}


string **ImgModify:: addPattern(
                            string patternFile,
                            int startHeight,
                            int startWidth,
                            int color,
                            string outputFile,
                            string **imageArray
                            )
{
    // initialize pattern array
    string **patternArray = new string *[ARRAY_INITIIAL_HEIGHT];
    for (int i = 0; i < ARRAY_INITIIAL_HEIGHT; i++)
    {
        patternArray[i] = new string[ARRAY_INITIIAL_WIDTH * NUM_RGB];
    }
    // get pattern array
    ReadPattern testPattern(patternFile);
    patternArray = testPattern.convertArray();
    if (!patternArray)
    {
        return 0;
    }
    
    
    // modify the input image array
    string valueRGB;
    if (color == BLACK_INT)
    {
        valueRGB = MIN_RGB;
    }
    else if (color == WHITE_INT)
    {
        valueRGB = MAX_RGB;
    }
    
    for (int i = 0; i < testPattern.heightPattern; i++)
    {
        for (int j = 0; j < testPattern.widthPattern; j++)
        {
            if (patternArray[i][j] == PATTERN_DOMINANCE)
            {
                if (color == RED_INT || color == GREEN_INT
                    || color == BLUE_INT)
                {
                    int setMaxIndex = (j + startWidth) * NUM_RGB + color - 1;
                    int setMinIndex1 = (j + startWidth) * NUM_RGB
                                     + (color % NUM_RGB);
                    int setMinIndex2 = (j + startWidth) * NUM_RGB
                                     + ((color + 1) % NUM_RGB);
                    imageArray[i + startHeight][setMaxIndex] = MAX_RGB;
                    imageArray[i + startHeight][setMinIndex1] = MIN_RGB;
                    imageArray[i + startHeight][setMinIndex2] = MIN_RGB;
                }

                else if (color == BLACK_INT || color == WHITE_INT)
                {
                    imageArray[i + startHeight]
                    [(j + startWidth) * NUM_RGB] = valueRGB;
                    imageArray[i + startHeight]
                    [(j + startWidth) * NUM_RGB + 1] = valueRGB;
                    imageArray[i + startHeight]
                    [(j + startWidth) * NUM_RGB + 2] = valueRGB;
                }
            }
        }
    }
    

    return imageArray;
}





string **ImgModify:: addImg(
                        string imgToAdd,
                        int startHeight,
                        int startWidth,
                        string outputFile,
                        int colorTrans,
                        string **inputArray
                        )
{

    string **imgAddArray = new string *[ARRAY_INITIIAL_HEIGHT];
    for (int i = 0; i < ARRAY_INITIIAL_HEIGHT; i++)
    {
        imgAddArray[i] = new string[ARRAY_INITIIAL_WIDTH * NUM_RGB];
    }
    ImgLoad addImg(imgToAdd);
    imgAddArray = addImg.loadToBuffer();
    
    
    
    // Initialize the output array
    string **outputArray = new string *[ARRAY_INITIIAL_HEIGHT];
    for (int i = 0; i < ARRAY_INITIIAL_WIDTH; i++)
    {
        outputArray[i] = new string[ARRAY_INITIIAL_WIDTH * NUM_RGB];
    }
    
    // Change the RGB of output array to be same as input
    for (int i = 0; i < ARRAY_INITIIAL_HEIGHT; i++)
    {
        for (int j = 0; j < ARRAY_INITIIAL_WIDTH * NUM_RGB; j++)
        {
            outputArray[i][j] = inputArray[i][j];
        }
    }
    
    

    
    
    // Add image to the output array
    for (int i = 0; i < addImg.height; i++)
    {
        for (int j = 0; j < addImg.width * NUM_RGB; j++)
        {
            // Avoid changing the original image by transparency color
            if (colorTrans == WHITE_INT)
            {
                if (imgAddArray[i][j] != MAX_RGB)
                {
                    outputArray[i + startHeight][j + startWidth * NUM_RGB]
                    = imgAddArray[i][j];
                }
            }
            
            else if (colorTrans == BLACK_INT)
            {
                if (imgAddArray[i][j] != MIN_RGB)
                {
                    outputArray[i + startHeight][j + startWidth * NUM_RGB]
                    = imgAddArray[i][j];
                }
            }
            
            else if (colorTrans == RED_INT)
            {
                if (j % NUM_RGB == 0)
                {
                    // Only the RGB of a pixel is [255, 0, 0], it is red.
                    // Avoid the output to be changed these pixels
                    if (imgAddArray[i][j] != MAX_RGB ||
                        imgAddArray[i][j + 1] != MIN_RGB ||
                        imgAddArray[i][j + 2] != MIN_RGB)
                    {
                        outputArray[i + startHeight]
                        [j + startWidth * NUM_RGB] = imgAddArray[i][j];
                    }
                }
            }
            else if (colorTrans == GREEN_INT)
            {
                if (j % NUM_RGB == 1)
                {
                    // Only the RGB of a pixel is [0, 255, 0], it is green.
                    // Avoid the output to be changed these pixels
                    if (imgAddArray[i][j] != MAX_RGB ||
                        imgAddArray[i][j - 1] != MIN_RGB ||
                        imgAddArray[i][j + 1] != MIN_RGB)
                    {
                        outputArray[i + startHeight]
                        [j + startWidth * NUM_RGB] = imgAddArray[i][j];
                    }
                }
            }
            else if (colorTrans == BLUE_INT)
            {
                if (j % NUM_RGB == 2)
                {
                    // Only the RGB of a pixel is [0, 0, 255], it is black.
                    // Avoid the output to be changed these pixels
                    if (imgAddArray[i][j] != MAX_RGB ||
                        imgAddArray[i][j - 1] != MIN_RGB ||
                        imgAddArray[i][j - 2] != MIN_RGB)
                    {
                        outputArray[i + startHeight]
                        [j + startWidth * NUM_RGB] = imgAddArray[i][j];
                    }
                }
            }
                
        }
    }
    
    delete [] inputArray;
    delete [] imgAddArray;

    
    return outputArray;
}

