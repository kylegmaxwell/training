#pragma once

#include <vector>
#include <memory>

#include "unittest.h"

/*!
 * Container for a list of unit tests.
 */
class TestSuite
{
public:
    /*!
     * Run all the tests that have been added
     * @returns status code
     */
    static int test(const std::vector<std::unique_ptr<UnitTest>> &tests);
};
