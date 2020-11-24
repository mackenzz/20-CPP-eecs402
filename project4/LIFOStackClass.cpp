//
//  LIFOStackClass.cpp
//  project4
//
//  Created by Zijin Zhang on 11/21/20.
//  Copyright © 2020 Zijin Zhang. All rights reserved.
//


#include <iostream>
#include "LinkedNodeClass.h"
#include "LIFOStackClass.h"
using namespace std;

LIFOStackClass:: LIFOStackClass()
{
    this->head = NULL;
    this->tail = NULL;
}

LIFOStackClass:: ~LIFOStackClass()
{
    this->clear();
}



void LIFOStackClass:: push(const int &newItem)
{
    // Add to the last
    if (!this->head)
    {
        this->head = new LinkedNodeClass(NULL, newItem, NULL);
        this->tail = this->head;
    }
    else
    {
        LinkedNodeClass *temp;
        LinkedNodeClass *tailNode = this->tail;
        
        temp = new LinkedNodeClass(tailNode, newItem, NULL);
        temp->setBeforeAndAfterPointers();
        
        this->tail = temp;
    }
    
}


bool LIFOStackClass:: pop(int &outItem)
{
    // Remove from the last
    bool isFound = false;
    LinkedNodeClass *temp = this->tail;
    
    if (temp)
    {
        outItem = temp->getValue();
        
        if (temp->getPrev())
        {
            this->tail = temp->getPrev();
            this->tail->setNextPointerToNull();
        }
        else
        {
            this->head = NULL;
            this->tail = NULL;
        }
        isFound = true;
    }
    
    delete temp;
    return isFound;
}


void LIFOStackClass:: print() const
{
    // Print from head to tail
    LinkedNodeClass *temp;
    temp = this->head;
    
    while (temp) {
        cout << temp->getValue() << " ";
        temp = temp->getNext();
    }
    cout << endl;
    
}


int LIFOStackClass:: getNumElems() const
{
    int numElems = 0;
    LinkedNodeClass *temp;
    
    temp = this->head;
    
    while (temp) {
        numElems += 1;
        temp = temp->getNext();
    }
    
    return numElems;
}


void LIFOStackClass:: clear()
{
    LinkedNodeClass *temp = this->head;
    while (temp)
    {
        LinkedNodeClass *next = temp->getNext();
        delete temp;
        temp = next;
    }
    this->head = NULL;
    this->tail = NULL;
}






