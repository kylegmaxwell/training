#pragma once

#include "unittest.h"

#include <iostream>
#include <vector>

class PairSum : public UnitTest
{
public:
    typedef std::vector<int> IntVec;

    /*!
     * \brief hasPairSum Checks to see if there are any two integers that sum to the given value.
     * Assumes input vector is sorted.
     * \param vec The vector of numbers which could form pairs.
     * \param querySum The value of the sum.
     * \return true If there is such a pair
     */
    bool hasPairSum(IntVec &vec, int querySum);

    /*!
     * \brief hasThreeSum Checks to see if there are any three integers in the array that sum to the given value.
     * Assumes input vector is sorted (O(n log n).
     * \param vec The vector of numbers which could form triples.
     * \param querySum The value of the sum.
     * \return true If there is such a pair
     */
    bool hasThreeSum(IntVec &vec, int querySum);

    //WARNING: Does not work
    // This was an attempt to solve the open problem for a n log n 3 sum search using a combination of the pair sum algorithm and binary search
    bool hasThreeSumFast(IntVec &vec, int querySum);

    size_t binarySearch(IntVec &values, int searchValue, size_t firstIndex, size_t lastIndex, int &closest, size_t &closestIdx);

    virtual TestResult test() override;

    ;
};
