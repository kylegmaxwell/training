#include "binarytree.h"
#include <stack>
#include <utility> // pair
#include <math.h>

using namespace std;

BinaryTree::BinaryTree() : UnitTest(true)
{}

BinaryNode *BinaryTree::buildBalancedTree()
{
    BinaryNode *b = new BinaryNode(2);
    BinaryNode *c = new BinaryNode(3);
    BinaryNode *d = new BinaryNode(4);
    BinaryNode *e = new BinaryNode(5);
    BinaryNode *f = new BinaryNode(6);
    BinaryNode *g = new BinaryNode(7);
    BinaryNode *h = new BinaryNode(8);
    BinaryNode *i = new BinaryNode(9);
    BinaryNode *j = new BinaryNode(10);

    b->mLeft = c;
    b->mRight = h;
    c->mLeft = d;
    c->mRight = g;
    d->mLeft = e;
    d->mRight = f;
    h->mLeft = i;
    h->mRight = j;

    return b;
}

BinaryNode *BinaryTree::buildUnbalancedTree()
{
    // TODO try using shared_ptr for memory management
    //BinaryNode *root = nullptr;
    BinaryNode *b = new BinaryNode(6);
    BinaryNode *c = new BinaryNode(271);
    BinaryNode *d = new BinaryNode(28);
    BinaryNode *e = new BinaryNode(0);
    BinaryNode *f = new BinaryNode(561);
    BinaryNode *g = new BinaryNode(3);
    BinaryNode *h = new BinaryNode(17);

    b->mLeft = c;
    b->mRight = f;
    c->mLeft = d;
    c->mRight = e;
    f->mRight = g;
    g->mLeft = h;

    return b;
}

bool BinaryTree::isBalanced(BinaryNode *node)
{
    int d = 0;
    if (node != nullptr)
        return isBalancedHelper(node, d);
    else
        return false;
}

bool BinaryTree::isBalancedHelper(BinaryNode *node, int &depth)
{
    int leftDepth = depth;
    int rightDepth = depth;
    if (node->mLeft != nullptr) {
        leftDepth++;
        if (!isBalancedHelper(node->mLeft, leftDepth))
            return false; // return as early as possible to save computation
    }

    if (node->mRight != nullptr) {
        rightDepth++;
        if (!isBalancedHelper(node->mRight, rightDepth))
            return false;
    }

    depth = max<int>(leftDepth, rightDepth);

    if (abs(leftDepth - rightDepth) > 1)
        return false;

    return true;
}

UnitTest::TestResult BinaryTree::test()
{
    BinaryNode *treeGood = buildBalancedTree();

    if (!isBalanced(treeGood))
        return FAIL;

    BinaryNode *treeBad = buildUnbalancedTree();
    if (isBalanced(treeBad))
        return FAIL;

    return PASS;
}


BinaryNode::BinaryNode(int iData)
    : mData(iData), mLeft(nullptr), mRight(nullptr)
{}

BinaryNode::BinaryNode(int iData, BinaryNode *iLeft, BinaryNode *iRight)
    : mData(iData), mLeft(iLeft), mRight(iRight)
{}
