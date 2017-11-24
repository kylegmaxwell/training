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
#include "binarysearch.h"
#include "hashletter.h"
#include "dynamicprogramming.h"
#include "sorting.h"
#include "heapmerge.h"
#include "powerset.h"
#include "move.h"

using namespace std;

/*!
 * Main entry point for code.
 * Executes all tests.
 */
int main(int argc, char *argv[])
{
    bool verbose = false;

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
    Queens queens(verbose);
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

    // Test 11
    HashLetter hash;
    tests.addTest(&hash);

    // Test 12
    PowerSet set;
    tests.addTest(&set);

    // Test 13
    DynamicProgramming dyno;
    tests.addTest(&dyno);

    // Test 14
    Sorting sorting;
    tests.addTest(&sorting);

    Move move;
    tests.addTest(&move);

    // Run Tests
    int status = tests.test();
    
    return status;
}
