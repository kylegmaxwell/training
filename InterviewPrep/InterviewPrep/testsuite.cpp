#include "testsuite.h"

#include <iostream>
using namespace std;

TestSuite::TestSuite()
{
}

void TestSuite::addTest(UnitTest *test)
{
    mTests.push_back(test);
}

void TestSuite::test()
{
    int count=0;
    int failures=0;

    for (auto itr = mTests.begin(); itr != mTests.end(); itr++) {

        UnitTest *t = *itr;
        if (!t->test()) {
            cout << "X";
            failures++;
        }
        else {
            cout << ".";
        }
        count++;
    }

    cout << endl;

    cout << failures << " failure";
    if (failures != 1)
        cout << "s";
    cout << endl;
}
