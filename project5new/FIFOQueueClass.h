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

template <class T>
class FIFOQueueClass
{
private:
    LinkedNodeClass<T> *head;
    LinkedNodeClass<T> *tail;

public:
    //Default Constructor.
    FIFOQueueClass();

    //Destructor.
    ~FIFOQueueClass();

    //Inserts the value provided (newItem) into the queue.
    void enqueue(
                 const T &newItem
                 );

    //Attempts to take the next item out of the queue.
    bool dequeue(
                 T &outItem
                 );

    //Prints out the contents of the queue.
    void print() const;

    //Returns the number of nodes contained in the queue.
    int getNumElems() const;

    //Clears the queue to an empty state.
    void clear();


};


#include "FIFOQueueClass.inl"
#endif /* FIFOQUEUECLASS_H */

