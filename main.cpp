#include <iostream>
#include <vector>
#include <memory>

#include "src/unittest.h"
#include "src/computeparity.h"
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
#include "src/logger.h"

using namespace std;

/*!
 * Main entry point for code.
 * Executes all tests.
 */
int main(int argc, char *argv[])
{
    // Initialize as array since initializer_list must copy, but unique_ptr can only move
    unique_ptr<UnitTest> testList[] = {
        make_unique<Queens>(),
        make_unique<DynamicProgramming>(),
        make_unique<ComputeParity>(),
        make_unique<NaryTree>(),
        make_unique<ConvertBase>(),
        make_unique<ListCycle>(),
        make_unique<PairSum>(),
        make_unique<MaxStack>(),
        make_unique<BinaryTree>(),
        make_unique<HeapMerge>(),
        make_unique<BinarySearch>(),
        make_unique<HashLetter>(),
        make_unique<PowerSet>(),
        make_unique<Sorting>(),
        make_unique<Move>()
    };

    // Convert array to vector
    vector<unique_ptr<UnitTest>> tests{
        make_move_iterator(begin(testList)),
        make_move_iterator(end(testList))
    };

    // Run Tests
    return TestSuite::test(tests);
}