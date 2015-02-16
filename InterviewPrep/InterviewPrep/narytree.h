#ifndef NARYTREE_H
#define NARYTREE_H

#include "unittest.h"

#include <iostream>
#include <vector>
#include <sstream>

class Node
{
public:

    Node(char iData);

    // recursive print
    void print(std::iostream &stream);

    // just print data
    void printData(std::iostream &stream);

    char getData();

    void addChild(Node *node);

private:
    char mData;

    std::vector<Node*> mChildren;
};

class Tree
{
public:
    Tree();

    Node *mRootNode;

    void buildTree();

    void print(std::iostream &stream);
};


class NaryTree : public UnitTest
{
public:
    NaryTree();

    virtual bool test();

private:


};

#endif // NARYTREE_H
