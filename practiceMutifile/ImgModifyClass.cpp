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

bool ImgModify:: addRectangle(
                              int upperLeft[2],
                              int lowerRight[2],
                              int color,
                              bool isFilled,
                              string outputFile
                              )
{
    // initialize and get image array
    string **imageArray = new string *[ARRAY_INITIIAL_HEIGHT];
    for (int i = 0; i < ARRAY_INITIIAL_HEIGHT; i++)
    {
        imageArray[i] = new string[ARRAY_INITIIAL_WIDTH * NUM_RGB];
    }
    ImgLoad inputImg(inputFile);
    imageArray = inputImg.loadToBuffer();
    
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
                if (color == RED_INT)
                {
                    if (j % NUM_RGB == 0){
                        // Change "red" in RGB of upper and lower border
                        imageArray[upperLeft[0]][j] = MAX_RGB;
                        imageArray[lowerRight[0]][j] = MAX_RGB;
                        // Change "red" in RGB of left and right border
                        imageArray[i][upperLeft[1] * NUM_RGB] = MAX_RGB;
                        imageArray[i][lowerRight[1] * NUM_RGB] = MAX_RGB;
                    }
                    else
                    {
                        // Change "green" and "blue" in RGB to zero
                        imageArray[upperLeft[0]][j] = MIN_RGB;
                        imageArray[lowerRight[0]][j] = MIN_RGB;
                        imageArray[i][upperLeft[1] * NUM_RGB + 1] = MIN_RGB;
                        imageArray[i][upperLeft[1] * NUM_RGB + 2] = MIN_RGB;
                        imageArray[i][lowerRight[1] * NUM_RGB + 1] = MIN_RGB;
                        imageArray[i][lowerRight[1] * NUM_RGB + 2] = MIN_RGB;
                    }
                }
                else if (color == GREEN_INT)
                {
                    if (j % NUM_RGB == 1){
                        // Change "green" in RGB of upper and lower border
                        imageArray[upperLeft[0]][j] = MAX_RGB;
                        imageArray[lowerRight[0]][j] = MAX_RGB;
                        // Change "green" in RGB of left and right border
                        imageArray[i][upperLeft[1] * NUM_RGB + 1] = MAX_RGB;
                        imageArray[i][lowerRight[1] * NUM_RGB + 1] = MAX_RGB;
                    }
                    else
                    {
                        // Change "red" and "blue" in RGB to zero
                        imageArray[upperLeft[0]][j] = MIN_RGB;
                        imageArray[lowerRight[0]][j] = MIN_RGB;
                        imageArray[i][upperLeft[1] * NUM_RGB] = MIN_RGB;
                        imageArray[i][upperLeft[1] * NUM_RGB + 2] = MIN_RGB;
                        imageArray[i][lowerRight[1] * NUM_RGB] = MIN_RGB;
                        imageArray[i][lowerRight[1] * NUM_RGB + 2] = MIN_RGB;
                    }
                }
                else if (color == BLUE_INT)
                {
                    if (j % NUM_RGB == 2){
                        // Change "blue" in RGB of upper and lower border
                        imageArray[upperLeft[0]][j] = MAX_RGB;
                        imageArray[lowerRight[0]][j] = MAX_RGB;
                        // Change "blue" in RGB of left and right border
                        imageArray[i][upperLeft[1] * NUM_RGB + 2] = MAX_RGB;
                        imageArray[i][lowerRight[1] * NUM_RGB + 2] = MAX_RGB;
                    }
                    else
                    {
                        // Change "green" and "red" in RGB to zero
                        imageArray[upperLeft[0]][j] = MIN_RGB;
                        imageArray[lowerRight[0]][j] = MIN_RGB;
                        imageArray[i][upperLeft[1] * NUM_RGB + 1] = MIN_RGB;
                        imageArray[i][upperLeft[1] * NUM_RGB] = MIN_RGB;
                        imageArray[i][lowerRight[1] * NUM_RGB + 1] = MIN_RGB;
                        imageArray[i][lowerRight[1] * NUM_RGB] = MIN_RGB;
                    }
                }
                else if (color == BLACK_INT)
                {
                    // Black: change RGB of every border to zero
                    imageArray[upperLeft[0]][j] = MIN_RGB;
                    imageArray[lowerRight[0]][j] = MIN_RGB;
                    imageArray[i][upperLeft[1] * NUM_RGB] = MIN_RGB;
                    imageArray[i][lowerRight[1] * NUM_RGB] = MIN_RGB;
                    imageArray[upperLeft[0]][j] = MIN_RGB;
                    imageArray[lowerRight[0]][j] = MIN_RGB;
                    imageArray[i][upperLeft[1] * NUM_RGB + 1] = MIN_RGB;
                    imageArray[i][upperLeft[1] * NUM_RGB+ 2] = MIN_RGB;
                    imageArray[i][lowerRight[1] * NUM_RGB + 1] = MIN_RGB;
                    imageArray[i][lowerRight[1] * NUM_RGB + 2] = MIN_RGB;
                }
                else
                {
                    // White: change RGB of every border to 255
                    imageArray[upperLeft[0]][j] = MAX_RGB;
                    imageArray[lowerRight[0]][j] = MAX_RGB;
                    imageArray[i][upperLeft[1] * NUM_RGB] = MAX_RGB;
                    imageArray[i][lowerRight[1] * NUM_RGB] = MAX_RGB;
                    imageArray[upperLeft[0]][j] = MAX_RGB;
                    imageArray[lowerRight[0]][j] = MAX_RGB;
                    imageArray[i][upperLeft[1] * NUM_RGB + 1] = MAX_RGB;
                    imageArray[i][upperLeft[1] * NUM_RGB + 2] = MAX_RGB;
                    imageArray[i][lowerRight[1] * NUM_RGB + 1] = MAX_RGB;
                    imageArray[i][lowerRight[1] * NUM_RGB + 2] = MAX_RGB;
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
                if (color == RED_INT)
                {
                    // Red in RGB: the mod of width is 0
                    if (j % NUM_RGB == 0)
                    {
                        imageArray[i][j] = MAX_RGB;
                        
                    }
                    // Blue and green in RGB: the mod of width is 1 or 2
                    else
                    {
                        imageArray[i][j] = MIN_RGB;
                    }
                }
                else if (color == GREEN_INT)
                {
                    if (j % NUM_RGB == 1)
                    {
                        imageArray[i][j] = MAX_RGB;
                    }
                    else
                    {
                        imageArray[i][j] = MIN_RGB;
                    }
                }
                else if (color == BLUE_INT)
                {
                    if (j % NUM_RGB == 2)
                    {
                        imageArray[i][j] = MAX_RGB;
                    }
                    else
                    {
                        imageArray[i][j] = MIN_RGB;
                    }
                }
                else if (color == BLACK_INT)
                {
                    imageArray[i][j] = MIN_RGB;
                }
                else
                {
                    imageArray[i][j] = MAX_RGB;
                }
            }
        }
    }
    
    ImgOutput testOutput(imageArray, outputFile,
                         inputImg.height, inputImg.width);
    bool isValidImg = testOutput.outputToImg();
    // Free the memory of imageArray after using it
    delete [] imageArray;
    return isValidImg;
}


bool ImgModify:: addPattern(
                            string patternFile,
                            int startHeight,
                            int startWidth,
                            int color,
                            string outputFile
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
    
    
    // initialize and get input array
    string **inputArray = new string *[ARRAY_INITIIAL_HEIGHT];
    for (int i = 0; i < ARRAY_INITIIAL_HEIGHT; i++)
    {
        inputArray[i] = new string[ARRAY_INITIIAL_WIDTH * NUM_RGB];
    }
    ImgLoad inputImg(inputFile);
    inputArray = inputImg.loadToBuffer();
    
    
    // modify the input image array
    for (int i = 0; i < testPattern.heightPattern; i++)
    {
        for (int j = 0; j < testPattern.widthPattern; j++)
        {
            if (patternArray[i][j] == PATTERN_DOMINANCE)
            {
                if (color == RED_INT)
                {
                    inputArray[i + startHeight]
                    [(j+startWidth) * NUM_RGB] = MAX_RGB;
                    inputArray[i + startHeight]
                    [(j + startWidth) * NUM_RGB + 1] = MIN_RGB;
                    inputArray[i + startHeight]
                    [(j + startWidth) * NUM_RGB + 2] = MIN_RGB;
                }
                else if (color == GREEN_INT)
                {
                    inputArray[i + startHeight]
                    [(j + startWidth) * NUM_RGB] = MIN_RGB;
                    inputArray[i + startHeight]
                    [(j + startWidth) * NUM_RGB + 1] = MAX_RGB;
                    inputArray[i + startHeight]
                    [(j + startWidth) * NUM_RGB + 2] = MIN_RGB;
                }
                else if (color == BLUE_INT)
                {
                    inputArray[i + startHeight]
                    [(j + startWidth) * NUM_RGB] = MIN_RGB;
                    inputArray[i + startHeight]
                    [(j + startWidth) * NUM_RGB + 1] = MIN_RGB;
                    inputArray[i + startHeight]
                    [(j + startWidth) * NUM_RGB + 2] = MAX_RGB;
                }
                else if (color == BLACK_INT)
                {
                    inputArray[i + startHeight]
                    [(j + startWidth) * NUM_RGB] = MIN_RGB;
                    inputArray[i + startHeight]
                    [(j + startWidth) * NUM_RGB + 1] = MIN_RGB;
                    inputArray[i + startHeight]
                    [(j + startWidth) * NUM_RGB + 2] = MIN_RGB;
                }
                else if (color == WHITE_INT)
                {
                    inputArray[i + startHeight]
                    [(j + startWidth) * NUM_RGB] = MAX_RGB;
                    inputArray[i + startHeight]
                    [(j + startWidth) * NUM_RGB + 1] = MAX_RGB;
                    inputArray[i + startHeight]
                    [(j + startWidth) * NUM_RGB + 2] = MAX_RGB;
                }
            }
        }
    }
    
    ImgOutput testOutput(inputArray, outputFile,
                         inputImg.height, inputImg.width);
    bool isValidImg = testOutput.outputToImg();
    delete [] patternArray;
//    delete [] inputArray;
    return isValidImg;
}





bool ImgModify:: addImg(
                        string imgToAdd,
                        int startHeight,
                        int startWidth,
                        string outputFile,
                        string colorTrans
                        )
{
    // initialize and get input array
    string **inputArray = new string *[ARRAY_INITIIAL_HEIGHT];
    for (int i = 0; i < ARRAY_INITIIAL_HEIGHT; i++)
    {
        inputArray[i] = new string[ARRAY_INITIIAL_WIDTH * NUM_RGB];
    }
    ImgLoad inputImg(inputFile);
    inputArray = inputImg.loadToBuffer();
    
    // initialize array of the image to be added
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
            if (colorTrans == WHITE)
            {
                if (imgAddArray[i][j] != MAX_RGB)
                {
                    outputArray[i + startHeight][j + startWidth * NUM_RGB]
                    = imgAddArray[i][j];
                }
            }
            else if (colorTrans == BLACK)
            {
                if (imgAddArray[i][j] != MIN_RGB)
                {
                    outputArray[i + startHeight][j + startWidth * NUM_RGB]
                    = imgAddArray[i][j];
                }
            }
            else if (colorTrans == RED)
            {
                if (j % NUM_RGB == 0)
                {
                    // Only the RGB of a pixel is [255, 0, 0], it is red.
                    // Avoid the output to be changed these pixels
                    if (imgAddArray[i][j] != MAX_RGB ||
                        imgAddArray[i][j + 1] != MIN_RGB ||
                        imgAddArray[i][j + 1] != MIN_RGB)
                    {
                        outputArray[i + startHeight]
                        [j + startWidth * NUM_RGB] = imgAddArray[i][j];
                    }
                }
            }
            else if (colorTrans == GREEN)
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
            else if (colorTrans == BLUE)
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
    
    ImgOutput testOutput(outputArray, outputFile,
                         inputImg.height, inputImg.width);
    bool isValidImg = testOutput.outputToImg();
    
    // Free the memory of dynamic array
    delete [] inputArray;
    delete [] imgAddArray;
    delete [] outputArray;
    
    return isValidImg;
}

