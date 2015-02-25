#include "binarytree.h"
#include <stack>
#include <utility> // pair
#include <math.h>

using namespace std;

BinaryTree::BinaryTree() : UnitTest(true)
{}

BinaryNodePtr BinaryTree::buildBalancedTree()
{
    BinaryNodePtr b(new BinaryNode(2));
    BinaryNodePtr c(new BinaryNode(3));
    BinaryNodePtr d(new BinaryNode(4));
    BinaryNodePtr e(new BinaryNode(5));
    BinaryNodePtr f(new BinaryNode(6));
    BinaryNodePtr g(new BinaryNode(7));
    BinaryNodePtr h(new BinaryNode(8));
    BinaryNodePtr i(new BinaryNode(9));
    BinaryNodePtr j(new BinaryNode(10));

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

BinaryNodePtr BinaryTree::buildUnbalancedTree()
{
    BinaryNodePtr b(new BinaryNode(6));
    BinaryNodePtr c(new BinaryNode(271));
    BinaryNodePtr d(new BinaryNode(28));
    BinaryNodePtr e(new BinaryNode(0));
    BinaryNodePtr f(new BinaryNode(561));
    BinaryNodePtr g(new BinaryNode(3));
    BinaryNodePtr h(new BinaryNode(17));

    b->mLeft = c;
    b->mRight = f;
    c->mLeft = d;
    c->mRight = e;
    f->mRight = g;
    g->mLeft = h;

    return b;
}

bool BinaryTree::isBalanced(BinaryNodePtr node)
{
    int d = 0;
    if (node)
        return isBalancedHelper(node, d);
    else
        return false;
}

bool BinaryTree::isBalancedHelper(BinaryNodePtr node, int &depth)
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
    BinaryNodePtr treeGood = buildBalancedTree();

    if (!isBalanced(treeGood))
        return FAIL;

    BinaryNodePtr treeBad = buildUnbalancedTree();
    if (isBalanced(treeBad))
        return FAIL;

    return PASS;
}


BinaryNode::BinaryNode(int iData)
    : mData(iData), mLeft(nullptr), mRight(nullptr)
{
}

BinaryNode::BinaryNode(int iData, BinaryNode *iLeft, BinaryNode *iRight)
    : mData(iData), mLeft(iLeft), mRight(iRight)
{
}

BinaryNode::~BinaryNode()
{
}
