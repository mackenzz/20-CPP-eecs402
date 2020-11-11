//
//  ImgOutputClass.cpp
//  eecs402 project3
//
//  Created by Zijin Zhang on 11/1/20.
//  Copyright © 2020 Zijin Zhang. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "ImgOutputClass.h"
using namespace std;

bool ImgOutput:: outputToImg()
{
    bool isValidFile = false;
    
    ofstream outFile;
    outFile.open(outputFile.c_str());
    if (outFile.fail())
    {
        cout<< "You are trying to open the output file, but unable "
        << "to open it!" << endl;
    }
    else
    {
        outFile << PPM_FIRST_LINE << endl;
        outFile << PPM_SECOND_LINE << endl;
        outFile << MAX_RGB << endl;
        for (int i = 0; i < sizeHeight; i++)
        {
            for (int j = 0; j < sizeWidth * NUM_RGB; j++)
            {
                outFile << imageArray[i][j] << " ";
            }
            outFile << endl;
        }
        
        outFile.close();
        cout << "Sucessfully output!" << endl;
        isValidFile = true;
    }
    
    outFile.close();
    return isValidFile;
}
