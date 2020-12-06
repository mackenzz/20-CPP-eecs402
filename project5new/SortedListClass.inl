
//
//  SortedListClass.cpp
//  project4
//
//  Created by Zijin Zhang on 11/20/20.
//  Copyright © 2020 Zijin Zhang. All rights reserved.
//



#include <iostream>
#include "SortedListClass.h"
#include "LinkedNodeClass.h"
using namespace std;

// Constructors, destructor and memory clear
template <class T>
SortedListClass<T>:: SortedListClass()
{
    this->head = NULL;
    this->tail = NULL;
}


template <class T>
SortedListClass<T>:: SortedListClass(
                                 const SortedListClass<T> &rhs
                                 )
{
    this->head = NULL;
    this->tail = NULL;
    
    LinkedNodeClass<T> *rhsTemp = rhs.head;
    int rhsVal = 0;
    
    while (rhsTemp)
    {
        rhsVal = rhsTemp->getValue();
        this->insertValue(rhsVal);
        rhsTemp = rhsTemp->getNext();
    }
    
    
}


template <class T>
void SortedListClass<T>:: clear()
{
    LinkedNodeClass<T>* temp = this->head;
    
    while (temp)
    {
        LinkedNodeClass<T>* next = temp->getNext();
        delete temp;
        temp = next;
    }
    
    this->head = NULL;
    this->tail = NULL;
}


template <class T>
SortedListClass<T>:: ~SortedListClass()
{
    this->clear();
}


// Main functions
template <class T>
void SortedListClass<T>:: insertValue(
                                   const T &valToInsert
                                   )
{
    // Insert when head is NULL
    if (this->head == NULL)
    {
        this->head = new LinkedNodeClass<T>(NULL, valToInsert, NULL);
        this->tail = this->head;
        // return since we already got the num inserted
        return;
    }
    
    // Boundary situations when interting at the front or the last
    if (valToInsert < head->getValue())
    {
        LinkedNodeClass<T> *temp = new LinkedNodeClass<T>(
                                                    NULL,
                                                    valToInsert,
                                                    this->head
                                                    );
        temp->setBeforeAndAfterPointers();
        this->head = temp;
        return;
    }
    
    if (valToInsert >= tail->getValue())
    {
        LinkedNodeClass<T> *temp = new LinkedNodeClass<T>(
                                                    this->tail,
                                                    valToInsert,
                                                    NULL
                                                    );
        temp->setBeforeAndAfterPointers();
        this->tail = temp;
        return;
    }
    
    // Insert between, but exclusive of, head and tail
    LinkedNodeClass<T> *temp = head;
    LinkedNodeClass<T> *insert;
    while (temp->getNext())
    {
        if (valToInsert >= temp->getValue()
            && valToInsert < temp->getNext()->getValue())
        {
            insert = new LinkedNodeClass<T>(
                                         temp,
                                         valToInsert,
                                         temp->getNext()
                                         );
            insert->setBeforeAndAfterPointers();
            return;
        }
        else
        {
            temp = temp->getNext();
        }
    }
    
}


template <class T>
void SortedListClass<T>:: printForward() const
{
    cout << "Forward List Contents Follow:" << endl;
    LinkedNodeClass<T> *temp = this->head;

    while (temp)
    {
        cout << "  " << temp->getValue() << endl;
        temp = temp->getNext();
    }

    cout << "End Of List Contents" << endl << endl;
}


template <class T>
void SortedListClass<T>:: printBackward() const
{
    cout << "Backward List Contents Follow:" << endl;
    LinkedNodeClass<T> *temp = this->tail;
    
    while (temp)
    {
        cout << "  " << temp->getValue() << endl;
        temp = temp->getPrev();
    }
    
    cout <<  "End Of List Contents" << endl << endl;
}


template <class T>
bool SortedListClass<T>:: removeFront(
                                   T &theVal
                                   )
{
    bool isFound = false;
    LinkedNodeClass<T> *temp;
    
    temp = this->head;
    
    if (temp == 0)
    {
        cout << "List is empty." << endl;
    }
    else
    {
        theVal = temp->getValue();
        if (!temp->getNext())
        {
            this->head = NULL;
            this->tail = NULL;
        }
        else
        {
            head = temp->getNext();
            head->setPreviousPointerToNull();
        }
        
        delete temp;
        isFound = true;
    }
    
    return isFound;
}


template <class T>
bool SortedListClass<T>:: removeLast(
                                  T &theVal
                                  )
{
    bool isFound = false;
    LinkedNodeClass<T> *temp;
    
    temp = this->tail;
    
    if (temp == 0)
    {
        cout << "List is empty." << endl;
    }
    else
    {
        theVal = temp->getValue();
        if (!temp->getPrev())
        {
            this->head = NULL;
            this->tail = NULL;
        }
        else
        {
            tail = temp->getPrev();
            tail->setNextPointerToNull();
        }
        
        delete temp;
        isFound = true;
    }
    
    return isFound;
}


template <class T>
int SortedListClass<T>:: getNumElems() const
{
    int numElems = 0;
    LinkedNodeClass<T> *temp;
    
    temp = this->head;
    
    while (temp)
    {
        numElems += 1;
        temp = temp->getNext();
    }
    
    return numElems;
}


template <class T>
bool SortedListClass<T>:: getElemAtIndex(
                                      const int index,
                                      T &outVal
                                      ) const
{
    bool isInRange = false;
    LinkedNodeClass<T> *temp;
    
    temp = this->head;
    int currIndex = 0;
    
    while (temp && currIndex <= index)
    {
        if (currIndex == index)
        {
            outVal = temp->getValue();
            isInRange = true;
        }
        else
        {
            temp = temp->getNext();
        }
        
        currIndex += 1;
    }
    
    return isInRange;
}


