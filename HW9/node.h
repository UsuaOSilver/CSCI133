// ======================================================================================================================================
// File: node.h
// ======================================================================================================================================
// Header file for the class node.
// ======================================================================================================================================

#ifndef NODE_HEADER
#define NODE_HEADER

#include <iostream>

// typedefs
typedef std::string ListItemType;

class Node
{
public:
    //CTR
    Node();
    Node(const ListItemType& item);
    Node(const ListItemType& item, Node* nextNodePtr, Node* prevNodePtr);
    
    // member functions
    void SetItem(const ListItemType& item);
    void SetNext(Node* nextNodePtr);
    void SetPrev(Node* prevNodePtr);
    ListItemType GetItem() const;
    Node* GetNext() const;
    Node* GetPrev() const;
    
private:
    ListItemType m_item;
    Node* m_next;
    Node* m_prev;
};

#endif // NODE_HEADER