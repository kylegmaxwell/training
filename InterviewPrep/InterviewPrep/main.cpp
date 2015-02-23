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

    // Run Tests
    tests.test();

    QCoreApplication a(argc, argv);

    return a.exec();
}
