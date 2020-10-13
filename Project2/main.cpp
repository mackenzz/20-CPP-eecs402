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


// =======================================================================
class ColorClass {
private:
    int inRed;
    int inGreen;
    int inBlue;
    
    // The function is used to test whether an input color value is inrange
    // If not, the function will clip it to be in range [0, 255]
    bool needClip(int &inColor)
    {
        bool needToClip = false;
        if (inColor < MINIMUM_RGB)
        {
            inColor = MINIMUM_RGB;
            needToClip = true;
        }
        else if (inColor > MAXIMUM_RGB)
        {
            inColor = MAXIMUM_RGB;
            needToClip = true;
        }
        return needToClip;
    };
    
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
        this->inRed = inRed;
        this->inGreen = inGreen;
        this->inBlue = inBlue;
    };
    
    // Set the pixel to specified colors
    void setToBlack()
    {
        inRed = MINIMUM_RGB;
        inGreen = MINIMUM_RGB;
        inBlue = MINIMUM_RGB;
    };
    void setToRed()
    {
        inRed = MAXIMUM_RGB;
        inGreen = MINIMUM_RGB;
        inBlue = MINIMUM_RGB;
    };
    void setToGreen()
    {
        inRed = MINIMUM_RGB;
        inGreen = MAXIMUM_RGB;
        inBlue = MINIMUM_RGB;
    };
    void setToBlue()
    {
        inRed = MINIMUM_RGB;
        inGreen = MINIMUM_RGB;
        inBlue = MAXIMUM_RGB;
    };
    void setToWhite()
    {
        inRed = MAXIMUM_RGB;
        inGreen = MAXIMUM_RGB;
        inBlue = MAXIMUM_RGB;
    };
    
    // The function set the RGB values to input values
    bool setTo(
               int inRed,
               int inGreen,
               int inBlue)
    {
        bool inputNeedClip = false;
        bool redNeedClip = needClip(inRed);
        bool greenNeedClip = needClip(inGreen);
        bool blueNeedClip = needClip(inBlue);
        
        if (redNeedClip == true || greenNeedClip == true
            || blueNeedClip == true)
        {
            inputNeedClip = true;
        }
        
        this->inRed = inRed;
        this->inGreen = inGreen;
        this->inBlue = inBlue;
        
        return inputNeedClip;
    };
    
    
    // Set the object to have the same RGB with the input object inColor
    bool setTo(
               ColorClass &inColor
               )
    {
        bool inputNeedClip = false;
        
        this->inRed = inColor.inRed;
        this->inGreen = inColor.inGreen;
        this->inBlue = inColor.inBlue;
        
        bool redNeedClip = needClip(inRed);
        bool greenNeedClip = needClip(inGreen);
        bool blueNeedClip = needClip(inBlue);
        
        if (redNeedClip == true || greenNeedClip == true
            || blueNeedClip == true)
        {
            inputNeedClip = true;
        }
        
        return inputNeedClip;
    };
    
    
    // The function is used to have input parameter color added to it
    bool addColor(
                  ColorClass &rhs
                  )
    {
        bool inputNeedClip = false;
        
        this->inRed += rhs.inRed;
        this->inGreen += rhs.inGreen;
        this->inBlue += rhs.inBlue;
        
        bool redNeedClip = needClip(inRed);
        bool greenNeedClip = needClip(inGreen);
        bool blueNeedClip = needClip(inBlue);
        
        if (redNeedClip == true || greenNeedClip == true
            || blueNeedClip == true)
        {
            inputNeedClip = true;
        }
        
        return inputNeedClip;
    };
    
    // The function is used to have input parameter color subtracted from it
    bool subtractColor(
                       ColorClass &rhs
                       )
    {
        bool inputNeedClip = false;
        
        this->inRed -= rhs.inRed;
        this->inGreen -= rhs.inGreen;
        this->inBlue -= rhs.inBlue;
        
        bool redNeedClip = needClip(inRed);
        bool greenNeedClip = needClip(inGreen);
        bool blueNeedClip = needClip(inBlue);
        
        if (redNeedClip == true || greenNeedClip == true
            || blueNeedClip == true)
        {
            inputNeedClip = true;
        }
        
        return inputNeedClip;
    };
    
    
    bool adjustBrightness(
                          double adjFactor
                          )
    {
        bool inputNeedClip = false;
        inRed = adjFactor * inRed;
        inGreen = adjFactor * inGreen;
        inBlue = adjFactor * inBlue;
        
        bool redNeedClip = needClip(inRed);
        bool greenNeedClip = needClip(inGreen);
        bool blueNeedClip = needClip(inBlue);
        
        if (redNeedClip == true || greenNeedClip == true
            || blueNeedClip == true)
        {
            inputNeedClip = true;
        }
        
        return inputNeedClip;
    };
    
    // The functionn is used to print the RGB values
    void printComponentValues()
    {
        cout << "R: " << inRed;
        cout << " G: " << inGreen;
        cout << " B: " << inBlue;
    };
    
};




// =======================================================================
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
                   int inCol)
    {
        this->inRow = inRow;
        this->inCol = inCol;
    };
    
    void setRowCol(
                   int inRow,
                   int inCol)
    {
        this->inRow = inRow;
        this->inCol = inCol;
    };
    void setRow(
                int inRow
                )
    {
        this->inRow = inRow;
    };
    void setCol(int inCol){
        this->inCol = inCol;
    };
    
    int getRow()
    {
        return inRow;
    };
    int getCol()
    {
        return inCol;
    };
    
    void addRowColTo(
                     RowColumnClass &inRowCol
                     )
    {
        this->inRow += inRowCol.inRow;
        this->inCol += inRowCol.inCol;
    };
    
    void printRowCol()
    {
        cout << '[' << inRow << ',' << inCol << ']';
    };
};



// =======================================================================
class ColorImageClass {
private:
    int numRows = 10;
    int numCols = 18;
    ColorClass colorArray[IMAGE_NUM_ROWS][IMAGE_NUM_COLS];

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
                    )
    {
        for (int i = 0; i < IMAGE_NUM_ROWS; i++)
        {
            for (int j = 0; j < IMAGE_NUM_COLS; j++)
            {
                colorArray[i][j] = inColor;
            }
        }
    };
    
    
    bool addImageTo(ColorImageClass &rhsImg)
    {
        bool inputNeedClip = false;
        bool outputNeedClip = false;
        
        
        for (int i = 0; i < IMAGE_NUM_ROWS; i++)
        {
            for (int j = 0; j < IMAGE_NUM_COLS; j++)
            {
                RowColumnClass inRowCol(i, j);
                ColorClass outColor;
                
                // Get color at the same position of rhsImg
                inputNeedClip = rhsImg.getColorAtLocation(inRowCol, outColor);
                // After adding rhsImg color at [i, j]
                if (colorArray[i][j].addColor(outColor) == true) {
                    outputNeedClip = true;
                }
            }
        }
        return outputNeedClip;
    };
    
    
    
    bool addImages(
                   int numImgsToAdd,
                   ColorImageClass imagesToAdd []
                   )
    {
        bool needClip = false;
        // Initialize the current image to fullBlack
        ColorClass fullBlack(0, 0, 0);
        initializeTo(fullBlack);
        
        // k stands for the kth images
        for (int k = 0; k < numImgsToAdd; k++)
        {
            if (addImageTo(imagesToAdd[k]) == true)
            {
                needClip = true;
            }
        }
        
        return needClip;
    };
    
    
    
    bool setColorAtLocation(
                            RowColumnClass &inRowCol,
                            ColorClass &inColor)
    {
        bool isValidLocation = false;
        int inRow = inRowCol.getRow();
        int inCol = inRowCol.getCol();
        
        if (inRow >= 0 && inRow < IMAGE_NUM_ROWS && inCol >= 0 && inCol < IMAGE_NUM_COLS)
        {
            isValidLocation = true;
            colorArray[inRow][inCol] = inColor;
        }
        return isValidLocation;
    };
    
    
    
    bool getColorAtLocation(
                            RowColumnClass &inRowCol,
                            ColorClass &outColor
                            )
    {
        bool isValidLocation = false;
        int inRow = inRowCol.getRow();
        int inCol = inRowCol.getCol();
        
        if (inRow >= 0 && inRow < IMAGE_NUM_ROWS && inCol >= 0 && inCol < IMAGE_NUM_COLS)
        {
            isValidLocation = true;
            outColor = colorArray[inRow][inCol];
        }
        return isValidLocation;
    };
    
    
    
    void printImage()
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
    };
    
};




int main(int argc, const char * argv[]) {
    // insert code here...

//    ColorClass testColor1(15, 15, 0);
//    ColorClass testColor2(20, 20, 9);
//    ColorClass testColor3(1, 1, 1);
//
//    cout << endl << endl;
//
//
//    ColorImageClass testImage;
//    testImage.initializeTo(testColor1);
//    cout << "testImage: " << endl;
//    testColor1.printComponentValues();
//
//    ColorImageClass testImage2;
//    testImage2.initializeTo(testColor2);
//    cout << endl <<"testImage2: " << endl;
//    testColor2.printComponentValues();
//
//    ColorImageClass testImage3;
//    testImage3.initializeTo(testColor3);
//    cout << endl <<"testImage3: " << endl;
//    testColor3.printComponentValues();
//
//    cout << endl << endl;
//    ColorImageClass imageaArray[2] = {testImage, testImage2};
//    testImage3.addImages(2, imageaArray);
//    testImage3.printImage();
    
    ColorClass testColor;
    RowColumnClass testRowCol;
    RowColumnClass testRowColOther(111, 222);
    ColorImageClass testImage;
    ColorImageClass testImages[3];
    
    
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
