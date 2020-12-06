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

template <class T>
FIFOQueueClass<T>:: FIFOQueueClass()
{
    this->head = NULL;
    this->tail = NULL;
}


template <class T>
FIFOQueueClass<T>:: ~FIFOQueueClass()
{
    this->clear();
}


template <class T>
void FIFOQueueClass<T>:: enqueue(
                              const T &newItem
                              )
{
    // Add to the last
    if (!this->head)
    {
        this->head = new LinkedNodeClass<T>(NULL, newItem, NULL);
        this->tail = this->head;
    }
    else
    {
        LinkedNodeClass<T> *temp;
        LinkedNodeClass<T> *tailNode = this->tail;

        temp = new LinkedNodeClass<T>(tailNode, newItem, NULL);
        temp->setBeforeAndAfterPointers();

        this->tail = temp;
    }

}


template <class T>
bool FIFOQueueClass<T>:: dequeue(
                              T &outItem
                              )
{
    // Delete from the front
    bool isFound = false;
    LinkedNodeClass<T> *temp = this->head;

    
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


template <class T>
void FIFOQueueClass<T>:: print() const
{
    // Print from head to tail
    LinkedNodeClass<T> *temp;

    temp = head;

    while (temp)
    {
        cout << temp->getValue() << " ";
        temp = temp->getNext();
    }
    cout << endl;
}


template <class T>
int FIFOQueueClass<T>:: getNumElems() const
{
    int numElems = 0;
    LinkedNodeClass<T> *temp;

    temp = head;

    while (temp)
    {
        numElems += 1;
        temp = temp->getNext();
    }

    return numElems;
}


template <class T>
void FIFOQueueClass<T>:: clear()
{
    LinkedNodeClass<T> *temp = this->head;
    while (temp)
    {
        LinkedNodeClass<T> *next = temp->getNext();
        delete temp;
        temp = next;
    }
    this->head = NULL;
    this->tail = NULL;

}



