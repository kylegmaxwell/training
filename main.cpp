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
    // Initialize test suite
    vector<shared_ptr<UnitTest>> tests = {
        make_shared<Queens>(),
        make_shared<DynamicProgramming>(),
        make_shared<ComputeParity>(),
        make_shared<NaryTree>(),
        make_shared<ConvertBase>(),
        make_shared<ListCycle>(),
        make_shared<PairSum>(),
        make_shared<MaxStack>(),
        make_shared<BinaryTree>(),
        make_shared<HeapMerge>(),
        make_shared<BinarySearch>(),
        make_shared<HashLetter>(),
        make_shared<PowerSet>(),
        make_shared<Sorting>(),
        make_shared<Move>()
    };
    
    // Run Tests
    auto status = TestSuite::test(tests);
    return status;
}