#ifndef PAIRSUM_H
#define PAIRSUM_H

#include "unittest.h"

#include <iostream>
#include <vector>

class PairSum : public UnitTest
{
public:
    typedef std::vector<int> IntVec;

    PairSum();

    /*!
     * \brief hasPairSum Checks to see if there are any two integers that sum to the given value.
     * Assumes input vector is sorted.
     * \param vec The vector of numbers which could form pairs.
     * \param querySum The value of the sum.
     * \return true If there is such a pair
     */
    bool hasPairSum(IntVec &vec, int querySum);

    virtual TestResult test();

    ;
};

#endif // PAIRSUM_H
