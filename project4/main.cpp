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

int main(int argc, const char * argv[]) {
    // insert code here...
//    SortedListClass testList;
    //testList.printForward();
//    testList.insertValue(20);
//    testList.insertValue(10);
//    testList.insertValue(50);
//    testList.printForward();
//    testList.clear();
//    testList.printBackward();
    
    /* Test for nums
    cout << "\nnumElems: " << testList.getNumElems() << endl;
    int outVal = 0;
    testList.getElemAtIndex(2, outVal);
    cout << "\noutVal: " << outVal << endl;
     */
    
    /* Test for removing
    int theVal = 0;
//    testList.removeFront(theVal);
//    testList.printForward();
//    cout << "theVal: " << theVal << endl;
    
    testList.removeLast(theVal);
    testList.printForward();
    cout << "theVal: " << theVal << endl;
     */
    
    
    /*
     Test for copy ctor
    SortedListClass testList2 = SortedListClass(testList);
    testList2.printForward();
    
    cout << "\nnumElems: " << testList2.getNumElems() << endl;
    int outVal = 0;
    testList2.getElemAtIndex(0, outVal);
    cout << "\noutVal: " << outVal << endl;
    
    int theVal = 0;
    testList2.removeLast(theVal);
    testList2.removeFront(theVal);
    testList2.printForward();
     */
    
    
//    FIFOQueueClass testQueue;
//    testQueue.enqueue(7);
//    testQueue.enqueue(3);
//    testQueue.enqueue(5);
//    cout << "numElems: " << testQueue.getNumElems() << endl;
//    cout << "print the queue: \n";
//    testQueue.print();
//
//    int outVal = 0;
//    cout << "print the queue: \n";
//    testQueue.dequeue(outVal);
//    testQueue.dequeue(outVal);
//    testQueue.print();
//    cout << outVal << endl;
    
    LIFOStackClass stack;
    stack.push(1);
//    stack.push(5);
//    stack.push(7);
    stack.print();
    cout << stack.getNumElems() << endl;
    
    int outVal = 0;
    stack.pop(outVal);
//    cout << outVal << endl;
    stack.print();
    
    
    stack.clear();
    stack.print();
    
    
    
    
    

    

    
    return 0;
}
