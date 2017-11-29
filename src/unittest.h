#pragma once

#include <iostream>
#include <string>

/*!
 * Unit test base class.
 * Tests can implement the test() function to be run as part of a test suite.
 */
class UnitTest
{
public:

    //! Tests can pass or fail
    enum TestResult { PASS, FAIL };

    //! Constrctor for a unit test that defaults verose to true
    UnitTest(bool iVerbose = true);

    //! Overridable test function to be implemented by test classes
    virtual TestResult test();

protected:

    //! Wheter to print extra logging information
    bool mVerbose;

    //! Accessor for verbose
    bool verbose() const
    {
        return mVerbose;
    }

    /*!
     * Convenience function to compare strings and return a bool
     * @returns true when equal
     */
    static bool stringEqual(std::string a, std::string b) {
        return a.compare(b) == 0;
    }
};
