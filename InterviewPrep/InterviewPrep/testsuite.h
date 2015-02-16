#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <vector>

#include "unittest.h"

class TestSuite
{
public:
    TestSuite();

    void addTest(UnitTest *test);

    void test();

private:
    std::vector<UnitTest*> mTests;
};

#endif // TESTSUITE_H
