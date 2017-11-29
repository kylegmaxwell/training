#include "testsuite.h"

#include <iostream>
using namespace std;

int TestSuite::test(vector<shared_ptr<UnitTest>> tests)
{
    int count = 0;
    int failures = 0;

    for (auto t : tests) {
        if (t->test() == UnitTest::FAIL) {
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