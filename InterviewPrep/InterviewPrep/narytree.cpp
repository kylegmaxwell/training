#include "narytree.h"

using namespace std;

NaryTree::NaryTree()
{
}

bool NaryTree::test()
{
    string expectedResult = "A B C D E F G \n";
    Tree tree;
    tree.buildTree();

    stringstream ss;
    tree.print(ss);

    string result = ss.str();
    return result.compare(expectedResult)==0;
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
    Node *g = new Node('G');
    Node *d = new Node('D');
    d->addChild(g);

    Node *f = new Node('F');
    Node *e = new Node('E');
    Node *c = new Node('C');
    c->addChild(e);
    c->addChild(f);

    Node *b = new Node('B');

    Node *a = new Node('A');

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

Node::Node(char iData)
{
    mData = iData;
}

void Node::print(iostream &stream)
{
    // base case
    if (mChildren.size()==0)
        return;

    // print children
    for (auto itr = mChildren.begin(); itr != mChildren.end(); itr++) {
        Node *node = *itr;
        node->printData(stream);
    }

    // call children
    for (auto itr = mChildren.begin(); itr != mChildren.end(); itr++) {
        Node *node = *itr;
        node->print(stream);
    }
}

void Node::printData(iostream &stream)
{
    stream << mData << " ";
}

char Node::getData()
{
    return mData;
}

void Node::addChild(Node *node)
{
    mChildren.push_back(node);
}
