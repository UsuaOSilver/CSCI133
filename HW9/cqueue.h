// ======================================================================================================================================
// File: cqueue.h
// ======================================================================================================================================
// Header file for the CQueue class.
// ======================================================================================================================================

#ifndef CQUEUE_HEADER
#define CQUEUE_HEADER

#include <iostream>
#include "clinkedlist.h"

// type definitions
typedef ListItemType QueueItemType; // ListItemType is defined in clinkedlist.h

// exception class for CQueue
class CQueueException
{
public:
    //CTR
    CQueueException(std::string funcName, std::string msg) : m_msg(msg), m_funcName(funcName)
    {
    }
    
    // member functions
    std::string GetMsg() const {return m_msg;}
    std::string GetFuncName() const {return m_funcName;}
    
private:
    std::string m_msg;
    std::string m_funcName;
};

// make our own CQueue class as oppose to the prebuilt STL
class CQueue
{
public:
    //CTR & DTR
    
    /* compiler generated default constructor/destructor will be enough */
    
    // member functions
    bool IsEmpty() const;
    bool Enqueue(const QueueItemType& newItem);
    bool Dequeue(QueueItemType& item);
    void DestroyQueue();
    QueueItemType PeekFront() const throw (CQueueException);
    
private:
    // data members
    CLinkedList m_qlist;
};

#endif // CQUEUE_HEADER