#include <QCoreApplication>
#include <iostream>

#include "computeparity.h"
#include "unittest.h"
#include "testsuite.h"
#include "narytree.h"
#include "convertbase.h"

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

    ConvertBase base;
    tests.addTest(&base);

    // Run Tests
    tests.test();

    QCoreApplication a(argc, argv);

    return a.exec();
}
