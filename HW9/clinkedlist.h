// ======================================================================================================================================
// File: clinkedlist.h
// ======================================================================================================================================
// Header file for the class CLinkedList (doubly linked).
// ======================================================================================================================================

#ifndef CLinkedLIST_HEADER
#define CLinkedLIST_HEADER

#include <iostream>
#include "node.h"

// exception class for CLinkedList
class CLinkedListException
{
public:
    //CTR
    CLinkedListException(std::string funcName, std::string msg) : m_msg(msg), m_funcName(funcName)
    {
    }
    
    // member functions
    std::string GetMsg() const {return m_msg;}
    std::string GetFuncName() const {return m_funcName;}
    
private:
    std::string m_msg;
    std::string m_funcName;
};

// CLinkedList 
class CLinkedList
{
public:
    //CTR & DTR
    CLinkedList();
    ~CLinkedList();
    
    // member functions
    bool DestroyList();
    bool GetItem(int index, ListItemType& item) const throw (CLinkedListException);
    int GetCurrentSize() const;
    bool Add(const ListItemType& newItem);
    bool IsEmpty() const;
    bool Remove(const ListItemType& value) throw (CLinkedListException);
    bool Clear();
    bool Contains(const ListItemType& item) const;
    void DisplayListAscending();
    void DisplayListDescending();
    
private:
    // data members
    Node* headPtr;
    Node* tailPtr;
};

#endif // CLinkedLIST_HEADER