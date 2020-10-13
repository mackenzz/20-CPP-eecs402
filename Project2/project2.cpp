//
//  EECS402 project2:
//  Purpose: The object-oriented project includes three classes,
//  which represent and utilize colors, pixel location and images.
//  It uses a bunch of colors arranged in a rectangle to represent an image.
//
//
//  Created by Zijin Zhang (UMID: 40703833) on 10/3/20.
//  Copyright © 2020 Zijin Zhang. All rights reserved.
//


#include <iostream>
using namespace std;
const int MINIMUM_RGB = 0;
const int MAXIMUM_RGB = 1000;
const int IMAGE_NUM_ROWS = 10;
const int IMAGE_NUM_COLS = 18;
const int INITIAL_ROWS = -99999;
const int INITIAL_COLS = -99999;
const int MINIMUM_NUM_ROWS = 0;
const int MINIMUM_NUM_COLS = 0;


// ************************************************************
// ******************* ColorClass definitions *****************
// The class represents colors with the combination of some amount
// of red, green, and blue (RGB). The class provids functions for users
// to set colors and performs some operations like adding, substracting.
class ColorClass {
private:
    int inRed;
    int inGreen;
    int inBlue;
    
    // The function tests whether the input one color needs clipping.
    bool needClip(
                  int &inColor
                  );
    
    // The function tests whether any of input component colors need clipping.
    bool needClip(
                  int &inRed,
                  int &inGreen,
                  int &inBlue
                  );

public:
    // Constructor: with no input, the attributes will be set as default.
    ColorClass()
    {
        inRed = MAXIMUM_RGB;
        inGreen = MAXIMUM_RGB;
        inBlue = MAXIMUM_RGB;
    };
    
    // Constructor: with input values, the attributes will be set as provided.
    // The input values will be clipped if out of valid range.
    ColorClass(
               int inRed,
               int inGreen,
               int inBlue
               )
    {
        needClip(inRed, inGreen, inBlue);
        this->inRed = inRed;
        this->inGreen = inGreen;
        this->inBlue = inBlue;
    };

    // The following functions set the color’s component color values
    // to the appropriate values to form the color indicated.
    void setToBlack();
    void setToRed();
    void setToGreen();
    void setToBlue();
    void setToWhite();
    
    // The function sets the color object's RGB values to the provided values.
    bool setTo(
               int inRed,
               int inGreen,
               int inBlue
               );

    // The function sets the color object's RGB values to the same as
    // those in the "inColor" input parameter, returns true if input
    // values need to be clipped.
    bool setTo(
               ColorClass &inColor
               );
    
    
    // The function adds the corresponding value from the input parameter
    // to each color’s component color value, returns true if the
    // component values need to be clipped after adding input values.
    bool addColor(
                  ColorClass &rhs
                  );
    
    // The function subtracts the corresponding value of the input parameter
    // from each color’s component color value, returns true if the
    // component values need to be clipped after subtracting input values.
    bool subtractColor(
                       ColorClass &rhs
                       );
    
    // This function performs a brightness adjustment which multiplies
    // each RGB value by the input adjustment factor, returns true if the
    // component values need to be clipped after adjusting.
    bool adjustBrightness(
                          double adjFactor
                          );
    
    // The function prints component RGB color values in formatted way.
    void printComponentValues();
};



// ************************************************************
// ***************** RowColumnClass definitions ***************
// The class refers to a specific pixel within the collection of pixels
// that make up an image. It applies row index and a column index to
// identify a specific pixel via its location.
class RowColumnClass {
private:
    int inRow;
    int inCol;

public:
    // Constructor: with no input, the attributes will be set as default.
    RowColumnClass()
    {
        inRow = INITIAL_ROWS;
        inCol = INITIAL_COLS;
    };
    
    // Constructor: with input values, the attributes will be set as provided.
    RowColumnClass(
                   int inRow,
                   int inCol
                   )
    {
        this->inRow = inRow;
        this->inCol = inCol;
    };
    
    // The function set row and column indexes to provided values.
    void setRowCol(
                   int inRow,
                   int inCol
                   );
    
    // The function set row index to provided values.
    void setRow(
                int inRow
                );
    
    // The function set column index to provided values.
    void setCol(
                int inCol
                );
    
    // The function returns row index of the pixel.
    int getRow();
    
    // The function returns column index of the pixel.
    int getCol();
    
    // The function adds the row and column index values in the input
    // parameter to current indexes.
    void addRowColTo(
                     RowColumnClass &inRowCol
                     );
    
    // The function prints component row and column indexes in formatted way.
    void printRowCol();
};



// ************************************************************
// **************** ColorImageClass definitions ***************
// The class represents a small image, using a 2D array to represent it,
// with each entry storing the RGB values of the color.
class ColorImageClass {
private:
    ColorClass colorArray[IMAGE_NUM_ROWS][IMAGE_NUM_COLS];
    
    // The function test whether input is a valid location in the image.
    bool isValidLocation(
                         RowColumnClass &inRowCol
                         );
    
public:
    // Constructor: no input, set the color’s initial RGB values to the
    // color full white (R: 0, G: 0, B: 0).
    ColorImageClass()
    {
        for (int i = 0; i < IMAGE_NUM_ROWS; i++)
        {
            for (int j = 0; j < IMAGE_NUM_COLS; j++)
            {
                colorArray[i][j] = ColorClass(0, 0, 0);
            }
        }
    };
    
    // The function initializes all image pixel color to input values
    void initializeTo(
                      ColorClass &inColor
                      );
    
    // The function add input image RGB value to current image,
    // returns true if clippinng is needed after adding.
    bool addImageTo(
                    ColorImageClass &rhsImg
                    );
    
    // The function adds the RGB values of the input images together
    // and assign the values to corresponding pixel of current image.
    bool addImages(
                   int numImgsToAdd,
                   ColorImageClass imagesToAdd []
                   );
    
    // The function set RGB values at specified pixel to provided values,
    // returns true if the input row and column indexes are valid.
    bool setColorAtLocation(
                            RowColumnClass &inRowCol,
                            ColorClass &inColor
                            );
    
    // The function get the component color values at provided location,
    // returns true if the input row and column indexes are valid.
    bool getColorAtLocation(
                            RowColumnClass &inRowCol,
                            ColorClass &outColor
                            );
    
    // The function prints the RGB values at each pixel in formatted way.
    void printImage();
};




// ************************************************************
// *************** main function starts from here *************
#ifdef ANDREW_TEST
#include "andrewTest.h"
#else
int main(int argc, const char * argv[]) {
    // Sample main
    ColorClass testColor;
    RowColumnClass testRowCol;
    RowColumnClass testRowColOther(111, 222);
    ColorImageClass testImage;
    ColorImageClass testImages[3];
    
    //Test some basic ColorClass operations
    cout << "Initial: ";
    testColor.printComponentValues();
    cout << endl;
    
    testColor.setToBlack();
    cout << "Black: ";
    testColor.printComponentValues();
    cout << endl;
    
    testColor.setToGreen();
    cout << "Green: ";
    testColor.printComponentValues();
    cout << endl;
    
    testColor.adjustBrightness(0.5);
    cout << "Dimmer Green: ";
    testColor.printComponentValues();
    cout << endl;
    
    //Test some basic RowColumnClass operations
    cout << "Want defaults: ";
    testRowCol.printRowCol();
    cout << endl;
    
    testRowCol.setRowCol(2, 8);
    cout << "Want 2,8: ";
    testRowCol.printRowCol();
    cout << endl;
    
    cout << "Want 111, 222: ";
    testRowColOther.printRowCol();
    cout << endl;
    
    testRowColOther.setRowCol(4, 2);
    testRowCol.addRowColTo(testRowColOther);
    cout << "Want 6,10: ";
    testRowCol.printRowCol();
    cout << endl;
    
    //Test some basic ColorImageClass operations
    testColor.setToRed();
    testImage.initializeTo(testColor);
    
    testRowCol.setRowCol(555, 5);
    cout << "Want: Color at [555,5]: Invalid Index!" << endl;
    cout << "Color at ";
    testRowCol.printRowCol();
    cout << ": ";
    if (testImage.getColorAtLocation(testRowCol, testColor))
    {
        testColor.printComponentValues();
    }
    else
    {
        cout << "Invalid Index!";
    }
    cout << endl;
    
    testRowCol.setRow(4);
    cout << "Want: Color at [4,5]: R: 1000 G: 0 B: 0" << endl;
    cout << "Color at ";
    testRowCol.printRowCol();
    cout << ": ";
    if (testImage.getColorAtLocation(testRowCol, testColor))
    {
        testColor.printComponentValues();
    }
    else
    {
        cout << "Invalid Index!";
    }
    cout << endl;
    
    //Set up an array of images of different colors
    testColor.setToRed();
    testColor.adjustBrightness(0.25);
    testImages[0].initializeTo(testColor);
    testColor.setToBlue();
    testColor.adjustBrightness(0.75);
    testImages[1].initializeTo(testColor);
    testColor.setToGreen();
    testImages[2].initializeTo(testColor);
    
    //Modify a few individual pixel colors
    testRowCol.setRowCol(4, 2);
    testColor.setToWhite();
    testImages[1].setColorAtLocation(testRowCol, testColor);
    
    testRowCol.setRowCol(2, 4);
    testColor.setToBlack();
    testImages[2].setColorAtLocation(testRowCol, testColor);
    
    //Add up all images in testImages array and assign result
    //to the testImage image
    testImage.addImages(3, testImages);
    
    //Check some certain values
    cout << "Added values:" << endl;
    for (int colInd = 0; colInd < 8; colInd += 2)
    {
        testRowCol.setRowCol(4, colInd);
        cout << "Color at ";
        testRowCol.printRowCol();
        cout << ": ";
        if (testImage.getColorAtLocation(testRowCol, testColor))
        {
            testColor.printComponentValues();
        }
        else
        {
            cout << "Invalid Index!";
        }
        cout << endl;
    }
    
    for (int rowInd = 0; rowInd < 8; rowInd += 2)
    {
        testRowCol.setRowCol(rowInd, 4);
        cout << "Color at ";
        testRowCol.printRowCol();
        cout << ": ";
        if (testImage.getColorAtLocation(testRowCol, testColor))
        {
            testColor.printComponentValues();
        }
        else
        {
            cout << "Invalid Index!";
        }
        cout << endl;
    }
    
    cout << "Printing entire test image:" << endl;
    testImage.printImage();

    return 0;
}
#endif




// ************************************************************
// ********* ColorClass member functions definitions **********
bool ColorClass:: needClip(
                           int &inColor
                           )
{
    // Initialize a boolean to represent whether clipping is needed.
    bool inputNeedClip = false;
    
    // Test if input value are valid and clip it if invalid
    if (inColor < MINIMUM_RGB)
    {
        inColor = MINIMUM_RGB;
        inputNeedClip = true;
    }
    else if (inColor > MAXIMUM_RGB)
    {
        inColor = MAXIMUM_RGB;
        inputNeedClip = true;
    }
    return inputNeedClip;
}

bool ColorClass:: needClip(
                           int &inRed,
                           int &inGreen,
                           int &inBlue
                           )
{
    // Initialize a boolean to represent whether clipping is needed.
    bool inputNeedClip = false;

    // Call the function needClip(int &inColor) to clip the three values.
    bool redNeedClip = needClip(inRed);
    bool greenNeedClip = needClip(inGreen);
    bool blueNeedClip = needClip(inBlue);
    
    // If any of three value need to be clipped, then return true.
    if (redNeedClip == true || greenNeedClip == true || blueNeedClip == true)
    {
        inputNeedClip = true;
    }
    return inputNeedClip;
}

void ColorClass:: setToBlack()
{
    inRed = MINIMUM_RGB;
    inGreen = MINIMUM_RGB;
    inBlue = MINIMUM_RGB;
}

void ColorClass:: setToRed()
{
    inRed = MAXIMUM_RGB;
    inGreen = MINIMUM_RGB;
    inBlue = MINIMUM_RGB;
}

void ColorClass:: setToGreen()
{
    inRed = MINIMUM_RGB;
    inGreen = MAXIMUM_RGB;
    inBlue = MINIMUM_RGB;
}

void ColorClass:: setToBlue()
{
    inRed = MINIMUM_RGB;
    inGreen = MINIMUM_RGB;
    inBlue = MAXIMUM_RGB;
}

void ColorClass:: setToWhite()
{
    inRed = MAXIMUM_RGB;
    inGreen = MAXIMUM_RGB;
    inBlue = MAXIMUM_RGB;
}

bool ColorClass:: setTo(
                        int inRed,
                        int inGreen,
                        int inBlue
                        )
{
    // Test whether any component needs clipping, and clip them if needed to.
    bool inputNeedClip = needClip(inRed, inGreen, inBlue);
    
    this->inRed = inRed;
    this->inGreen = inGreen;
    this->inBlue = inBlue;
    
    return inputNeedClip;
}

bool ColorClass:: setTo(
                        ColorClass &inColor
                        )
{
    this->inRed = inColor.inRed;
    this->inGreen = inColor.inGreen;
    this->inBlue = inColor.inBlue;
    
    bool inputNeedClip = needClip(inRed, inGreen, inBlue);
    
    return inputNeedClip;
}

bool ColorClass:: addColor(
                           ColorClass &rhs
                           )
{
    this->inRed += rhs.inRed;
    this->inGreen += rhs.inGreen;
    this->inBlue += rhs.inBlue;
    
    bool inputNeedClip = needClip(inRed, inGreen, inBlue);
    
    return inputNeedClip;
}

bool ColorClass:: subtractColor(
                                ColorClass &rhs
                                )
{
    this->inRed -= rhs.inRed;
    this->inGreen -= rhs.inGreen;
    this->inBlue -= rhs.inBlue;
    
    bool inputNeedClip = needClip(inRed, inGreen, inBlue);
    
    return inputNeedClip;
}

bool ColorClass:: adjustBrightness(
                                   double adjFactor
                                   )
{
    inRed = adjFactor * inRed;
    inGreen = adjFactor * inGreen;
    inBlue = adjFactor * inBlue;
    
    bool inputNeedClip = needClip(inRed, inGreen, inBlue);
    
    return inputNeedClip;
}

void ColorClass:: printComponentValues()
{
    cout << "R: " << inRed;
    cout << " G: " << inGreen;
    cout << " B: " << inBlue;
}




// ************************************************************
// ******* RowColumnClass member functions definitions ********
void RowColumnClass:: setRowCol(
                                int inRow,
                                int inCol
                                )
{
    this->inRow = inRow;
    this->inCol = inCol;
}

void RowColumnClass:: setRow(
                             int inRow
                             )
{
    this->inRow = inRow;
}

void RowColumnClass:: setCol(
                             int inCol
                             )
{
    this->inCol = inCol;
}

int RowColumnClass:: getRow()
{
    return inRow;
}

int RowColumnClass:: getCol()
{
    return inCol;
}

void RowColumnClass:: addRowColTo(
                                  RowColumnClass &inRowCol
                                  )
{
    this->inRow += inRowCol.inRow;
    this->inCol += inRowCol.inCol;
}

void RowColumnClass:: printRowCol()
{
    cout << '[' << inRow << ',' << inCol << ']';
}




// ************************************************************
// ******* ColorImageClass member functions definitions *******
bool ColorImageClass:: isValidLocation(
                                       RowColumnClass &inRowCol
                                       )
{
    // Use a bool to represent whether the indexes are valid.
    bool isValid = false;
    int inRow = inRowCol.getRow();
    int inCol = inRowCol.getCol();
    
    if (inRow >= MINIMUM_NUM_ROWS && inRow < IMAGE_NUM_ROWS
        && inCol >= MINIMUM_NUM_COLS && inCol < IMAGE_NUM_COLS)
    {
        isValid = true;
    }
    
    return isValid;
}

void ColorImageClass:: initializeTo(
                                    ColorClass &inColor
                                    )
{
    // Traverse each pixel of the image, and assign input values to current.
    for (int i = 0; i < IMAGE_NUM_ROWS; i++)
    {
        for (int j = 0; j < IMAGE_NUM_COLS; j++)
        {
            colorArray[i][j] = inColor;
        }
    }
}

bool ColorImageClass:: addImageTo(
                                  ColorImageClass &rhsImg
                                  )
{
    // Initialize a bool to represent whether clipping is needed.
    bool inputNeedClip = false;
    
    // Traverse each pixel of the image.
    for (int i = 0; i < IMAGE_NUM_ROWS; i++)
    {
        for (int j = 0; j < IMAGE_NUM_COLS; j++)
        {
            // Initialize a ColorClass object to store the color at [i, j]
            ColorClass outColor;
            RowColumnClass inRowCol(i, j);
            
            // Get color at the same position of rhsImg
            rhsImg.getColorAtLocation(inRowCol, outColor);
            
            // Add the RGB values in corresponding pixel to current image.
            // Meantime, change the bool to true if clipping is ever needed.
            if (colorArray[i][j].addColor(outColor) == true) {
                inputNeedClip = true;
            }
        }
    }
    
    return inputNeedClip;
}

bool ColorImageClass:: addImages(
                                 int numImgsToAdd,
                                 ColorImageClass imagesToAdd []
                                 )
{
    bool inputNeedClip = false;
    // Assign the current image to fullBlack (R: 0, G: 0, B: 0).
    ColorClass fullBlack(0, 0, 0);
    initializeTo(fullBlack);
    
    // k stands for the (k+1)-th images
    for (int k = 0; k < numImgsToAdd; k++)
    {
        // Add the RGB values in pixel to current image, which has already
        // been assigned full black. Meantime, change the bool if needed.
        if (addImageTo(imagesToAdd[k]) == true)
        {
            inputNeedClip = true;
        }
    }
    
    return inputNeedClip;
}

bool ColorImageClass:: setColorAtLocation(
                                          RowColumnClass &inRowCol,
                                          ColorClass &inColor
                                          )
{
    int inRow = inRowCol.getRow();
    int inCol = inRowCol.getCol();
    
    // Use the bool  to store if the indexes are valid.
    bool isValid = isValidLocation(inRowCol);
    
    // Assign the input values to current image if the location is valid.
    if (isValid == true)
    {
        colorArray[inRow][inCol] = inColor;
    }
    
    return isValid;
}

bool ColorImageClass:: getColorAtLocation(
                                          RowColumnClass &inRowCol,
                                          ColorClass &outColor
                                          )
{
    int inRow = inRowCol.getRow();
    int inCol = inRowCol.getCol();
    
    // Use the bool  to store if the indexes are valid.
    bool isValid = isValidLocation(inRowCol);
    
    // Assign the current image values to outColor values if valid.
    if (isValid == true)
    {
        outColor = colorArray[inRow][inCol];
    }
    
    return isValid;
}

void ColorImageClass:: printImage()
{
    // Traverse each pixel and print the RGB values.
    for (int i = 0; i < IMAGE_NUM_ROWS; i++)
    {
        for (int j = 0; j < IMAGE_NUM_COLS; j++)
        {
            colorArray[i][j].printComponentValues();
            
            if (j < IMAGE_NUM_COLS - 1)
            {
                cout << "--";
            }
        }
        cout << endl;
    }
}
