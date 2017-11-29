#include <unordered_map>

#include "narytree.h"

using namespace std;

NaryTree::NaryTree() : UnitTest(false)
{
}

UnitTest::TestResult NaryTree::test()
{
    buildTree();

    // Breadth First Search
    {
        string expectedResult = "A B C D E F G H I J K L M N ";
        stringstream ss;
        printBFS(ss);

        string result = ss.str();
        if (mVerbose) {
            cout << result << endl;
        }
        if (!stringEqual(result, expectedResult))
            return FAIL;
    }

    // Depth First Search
    {
        string expectedResult = "A B E K F G C H I L M D J N ";
        stringstream ss;
        printDFS(ss);

        string result = ss.str();
        if (mVerbose) {
            cout << result << endl;
        }
        if (!stringEqual(result, expectedResult))
            return FAIL;
    }

    // Depth First Search Recursive
    {
        string expectedResult = "A B E K F G C H I L M D J N ";
        stringstream ss;
        printDFSRecursive(ss);

        string result = ss.str();
        if (mVerbose) {
            cout << result << endl;
        }
        if (!stringEqual(result, expectedResult))
            return FAIL;
    }

    return PASS;
}

/* Structure
 *
 *             A
 *    -------------------
 *    |        |        |
 *    B        C        D
 *  ----    ------      |
 *  | | |  |      |     |
 *  E F G  H      I     J
 *  |           ----    |
 *  |           |  |    |
 *  K           L  M    N
 *
*/
void NaryTree::buildTree()
{
    unordered_map<char, TreeNode*> nodeMap;

    for (char c = 'A'; c <= 'N'; c++) {
        nodeMap[c] = new TreeNode(c);
    }

    TreeNode *a = nodeMap['A'];
    a->addChild(nodeMap['B']);
    a->addChild(nodeMap['C']);
    a->addChild(nodeMap['D']);

    TreeNode *b = nodeMap['B'];
    b->addChild(nodeMap['E']);
    b->addChild(nodeMap['F']);
    b->addChild(nodeMap['G']);

    TreeNode *e = nodeMap['E'];
    e->addChild(nodeMap['K']);

    TreeNode *c = nodeMap['C'];
    c->addChild(nodeMap['H']);
    c->addChild(nodeMap['I']);

    TreeNode *i = nodeMap['I'];
    i->addChild(nodeMap['L']);
    i->addChild(nodeMap['M']);

    TreeNode *d = nodeMap['D'];
    d->addChild(nodeMap['J']);

    TreeNode *j = nodeMap['J'];
    j->addChild(nodeMap['N']);

    mRootNode = nodeMap['A'];
}

void NaryTree::printBFS(iostream &stream)
{
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(mRootNode);

    while (!nodeQueue.empty()) {
        // get the next element and pop it
        TreeNode *n = nodeQueue.front();
        nodeQueue.pop();

        // add children to queue
        for (auto itr = n->mChildren.begin(); itr != n->mChildren.end(); itr++)
            nodeQueue.push(*itr);

        stream << n->getData() << " ";
    }
}

void NaryTree::printDFS(iostream &stream)
{
    stack<TreeNode*> nodeStack;
    nodeStack.push(mRootNode);

    while (!nodeStack.empty()) {
        // get the next element and pop it
        TreeNode *n = nodeStack.top();
        nodeStack.pop();

        stream << n->getData() << " ";

        // add children to queue in reverse order
        for (auto itr = n->mChildren.rbegin(); itr != n->mChildren.rend(); itr++)
            nodeStack.push(*itr);
    }
}

void NaryTree::printDFSRecursive(iostream &stream)
{
    printDFSHelper(stream, mRootNode);
}

void NaryTree::printDFSHelper(iostream &stream, TreeNode *n)
{
    stream << n->getData() << " ";

    for (auto itr = n->mChildren.begin(); itr != n->mChildren.end(); itr++) {
        TreeNode *c = *itr;
        printDFSHelper(stream, c);
    }
}

TreeNode::TreeNode(char iData)
{
    mData = iData;
}

void TreeNode::printData(iostream &stream)
{
    stream << mData << " ";
}

char TreeNode::getData()
{
    return mData;
}

void TreeNode::addChild(TreeNode *node)
{
    mChildren.push_back(node);
}