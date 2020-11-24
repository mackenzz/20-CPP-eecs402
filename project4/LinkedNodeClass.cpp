//
//  LinkedNodeClass.cpp
//  project4
//
//  Created by Zijin Zhang on 11/20/20.
//  Copyright © 2020 Zijin Zhang. All rights reserved.
//


#include "LinkedNodeClass.h"





// Constructor
LinkedNodeClass:: LinkedNodeClass(
                                  LinkedNodeClass *inPrev,
                                  const int &inVal,
                                  LinkedNodeClass *inNext
                                  )
{
    this->prevNode = inPrev;
    this->nodeVal = inVal;
    this->nextNode = inNext;
}



// Functions
int LinkedNodeClass:: getValue() const
{
    return this->nodeVal;
}


LinkedNodeClass* LinkedNodeClass:: getNext() const
{
    return this->nextNode;
}


LinkedNodeClass* LinkedNodeClass:: getPrev() const
{
    return this->prevNode;
}


void LinkedNodeClass:: setPreviousPointerToNull()
{
    this->prevNode = NULL;
}


void LinkedNodeClass:: setNextPointerToNull()
{
    this->nextNode = NULL;
}


void LinkedNodeClass:: setBeforeAndAfterPointers()
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



