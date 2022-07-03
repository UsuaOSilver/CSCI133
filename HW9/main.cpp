// ======================================================================================================================================
// File: main.cpp
// ======================================================================================================================================
// Description:
// This program works with the ADT CLinkedList. It allows the user to remove and insert names (nodes) in the list.
// Items in this example are names of people.
// ======================================================================================================================================

#include <iostream>
#include "clinkedlist.h"
using namespace std;

// global const
const int MAX_NAMES = 4;

// ==== main =============================================================================================================================
//
// ======================================================================================================================================
int main()
{
    CLinkedList list;
    string      namesToAdd[MAX_NAMES] = {"Thor", "Captain America", "Black Widow", "Hulk"};
    
    // The following steps will display, add, and remove names in the list to test all the functions.
    
    // 1) Display an empty list
    cout << "\n1) Display the number of names and an empty list:\n\n ";
    cout << "Number of names: " << list.GetCurrentSize() << endl;
    list.DisplayListAscending();
    
    // 2) Clear an empty list
    cout << "\n2) Clearing an empty list:\n\n ";
    if (!list.Clear())
    {
        cerr << "\nError in clearing list!\n\n";
    }
    
    // 3) Add some names 
    cout << "\n3) Adding "<< MAX_NAMES <<" names to fill the list:\n\n ";
    for (int i = 0; i < MAX_NAMES; i++)
    {
        cout << "Adding " << namesToAdd[i] << "...\n";
        
        if (!list.Add(namesToAdd[i]))
        {
            cerr << "\nError in adding " << namesToAdd[i] << "to the list!\n\n";
        }
    }
    
    // 4) Display the current list in ascending and descending based on the order they were entered.
    cout << "\n4) Display the number of names, an ascending and descending "
         << "list based on the order they were entered:\n\n ";
    cout << "Number of names: " << list.GetCurrentSize() << endl << endl;
    list.DisplayListAscending();
    cout << endl << endl;
    list.DisplayListDescending();
    
    // 5) Delete the first name (Thor)
    cout << "\n5) Delete first name (Thor):\n\n ";
    
    try
    {
        list.Remove("Thor");
    }
    catch(CLinkedListException &exceptObj)
    {
        cerr << "Error in Function: " << exceptObj.GetFuncName() << endl;
        cerr << "\tMessage: " << exceptObj.GetMsg() << endl;
    }
   
   // 6) Display list
   cout << "\n6) Displaying list:\n\n ";
    list.DisplayListAscending();
    
    // 7) Delete the middle name (Black Widow)
    cout << "\n7) Delete middle name (Black Widow):\n\n ";
    
    try
    {
        list.Remove("Black Widow");
    }
    catch(CLinkedListException &exceptObj)
    {
        cerr << "Error in Function: " << exceptObj.GetFuncName() << endl;
        cerr << "\tMessage: " << exceptObj.GetMsg() << endl;
    }
    
    // 8) Display list
    cout << "\n8) Displaying list:\n\n ";
    list.DisplayListAscending();
    
    // 9) Delete the last name (Hulk)
    cout << "\n9) Delete last name (Hulk):\n\n ";
    
    try
    {
        list.Remove("Hulk");
    }
    catch(CLinkedListException &exceptObj)
    {
        cerr << "Error in Function: " << exceptObj.GetFuncName() << endl;
        cerr << "\tMessage: " << exceptObj.GetMsg() << endl;
    }
    
    // 10) Display list
    cout << "\n10) Displaying list:\n\n ";
    list.DisplayListAscending();
    
    // 11) Check if "Ironman" exists in the list
    cout << "\n11) Check if \"Ironman\" exists in the list:\n\n ";
    if (list.Contains("Ironman"))
    {
        cerr << "\"Ironman\" does not exist in the list.\n\n";
    }
    
    // 12) Delete name "Ironman", which is not in the list
    cout << "\n12) Delete name \"Ironman\", which is not in the list:\n\n ";
    
    try
    {
        list.Remove("Ironman");
    }
    catch(CLinkedListException &exceptObj)
    {
        cerr << "Error in Function: " << exceptObj.GetFuncName() << endl;
        cerr << "\tMessage: " << exceptObj.GetMsg() << endl;
    }
    
    // 13) Clear the list
    cout << "\n13) Clearing the list:\n\n ";
    if (!list.Clear())
    {
        cerr << "\nError in clearing list!\n\n";
    }
    
}