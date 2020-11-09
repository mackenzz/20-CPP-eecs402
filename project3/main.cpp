//
//  main.cpp
//  project3
//
//  Created by Zijin Zhang on 11/1/20.
//  Copyright © 2020 Zijin Zhang. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
class ImgLoad {
private:
    string fileName;
    int width = 0;
    int height = 0;
    
public:
    string **image = new string*[height];
    ImgLoad(
            string fileName
            )
    {
        this->fileName = fileName;
    };
    
    bool loadToBuffer()
    {

        bool isValidImg = false;
        ifstream inFile;
        string line;
        
        
        
        inFile.open(fileName.c_str());
        if (inFile.fail())
        {
            cout << "Unable to open file!" << endl;
        }
        else
        {
            isValidImg = true;
            string line1;
            string line2;
            string line3;
            getline(inFile, line1);
            getline(inFile, line2);
            istringstream issSize(line2);
            issSize >> width;
            issSize >> height;
            cout << "Width is: " << width << endl
            << "Height is: " << height << endl << endl;
            getline(inFile, line3);
            
//            string **image = new string*[height];
            

//            while (!inFile.eof())
            for (int i=0; i<height; ++i)
            {
                image[i] = new string[width * 3];
                istringstream iss;
                getline(inFile, line);
                iss.str(line);  // parse each line

                for (int j=0; j<width*3; j++)
                {
                    if (!iss.eof())
                    {
                        iss >> image[i][j];
//                        cout << image[i][j] << ' ';
                    }
                }
//                cout << endl << endl << endl;
            }
            
        }
        
        inFile.close();
        return isValidImg;
    };
};


class ImgModify
{
private:
    int width = 5;
    int height = 5;
    string fileName;
public:
    string **image = new string *[height];
    ImgModify(
             string fileName
             )
    {
        this->fileName = fileName;
    };
    
    bool addRectangle(int upperLeft[2], int lowerRight[2], int color, bool isFilled)
    {
        ImgLoad inputImg(fileName);
        image = inputImg.image;
        
        bool isValidImg = inputImg.loadToBuffer();
        int inRed = 0;
        int inGreen = 0;
        int inBlue = 0;
        if (color == 1) {     // carefull for magic number
            inRed = 255;
        }
        
        if (!isFilled)
        {
            for (int i=upperLeft[0]; i<lowerRight[0]; i++)
            {
                for (int j=(upperLeft[1]-1)*3+1; j<(lowerRight[1]*3); j++){
                    if (j % 3 == 1){
                        image[upperLeft[0]][j] = "255";
                        image[lowerRight[0]][j] = "255";
                    }
                    else
                    {
                        image[upperLeft[0]][j] = "0";
                        image[lowerRight[0]][j] = "0";
                    }
                }
            }
        }
        cout << "this is for testing: " << image[0][1] << endl;
        
        return isValidImg;
    };
    
    
    
};


int main(int argc, char * argv[]) {
    
    string fileName = "deerTest.txt";
    ImgLoad deerLoad(fileName);
    deerLoad.loadToBuffer();
    cout << deerLoad.image[0][2] << endl;
    ImgModify testModify(fileName);
    
    
    int upperLeft[2] = {0,0};
    int lowerRight[2]={2,3};
    int color=1;
    bool isFilled=false;
    testModify.addRectangle(upperLeft, lowerRight, color, isFilled);
    cout << testModify.image[0][0];
    
    
    

 
    
    return 0;
}

