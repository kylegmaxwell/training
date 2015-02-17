#include "unittest.h"

UnitTest::UnitTest(bool iVerbose) : mVerbose(iVerbose)
{
}

UnitTest::TestResult UnitTest::test()
{
    return PASS;
}
