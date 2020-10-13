//
//  main.cpp
//  project2
//
//  Created by Zijin Zhang on 10/3/20.
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

// =======================================================================
class ColorClass {
private:
    int inRed;
    int inGreen;
    int inBlue;
    
    // The function is used to test whether an input color needs clipping
    bool needClip(
                  int &inColor
                  );
    bool needClip(
                  int &inRed,
                  int &inGreen,
                  int &inBlue
                  );
    
public:
    ColorClass()
    {
        inRed = MAXIMUM_RGB;
        inGreen = MAXIMUM_RGB;
        inBlue = MAXIMUM_RGB;
    };
    
    ColorClass(
               int inRed,
               int inGreen,
               int inBlue
               )
    {
        // Here I have questions!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        needClip(inRed, inGreen, inBlue);
        this->inRed = inRed;
        this->inGreen = inGreen;
        this->inBlue = inBlue;
    };
    
    // Set the pixel to specified colors
    void setToBlack();
    void setToRed();
    void setToGreen();
    void setToBlue();
    void setToWhite();
    
    // The function set the RGB values to input values
    bool setTo(
               int inRed,
               int inGreen,
               int inBlue
               );
    
    
    // Set the object to have the same RGB with the input object inColor
    bool setTo(
               ColorClass &inColor
               );
    
    
    // The function is used to have input parameter color added to it
    bool addColor(
                  ColorClass &rhs
                  );
    
    // The function is used to have input parameter color subtracted from it
    bool subtractColor(
                       ColorClass &rhs
                       );
    
    
    bool adjustBrightness(
                          double adjFactor
                          );
    
    // The functionn is used to print the RGB values
    void printComponentValues();
};



class RowColumnClass {
private:
    int inRow;
    int inCol;

public:
    RowColumnClass()
    {
        inRow = INITIAL_ROWS;
        inCol = INITIAL_COLS;
    };
    RowColumnClass(
                   int inRow,
                   int inCol
                   )
    {
        this->inRow = inRow;
        this->inCol = inCol;
    };
    
    void setRowCol(
                   int inRow,
                   int inCol
                   );
    void setRow(
                int inRow
                );
    void setCol(
                int inCol
                );
    int getRow();
    int getCol();
    void addRowColTo(
                     RowColumnClass &inRowCol
                     );
    
    void printRowCol();
};



class ColorImageClass {
private:
    ColorClass colorArray[IMAGE_NUM_ROWS][IMAGE_NUM_COLS];
    bool isValidLocation(RowColumnClass &inRowCol);
    
public:
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
    
    // The function initializes all image pixels to the input color
    void initializeTo(
                    ColorClass &inColor
                    );
    
    bool addImageTo(
                    ColorImageClass &rhsImg
                    );
    
    bool addImages(
                   int numImgsToAdd,
                   ColorImageClass imagesToAdd []
                   );
    
    bool setColorAtLocation(
                            RowColumnClass &inRowCol,
                            ColorClass &inColor
                            );
    
    bool getColorAtLocation(
                            RowColumnClass &inRowCol,
                            ColorClass &outColor
                            );
    void printImage();
    
};



// ************************************************************
// ************************************************************
int main(int argc, const char * argv[]) {
    ColorClass testColor;
    RowColumnClass testRowCol;
    RowColumnClass testRowColOther(111, 222);
    ColorImageClass testImage;
    ColorImageClass testImages[3];
    
    //Test some basic ColorClass operations...
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
    
    //Test some basic RowColumnClass operations...
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
    
    //Test some basic ColorImageClass operations...
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
// ************************************************************
// ************************************************************



// ================================================================
bool ColorClass:: needClip(
                           int &inColor
                           )
{
    bool inputNeedClip = false;
    
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
    bool inputNeedClip = false;
    bool redNeedClip = needClip(inRed);
    bool greenNeedClip = needClip(inGreen);
    bool blueNeedClip = needClip(inBlue);
    
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





// ================================================================
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





// ================================================================
bool ColorImageClass:: isValidLocation(RowColumnClass &inRowCol)
{
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
    bool inputNeedClip = false;
    
    for (int i = 0; i < IMAGE_NUM_ROWS; i++)
    {
        for (int j = 0; j < IMAGE_NUM_COLS; j++)
        {
            RowColumnClass inRowCol(i, j);
            ColorClass outColor;
            
            // Get color at the same position of rhsImg
            rhsImg.getColorAtLocation(inRowCol, outColor);
            // After adding rhsImg color at [i, j]
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
    // Initialize the current image to fullBlack
    ColorClass fullBlack(0, 0, 0);
    initializeTo(fullBlack);
    
    // k stands for the kth images
    for (int k = 0; k < numImgsToAdd; k++)
    {
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
    bool isValid = isValidLocation(inRowCol);
    
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
    bool isValid = isValidLocation(inRowCol);
    
    if (isValid == true)
    {
        outColor = colorArray[inRow][inCol];
    }
    return isValid;
}



void ColorImageClass:: printImage()
{
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
