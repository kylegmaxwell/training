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
    static int test(std::vector<std::shared_ptr<UnitTest>> tests);
};
