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

    // Allow child classes to override destructor if needed
    virtual ~UnitTest() = default;

    //! Tests can pass or fail
    enum class TestResult { PASS, FAIL };

    //! Overridable test function to be implemented by test classes
    virtual TestResult test();

protected:

    //! Wheter to print extra logging information
    bool mVerbose{ false };

    /*!
     * Convenience function to compare strings and return a bool
     * @returns true when equal
     */
    static auto stringEqual(std::string a, std::string b) {
        return a.compare(b) == 0;
    }
};
