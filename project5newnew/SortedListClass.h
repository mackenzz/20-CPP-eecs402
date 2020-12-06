//
//  SortedListClass.h
//  project4
//
//  Created by Zijin Zhang on 11/20/20.
//  Copyright © 2020 Zijin Zhang. All rights reserved.
//

#include <iostream>
#include "LinkedNodeClass.h"
using namespace std;

#ifndef _SORTEDLISTCLASS_H_
#define _SORTEDLISTCLASS_H_

//The sorted list class does not store any data directly. Instead,
//it contains a collection
//contains one element.
template <class T>
class SortedListClass
{
private:
    LinkedNodeClass<T> *head;
    LinkedNodeClass<T> *tail;
    
public:
    //Constructor and destructor
    //Default Constructor.
    SortedListClass();
    
    //Copy constructor.
    SortedListClass(
                    const SortedListClass<T> &rhs
                    );
    
    //Destructor.
    ~SortedListClass();
    
    //Clears the list to an empty list.
    void clear();
    
    // Main functions
    //Allows the user to insert value into the list.
    void insertValue(
                     const T &valToInsert
                     );
    
    //Prints the contents of the list from head to tail.
    void printForward() const;
    
    //Prints the contents of the list from tail to head.
    void printBackward() const;
    
    //Removes the front item from the list and returns the value.
    bool removeFront(
                     T &theVal
                     );
    
    //Removes the last item from the list and returns the value.
    bool removeLast(
                    T &theVal
                    );
    
    //Returns the number of nodes contained in the list.
    int getNumElems() const;
    
    //Provides the value stored in the node at index provided.
    bool getElemAtIndex(
                        const int index,
                        T &outVal
                        ) const;

    
    
};
#include "SortedListClass.inl"
#endif /* SORTEDLISTCLASS_H */
