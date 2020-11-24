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
    //Default Constructor.
    LIFOStackClass();
    
    //Destructor.
    ~LIFOStackClass();
    
    //Inserts the value provided (newItem) into the stack.
    void push(
              const int &newItem
              );
    
    //Attempts to take the next item out of the stack.
    bool pop(
             int &outItem
             );
    
    //Prints out the contents of the stack.
    void print() const;
    
    //Returns the number of nodes contained in the stack.
    int getNumElems() const;
    
    //Clears the stack to an empty state.
    void clear();
};


#endif /* LIFOSTACKCLASS_H */
