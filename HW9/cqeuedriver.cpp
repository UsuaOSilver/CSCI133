// ======================================================================================================================================
// File: cqeueDriver.cpp
// ======================================================================================================================================
// Description:
// This program is the driver for the CQeue ADT. It allows the user to remove and insert names in the queue.
// ======================================================================================================================================

#include <iostream>
#include "cqueue.h"
using namespace std;

const int MAX_NAMES = 4;

// ==== main =============================================================================================================================
//
// ======================================================================================================================================
int main() 
{
    CQueue queue;
    string namesToAdd[MAX_NAMES] = {"Thor", "Captain America", "Black Widow", "Hulk"};
    
    // The following steps will display, add, and remove names in the list to test all the functions.
    
    // 1) Display the first element of an empty queue
    cout << "\n1) Display the first element of an empty queue:\n\n ";
    
    try 
    {
        cout << queue.PeekFront() << endl << endl;
    }
    catch (CQueueException &exceptObj)
    {
        cerr << "Error in Function: " << exceptObj.GetFuncName() << endl;
        cerr << "\t Message: " << exceptObj.GetMsg() << endl;
    }
    
    // 2) Dequeue an empty list
    cout << "\n2) Dequeue an empty list:\n\n ";
    
    try
    {
        queue.Dequeue();
    }
    catch (const CQueueException &exceptObj)
    {
        cerr << "Error in Function: " << exceptObj.GetFuncName() << endl;
        cerr << "\t Message: " << exceptObj.GetMsg() << endl;
    }
    
    // 3) Add some names
    cout << "\n3) Adding "<< MAX_NAMES <<" names to fill the queue:\n\n ";
    for (int i = 0; i < MAX_NAMES; i++)
    {
        cout << "Adding " << namesToAdd[i] << "...\n";
        
        queue.Enqueue(namesToAdd[i]);
    }
    
    // 4) Display the next name in the queue
    cout << "\n4) Display the next name in the queue:\n\n ";
    
    try
    {
        cout << queue.PeekFront() << endl << endl;
    }
    catch (CQueueException &exceptObj)
    {
        cerr << "Error in Function: " << exceptObj.GetFuncName() << endl;
        cerr << "\t Message: " << exceptObj.GetMsg() << endl;
    }
    
    // 5) Dequeue the next name (Thor)
    cout << "\n5) Dequeue the next name (Thor):\n\n ";
    
    try
    {
        queue.Dequeue();
    }
    catch (CQueueException &exceptObj)
    {
        cerr << "Error in Function: " << exceptObj.GetFuncName() << endl;
        cerr << "\t Message: " << exceptObj.GetMsg() << endl;
    }
    
    // 6) Display the next name in the queue
    cout << "\n6) Display the next name in the queue:\n\n ";
    
    try
    {
        cout << queue.PeekFront() << endl << endl;
    }
    catch (CQueueException &exceptObj)
    {
        cerr << "Error in Function: " << exceptObj.GetFuncName() << endl;
        cerr << "\t Message: " << exceptObj.GetMsg() << endl;
    }
    
    // 7) Clear the queue
    cout << "\n7) Clearing the queue:\n\n ";
    
    queue.DestroyQueue();
    
    // 8) Display the first element of an empty queue
    cout << "\n8) Display the first element of an empty queue:\n\n ";
    
    try
    {
        cout << queue.PeekFront() << endl << endl;
    }
    catch (CQueueException &exceptObj)
    {
        cerr << "Error in Function: " << exceptObj.GetFuncName() << endl;
        cerr << "\t Message: " << exceptObj.GetMsg() << endl;
    }
    
    cout << endl;
    
    return 0;
} // end main