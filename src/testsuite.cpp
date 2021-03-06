#include "testsuite.h"
#include "logger.h"
#include <sstream>
#include <iostream>

using namespace std;

int TestSuite::test(const vector<unique_ptr<UnitTest>> &tests)
{
    int count = 0;
    int failures = 0;

    for (const auto &t : tests) {
        Logger::DEBUG_WORD(count);
        if (t->test() == UnitTest::TestResult::FAIL) {
            Logger::DEBUG_WORD("X");
            failures++;
        }
        else { // pass
            Logger::DEBUG_WORD(".");
        }
        count++;
    }
    Logger::ENDL();

    Logger::DEBUG_WORD(tests.size() - failures);
    Logger::DEBUG(" succeeded");

    stringstream ss;
    ss << failures << " failure";
    if (failures != 1)
        ss << "s";

    Logger::DEBUG(ss.str());

    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}