//
//  LIFOStackClass.h
//  project4
//
//  Created by Zijin Zhang on 11/21/20.
//  Copyright © 2020 Zijin Zhang. All rights reserved.
//


#include <iostream>
#include "LinkedNodeClass.h"
using namespace std;

#ifndef _LIFOSTACKCLASS_H_
#define _LIFOSTACKCLASS_H_

class LIFOStackClass
{
private:
    LinkedNodeClass *head;
    LinkedNodeClass *tail;
    
public:
    LIFOStackClass();
    ~LIFOStackClass();
    
    void push(
              const int &newItem
              );
    
    bool pop(
             int &outItem
             );
    
    void print() const;
    
    int getNumElems() const;
    
    void clear();
};


#endif /* LIFOStackClass_h */
