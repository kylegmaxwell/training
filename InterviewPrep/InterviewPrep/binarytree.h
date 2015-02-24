#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

#include "unittest.h"

class BinaryNode {

public:
    BinaryNode(int iData);

    BinaryNode(int iData, BinaryNode *iLeft, BinaryNode *iRight);

    int mData;
    BinaryNode *mLeft;
    BinaryNode *mRight;
};

class BinaryTree : public UnitTest
{
public:
    BinaryTree();

    BinaryNode *buildUnbalancedTree();
    BinaryNode *buildBalancedTree();

    bool isBalanced(BinaryNode *node);
    bool isBalancedHelper(BinaryNode *node, int &depth);

    virtual TestResult test();
};

#endif // BINARYTREE_H
