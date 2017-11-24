#include <iostream>

#include "src/computeparity.h"
#include "src/unittest.h"
#include "src/testsuite.h"
#include "src/narytree.h"
#include "src/convertbase.h"
#include "src/queens.h"
#include "src/listcycle.h"
#include "src/pairsum.h"
#include "src/maxstack.h"
#include "src/binarytree.h"
#include "src/binarysearch.h"
#include "src/hashletter.h"
#include "src/dynamicprogramming.h"
#include "src/sorting.h"
#include "src/heapmerge.h"
#include "src/powerset.h"
#include "src/move.h"

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
