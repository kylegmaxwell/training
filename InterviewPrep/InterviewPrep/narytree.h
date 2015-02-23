#ifndef NARYTREE_H
#define NARYTREE_H

#include "unittest.h"

#include <iostream>
#include <vector>
#include <sstream>

class TreeNode
{
public:

    TreeNode(char iData);

    // recursive print
    void print(std::iostream &stream);

    // just print data
    void printData(std::iostream &stream);

    char getData();

    void addChild(TreeNode *node);

private:
    char mData;

    std::vector<TreeNode*> mChildren;
};

class Tree
{
public:
    Tree();

    TreeNode *mRootNode;

    void buildTree();

    void print(std::iostream &stream);
};


class NaryTree : public UnitTest
{
public:
    NaryTree();

    virtual TestResult test();

private:


};

#endif // NARYTREE_H
