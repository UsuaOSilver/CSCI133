// ======================================================================================================================================
// File: clinkedlist.cpp
// ======================================================================================================================================
// This is an implementation file for a doubly list ADT CLinkedList. This implementation uses nodes to store 
// a list of type ListItemType (ints) items.
// ======================================================================================================================================

#include <iostream>
#include "clinkedlist.h"
using namespace std;

// ==== CLinkedList::CLinkedList (default) ==============================================================================================
//
// This is the default constructor that sets the head pointer to nullpot
//
// ======================================================================================================================================
CLinkedList::CLinkedList()
{
    headPtr = nullptr;
}

// ==== CLinkedList::~CLinkedList ======================================================================================================
//
// This is the destructor, which releases all the nodes.
//
// ======================================================================================================================================
CLinkedList::~CLinkedList()
{
    DestroyList();
}

// ==== CLinkedList::DestroyList ======================================================================================================
//
// This function releases (frees) all the nodes in the list and sets headPtr to nullPtr.
//
// Input: void
// Output: A boolean value of success or failure
//
// ======================================================================================================================================
bool CLinkedList::DestroyList()
{
    Node* p = headPtr;
    Node* n;
    
    while (p != nullptr)
    {
        n = p->GetNext();
        
        delete p;
        
        p = n;
    }
    
    headPtr = nullptr;
    
    return true;
}

// ==== CLinkedList::GetItem ===========================================================================================================
//
// This function retrieves the value of an item at a particular location (particular node).  
//
// The function throws error codes from the class CLinkedListException.
//      Ex: "CLinkedList::GetItem" Message: "Empty"
//
//
// Input: 
//      index - The index location for the target item (zero-based)
//      item - A reference to a ListItemType obj. This argument will contain the desired item after the function completes.
//
// Output: 
//      A boolean value 
//
// ======================================================================================================================================
bool CLinkedList::GetItem(int index, ListItemType& item) const throw (CLinkedListException)
{
    if (IsEmpty())
    {
        throw CLinkedListException("CLinkedList::GetItem", "Empty");
    }
    
    if (Contains(item) && GetCurrentSize() > index)
    {
        Node *p = headPtr;
        int count = 0;
        
        while(p->GetNext() != nullptr)
        {
            if ((p->GetItem() == item) && (count == index))
            {
                return true;
            }
        }
        p = p->GetNext();
        
        count++;
    }
    return false;
}

// ==== CLinkedList::Contains ========================================================================================================
//
// This function checks if an item exists in the list.
//
// Input:
//      newItem - a const reference to item to be checked
//
// Output:
//      A boolean value
//
// ======================================================================================================================================
bool CLinkedList::Contains(const ListItemType& newItem) const
{
    Node* p = headPtr;
    
    while (p->GetNext() != nullptr)
    {
        if (p->GetNext()->GetItem() == newItem)
        {
            return true;
        }
        p = p->GetNext();
    }
    return false;
}


// ==== CLinkedList::GetCurrentSize ==================================================================================================
//
// This function returns the num items in the list.
//
// Input:
//      void
//
// Output:
//      An int value
//
// ======================================================================================================================================
int CLinkedList::GetCurrentSize() const
{
    Node* p = headPtr;
    int count = 0;
    
    while (p != nullptr)
    {
        count++;
        
        p = p->GetNext();
    }
    return count;
}


// ==== CLinkedList::Add =============================================================================================================
//
// This function inserts an item to the end of the list.
//
// Input:
//      newItem - a const reference to item to be inserted
//
// Output:
//      A boolean value
//
// ======================================================================================================================================
bool CLinkedList::Add(const ListItemType& newItem)
{
    Node* n = new Node;
    
    n->SetItem(newItem);
    n->SetNext(nullptr);
    n->GetPrev();
    
    tailPtr = n;
    
    return true;
}


// ==== CLinkedList::IsEmpty =========================================================================================================
//
// This function returns a boolean if the list is empty.
//
// Input:
//      void
//
// Output:
//      A boolean value. True if the list is empty, false otherwise.
//
// ======================================================================================================================================
bool CLinkedList::IsEmpty() const
{
    return (headPtr == nullptr && tailPtr == nullptr);
}


// ==== CLinkedList::Remove =========================================================================================================
//
// This function removes an item from the list.
//
// This function throws error codes from the class CLinkedListException.
//      Ex: "CLinkedList::Remove" Message: "Empty"
//
// Input:
//      value - a const reference to item to be removed
//
// Output:
//      A boolean value of success or failure.
//
// ======================================================================================================================================
bool CLinkedList::Remove(const ListItemType& value) throw (CLinkedListException)
{
    if (IsEmpty())
    {
        throw CLinkedListException("CLinkedList::Remove", "Empty");
    }
    
    // Deleting front Node
    if(headPtr->GetItem() == value)
    {
        Node* targetNode = headPtr;
        
        // Special case: one node in list
        if(headPtr == tailPtr)
        {
            headPtr = nullptr;
            tailPtr = nullptr;
        }
        else
        {
            headPtr = headPtr->GetNext();
            targetNode->GetNext()->SetPrev(nullptr);
            targetNode->SetNext(nullptr);
        
            delete targetNode;
            targetNode = nullptr;
            
            return true;
        }
    }
    
    // Deleting interior or last node
    Node* before = headPtr;
    
    while(before->GetNext() != nullptr)
    {
        if(before->GetNext()->GetItem() == value) {break;}
        
        before = before->GetNext();
    }
    if(before != nullptr)
    {
        Node* targetNode = before->GetNext();
        
        before->SetNext(targetNode->GetNext());
        targetNode->GetNext()->SetPrev(targetNode->GetPrev());
        
        if(targetNode->GetNext() == nullptr)
        {
            tailPtr = before;
        }
        
        delete targetNode;
        
        return true;
    }
    return false;
}


// ==== CLinkedList::Clear ==========================================================================================================
//
// This function clears the list.
//
// Input:
//      void
//
// Output:
//      A boolean value of success or failure.
//
// ======================================================================================================================================
bool CLinkedList::Clear()
{
    Node* p = headPtr;

    if(!IsEmpty())
    {    
        while (p != nullptr)
        {
            p->SetItem(0);
            
            p->GetNext();
        }
        return true;
    }
    return false;
}



// ==== CLinkedList::DisplayListAscending ==================================================================================================
//
// This function displays the list in ascending order using the headPtr.
//
// Input:
//      void
//
// Output:
//      void
//
// ======================================================================================================================================
void CLinkedList::DisplayListAscending() 
{
    
    if(IsEmpty())
    {
        cout << "List is empty." << endl;
    }
    
    Node* p = headPtr;
    
    cout << "Display list in ascending order: " << endl;
    while (p->GetNext() != nullptr)
    {
        cout << p->GetItem() << " " << endl;
    }
}



//==== CLinkedList::DisplayListDescending =================================================================================================
//
// This function displays the list in descending order using the tailPtr.
//
// Input:
//      void
//
// Output:
//      void
// ======================================================================================================================================
void CLinkedList::DisplayListDescending() 
{
    if(IsEmpty())
    {
        cout << "List is empty." << endl;
    }
    
    Node* p = tailPtr;
    
    cout << "Display list in descending order: " << endl;
    while (p->GetPrev() != nullptr)
    {
        cout << p->GetItem() << " " << endl;
    }
}
