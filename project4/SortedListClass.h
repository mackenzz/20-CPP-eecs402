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
class SortedListClass
{
private:
    LinkedNodeClass *head;
    LinkedNodeClass *tail;
    
public:
    //Constructor and destructor
    SortedListClass();
    SortedListClass(
                    const SortedListClass &rhs
                    );
    ~SortedListClass();
    void clear();
    
    // Main functions
    void insertValue(
                     const int &valToInsert
                     );
    
    void printForward() const;
    
    void printBackward() const;
    
    bool removeFront(
                     int &theVal
                     );
    
    bool removeLast(
                    int &theVal
                    );
    
    int getNumElems() const;
    
    bool getElemAtIndex(
                        const int index,
                        int &outVal
                        ) const;

    
    
};

#endif /* SortedListClass_h */
