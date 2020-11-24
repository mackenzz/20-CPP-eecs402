//
//  main.cpp
//  project4
//
//  Created by Zijin Zhang on 11/20/20.
//  Copyright © 2020 Zijin Zhang. All rights reserved.
//

#include <iostream>
#include "LinkedNodeClass.h"
#include "SortedListClass.h"
#include "FIFOQueueClass.h"
#include "LIFOStackClass.h"
using namespace std;

#ifdef ANDREW_TEST
#include "andrewTest.h"
#else
int main(int argc, const char * argv[]) {
    // insert code here...
    SortedListClass testList;
    testList.insertValue(20);
    testList.insertValue(10);
    testList.insertValue(50);
    testList.printForward();

    
    // Test for nums
    cout << "\nnumElems: " << testList.getNumElems() << endl;
    int outVal = 0;
    testList.getElemAtIndex(2, outVal);
    cout << "\noutVal: " << outVal << endl;
    
    // Test for removing
    int theVal = 0;
    bool isFound = testList.removeFront(theVal);
    testList.printBackward();
    cout << "theVal: " << isFound << endl;
    
    testList.removeLast(theVal);
    testList.printBackward();
    cout << "theVal: " << theVal << endl;
    
    // test for copy ctor
    SortedListClass testList2 = SortedListClass(testList);
    testList2.printForward();

    cout << "\nnumElems: " << testList2.getNumElems() << endl;
    int outVal0 = 0;
    testList2.getElemAtIndex(2, outVal0);
    cout << "\noutVal: " << outVal0 << endl;

    int theVal1 = 0;
    testList2.removeLast(theVal1);
    testList2.printForward();


    
    // test for queuq
    FIFOQueueClass testQueue;
    testQueue.enqueue(7);
    testQueue.enqueue(3);
    testQueue.enqueue(5);
    cout << "numElems: " << testQueue.getNumElems() << endl;
    cout << "print the queue: \n";
    testQueue.print();

    int outVal2 = 0;
    testQueue.dequeue(outVal2);
    cout << "print the queue: \n";
    testQueue.print();
    cout << outVal << endl;
    
    //test for the stack
    LIFOStackClass stack;
    stack.push(1);
    stack.push(5);
    stack.push(7);
    cout << "print the stack: " << endl;
    stack.print();
    cout << "numElems: " << stack.getNumElems() << endl;

    int outVal1 = 0;
    stack.pop(outVal1);
    cout << "outVal: " << outVal1 << endl;
    stack.print();
    stack.clear();
    cout << "print the stack: " << endl;
    stack.print();
    
    
    
    return 0;
}
#endif
