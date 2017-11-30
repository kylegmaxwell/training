#pragma once

#include "unittest.h"

#include <vector>

class MaxStack : public UnitTest
{
public:
    using IntVec = std::vector<int>;

    /*!
     * \brief push Add a new value to the top of the stack, and compute the max
     */
    void push(int value);

    /*!
     * \brief push Remove a value from the top of the stack, and return the max
     */
    int pop();

    void getMaxValue();

    virtual TestResult test();

    IntVec mStack{};
    IntVec mMax{};
};
