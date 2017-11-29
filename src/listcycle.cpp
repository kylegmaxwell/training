#include "listcycle.h"

using namespace std;

ListCycle::ListCycle() : UnitTest(false)
{
}

ListCycle::CycleState ListCycle::findCycle(ListNode *n)
{
    unordered_map<ListNode*, char> nodes;
    do {
        auto itr = nodes.find(n);

        if (itr == nodes.end()) // not found
            nodes[n] = n->mData;
        else
            return CYCLE;

        if (mVerbose)
            n->print();

        n = n->mNext;
    } while (n != nullptr);
    return TERMINATES;
}

UnitTest::TestResult ListCycle::test()
{
    ListNode *z = new ListNode('z');
    ListNode *y = new ListNode('y', z);
    ListNode *x = new ListNode('x', y);
    ListNode *w = new ListNode('w', x);

    if (findCycle(w) != TERMINATES)
        return FAIL;

    z->mNext = x;

    if (findCycle(w) != CYCLE)
        return FAIL;

    return PASS;
}

ListNode::ListNode(char iData) : mData(iData), mNext(nullptr)
{
}

ListNode::ListNode(char iData, ListNode *iNext) : mData(iData), mNext(iNext)
{
}

void ListNode::print()
{
    cout << mData << " ";
}

void ListNode::printRecursive()
{
    print();
    if (mNext != nullptr)
        mNext->printRecursive();
}