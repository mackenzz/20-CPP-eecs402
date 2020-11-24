//
//  FIFOQueueClass.cpp
//  project4
//
//  Created by Zijin Zhang on 11/21/20.
//  Copyright © 2020 Zijin Zhang. All rights reserved.
//

#include <iostream>
#include "LinkedNodeClass.h"
#include "FIFOQueueClass.h"
using namespace std;


FIFOQueueClass:: FIFOQueueClass()
{
    this->head = NULL;
    this->tail = NULL;
}

FIFOQueueClass:: ~FIFOQueueClass()
{
    this->clear();
}

void FIFOQueueClass:: enqueue(
                              const int &newItem
                              )
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


bool FIFOQueueClass:: dequeue(
                              int &outItem
                              )
{
    // Delete from the front
    bool isFound = false;
    LinkedNodeClass *temp = this->head;
    
    if (temp)
    {
        outItem = temp->getValue();
        
        if (temp->getNext())
        {
            this->head = temp->getNext();
            this->head->setPreviousPointerToNull();
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


void FIFOQueueClass:: print() const
{
    // Print from head to tail
    LinkedNodeClass *temp;
    
    temp = head;
    
    while (temp)
    {
        cout << temp->getValue() << " ";
        temp = temp->getNext();
    }
    cout << endl;
}


int FIFOQueueClass:: getNumElems() const
{
    int numElems = 0;
    LinkedNodeClass *temp;
    
    temp = head;
    
    while (temp)
    {
        numElems += 1;
        temp = temp->getNext();
    }
    
    return numElems;
}


void FIFOQueueClass:: clear()
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







