#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <memory>

#include "unittest.h"

class BinaryNode {

public:

    typedef std::shared_ptr<BinaryNode> Ptr;

    BinaryNode(int iData);

    BinaryNode(int iData, BinaryNode *iLeft, BinaryNode *iRight);

    virtual ~BinaryNode();

    int mData;
    Ptr mLeft;
    Ptr mRight;
};

typedef BinaryNode::Ptr BinaryNodePtr;

class BinaryTree : public UnitTest
{
public:
    BinaryTree();

    BinaryNodePtr buildUnbalancedTree();
    BinaryNodePtr buildBalancedTree();

    bool isBalanced(BinaryNodePtr node);
    bool isBalancedHelper(BinaryNodePtr node, int &depth);

    virtual TestResult test();
};

#endif // BINARYTREE_H
