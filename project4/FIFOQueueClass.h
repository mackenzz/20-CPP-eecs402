//
//  FIFOQueueClass.h
//  project4
//
//  Created by Zijin Zhang on 11/21/20.
//  Copyright © 2020 Zijin Zhang. All rights reserved.
//


#include <iostream>
#include "LinkedNodeClass.h"
using namespace std;


#ifndef _FIFOQUEUECLASS_H_
#define _FIFOQUEUECLASS_H_

class FIFOQueueClass
{
private:
    LinkedNodeClass *head;
    LinkedNodeClass *tail;
    
public:
    FIFOQueueClass();
    ~FIFOQueueClass();
    
    void enqueue(
                 const int &newItem
                 );
    
    bool dequeue(
                 int &outItem
                 );
    
    void print() const;
    
    int getNumElems() const;
    
    void clear();
    
    
};


#endif /* FIFOQueueClass_h */
