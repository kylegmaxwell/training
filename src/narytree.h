#pragma once

#include "unittest.h"

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

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

    std::vector<TreeNode*> mChildren;

private:

    char mData;
};

class NaryTree : public UnitTest
{
public:
    NaryTree();

    virtual TestResult test();

private:
    TreeNode *mRootNode;

    void buildTree();

    /*!
     * \brief printBFS Print in Breadth First Search order using a queue
     * \param stream Output buffer for text
     */
    void printBFS(std::iostream &stream);

    /*!
     * \brief printDFS Print in Depth First Search order using a stack
     * \param stream Output buffer for text
     */
    void printDFS(std::iostream &stream);

    /*!
     * \brief printDFSRecursive Print in Depth First Search order using recursion
     * \param stream Output buffer for text
     */
    void printDFSRecursive(std::iostream &stream);
    void printDFSHelper(std::iostream &stream, TreeNode *n);

    //void printBroken(std::iostream &stream);
};
