#include "narytree.h"

using namespace std;

NaryTree::NaryTree()
{
}

UnitTest::TestResult NaryTree::test()
{
    string expectedResult = "A B C D E F G \n";
    Tree tree;
    tree.buildTree();

    stringstream ss;
    tree.print(ss);

    string result = ss.str();
    if (result.compare(expectedResult)==0)
        return PASS;
    else
        return FAIL;
}

/* Structure
 *
 *         A
 * -----------------
 * |      |        |
 * B      C        D
 *     ------      |
 *     |    |      G
 *     E    F
 *
*/
Tree::Tree()
{

}

void Tree::buildTree()
{
    TreeNode *g = new TreeNode('G');
    TreeNode *d = new TreeNode('D');
    d->addChild(g);

    TreeNode *f = new TreeNode('F');
    TreeNode *e = new TreeNode('E');
    TreeNode *c = new TreeNode('C');
    c->addChild(e);
    c->addChild(f);

    TreeNode *b = new TreeNode('B');

    TreeNode *a = new TreeNode('A');

    a->addChild(b);
    a->addChild(c);
    a->addChild(d);

    mRootNode = a;
}

void Tree::print(iostream &stream)
{
    mRootNode->printData(stream);
    mRootNode->print(stream);
    stream << endl;
}

TreeNode::TreeNode(char iData)
{
    mData = iData;
}

void TreeNode::print(iostream &stream)
{
    // base case
    if (mChildren.size()==0)
        return;

    // print children
    for (auto itr = mChildren.begin(); itr != mChildren.end(); itr++) {
        TreeNode *node = *itr;
        node->printData(stream);
    }

    // call children
    for (auto itr = mChildren.begin(); itr != mChildren.end(); itr++) {
        TreeNode *node = *itr;
        node->print(stream);
    }
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
