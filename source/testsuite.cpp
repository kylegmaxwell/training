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

int TestSuite::test()
{
    int count=0;
    int failures=0;

    for (auto itr = mTests.begin(); itr != mTests.end(); itr++) {

        UnitTest *t = *itr;
        if (t->test()==UnitTest::FAIL) {
            cout << "X";
            failures++;
        }
        else { // pass
            cout << ".";
        }
        count++;
    }

    cout << endl;

    cout << failures << " failure";
    if (failures != 1)
        cout << "s";
    cout << endl;
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
