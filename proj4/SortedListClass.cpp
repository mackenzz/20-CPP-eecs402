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
SortedListClass:: SortedListClass()
{
    this->head = NULL;
    this->tail = NULL;
}


SortedListClass:: SortedListClass(
                                 const SortedListClass &rhs
                                 )
{
    this->head = NULL;
    this->tail = NULL;
    
    LinkedNodeClass *rhsTemp = rhs.head;
    int rhsVal = 0;
    
    while (rhsTemp)
    {
        rhsVal = rhsTemp->getValue();
        this->insertValue(rhsVal);
        rhsTemp = rhsTemp->getNext();
    }
    
    
}


void SortedListClass:: clear()
{
    LinkedNodeClass* temp = this->head;
    
    while (temp)
    {
        LinkedNodeClass* next = temp->getNext();
        delete temp;
        temp = next;
    }
    
    this->head = NULL;
    this->tail = NULL;
}


SortedListClass:: ~SortedListClass()
{
    this->clear();
}


// Main functions
void SortedListClass:: insertValue(
                                   const int &valToInsert
                                   )
{
    // Insert when head is NULL
    if (this->head == NULL)
    {
        this->head = new LinkedNodeClass(NULL, valToInsert, NULL);
        this->tail = this->head;
        // return since we already got the num inserted
        return;
    }
    
    // Boundary situations when interting at the front or the last
    if (valToInsert <= head->getValue())
    {
        LinkedNodeClass *temp = new LinkedNodeClass(
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
        LinkedNodeClass *temp = new LinkedNodeClass(
                                                    this->tail,
                                                    valToInsert,
                                                    NULL
                                                    );
        temp->setBeforeAndAfterPointers();
        this->tail = temp;
        return;
    }
    
    // Insert between, but exclusive of, head and tail
    LinkedNodeClass *temp = head;
    LinkedNodeClass *insert;
    while (temp->getNext())
    {
        if (valToInsert >= temp->getValue()
            && valToInsert < temp->getNext()->getValue())
        {
            insert = new LinkedNodeClass(
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


void SortedListClass:: printForward() const
{
    cout << "Forward List Contents Follow:" << endl;
    LinkedNodeClass *temp = this->head;

    while (temp)
    {
        cout << "  " << temp->getValue() << endl;
        temp = temp->getNext();
    }

    cout << "End Of List Contents" << endl << endl;
}


void SortedListClass:: printBackward() const
{
    cout << "Backward List Contents Follow:" << endl;
    LinkedNodeClass *temp = this->tail;
    
    while (temp)
    {
        cout << "  " << temp->getValue() << endl;
        temp = temp->getPrev();
    }
    
    cout <<  "End Of List Contents" << endl << endl;
}


bool SortedListClass:: removeFront(
                                   int &theVal
                                   )
{
    bool isFound = false;
    LinkedNodeClass *temp;
    
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


bool SortedListClass:: removeLast(
                                  int &theVal
                                  )
{
    bool isFound = false;
    LinkedNodeClass *temp;
    
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



int SortedListClass:: getNumElems() const
{
    int numElems = 0;
    LinkedNodeClass *temp;
    
    temp = this->head;
    
    while (temp)
    {
        numElems += 1;
        temp = temp->getNext();
    }
    
    return numElems;
}


bool SortedListClass:: getElemAtIndex(
                                      const int index,
                                      int &outVal
                                      ) const
{
    bool isInRange = false;
    LinkedNodeClass *temp;
    
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


