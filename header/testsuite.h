#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <vector>

#include "unittest.h"

/*!
 * Container for a list of unit tests.
 */
class TestSuite
{
public:

    //! Default constructor
    TestSuite();

    /*!
     * Add a UnitTest (or one of it's child classes)
     */
    void addTest(UnitTest *test);

    /*!
     * Run all the tests that have been added
     */
    void test();

private:

    //! The tests that can be run via the test function
    std::vector<UnitTest*> mTests;
};

#endif // TESTSUITE_H
