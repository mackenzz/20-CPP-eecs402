//
//  LinkedNodeClass.cpp
//  project4
//
//  Created by Zijin Zhang on 11/20/20.
//  Copyright © 2020 Zijin Zhang. All rights reserved.
//


#include "LinkedNodeClass.h"

// Constructor
template <class T>
LinkedNodeClass<T>:: LinkedNodeClass(
                                  LinkedNodeClass<T>* inPrev,
                                  const T &inVal,
                                  LinkedNodeClass<T>* inNext
                                  )
{
    this->prevNode = inPrev;
    this->nodeVal = inVal;
    this->nextNode = inNext;
}


// Main functions
template <class T>
T LinkedNodeClass<T>:: getValue() const
{
    return this->nodeVal;
}


template <class T>
LinkedNodeClass<T>* LinkedNodeClass<T>:: getNext() const
{
    return this->nextNode;
}


template <class T>
LinkedNodeClass<T>* LinkedNodeClass<T>:: getPrev() const
{
    return this->prevNode;
}


template <class T>
void LinkedNodeClass<T>:: setPreviousPointerToNull()
{
    this->prevNode = NULL;
}


template <class T>
void LinkedNodeClass<T>:: setNextPointerToNull()
{
    this->nextNode = NULL;
}


template <class T>
void LinkedNodeClass<T>:: setBeforeAndAfterPointers()
{
    if (this->prevNode)
    {
        this->prevNode->nextNode = this;
    }
    
    if (this->nextNode)
    {
        this->nextNode->prevNode = this;
    }
    
}



