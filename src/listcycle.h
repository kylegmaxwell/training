#pragma once

#include "unittest.h"

#include <iostream>
#include <unordered_map>

/*!
 * \brief The ListNode class represents a node in a linked list
 */
class ListNode
{
public:

    ListNode(char iData);
    ListNode(char iData, ListNode *iNext);

    // print my data
    void print();

    // recursive print my data and children (later elements on list)
    void printRecursive();

    char mData;
    ListNode *mNext;
};

/*!
 * \brief The ListCycle class creates linked lists and tests for cycles
 */
class ListCycle : public UnitTest
{
public:
    enum class CycleState { CYCLE, TERMINATES };

    //! Check the list for cycles, which cause problems with iteration
    CycleState findCycle(ListNode *n);

    virtual TestResult test() override;
};
