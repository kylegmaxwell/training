#include <QCoreApplication>
#include <iostream>

#include "computeparity.h"
#include "unittest.h"
#include "testsuite.h"
#include "narytree.h"
#include "convertbase.h"
#include "queens.h"
#include "listcycle.h"
#include "pairsum.h"
#include "maxstack.h"
#include "binarytree.h"
#include "heapmerge.h"
#include "binarysearch.h"
#include "hashletter.h"

using namespace std;

int main(int argc, char *argv[])
{
    // Initialize test suite
    TestSuite tests;

    // Test 1
    ComputeParity parity;
    tests.addTest(&parity);

    // Test 2
    NaryTree tree;
    tests.addTest(&tree);

    // Test 3
    ConvertBase base;
    tests.addTest(&base);

    // Test 4
    Queens queens;
    tests.addTest(&queens);

    // Test 5
    ListCycle cycle;
    tests.addTest(&cycle);

    // Test 6
    PairSum pair;
    tests.addTest(&pair);

    // Test 7
    MaxStack stack;
    tests.addTest(&stack);

    // Test 8
    BinaryTree binary;
    tests.addTest(&binary);

    // Test 9
    HeapMerge heap;
    tests.addTest(&heap);

    // Test 10
    BinarySearch search;
    tests.addTest(&search);

    // Test 10
    HashLetter hash;
    tests.addTest(&hash);

    // Run Tests
    tests.test();

    QCoreApplication a(argc, argv);

    return a.exec();
}
