#pragma once

#include "unittest.h"

#include <vector>
#include <cstdlib> // rand

class Sorting : public UnitTest
{
public:

    using IntVec = std::vector<int>;

    Sorting();

    virtual TestResult test() override;

private:

    //! print all elements in a vector
    void printVec(IntVec &v) const;

    //! check if a vector is sorted increasing
    TestResult checkVec(const IntVec &v) const;

    //! populate a random vector
    void randomVec(IntVec &v, size_t size, size_t range) const;

    /*!
     * \brief mergeSort sort using divide and conquer
     * \param v vector to sort
     * \param L fist valid index
     * \param R last valid index
     */
    void mergeSort(IntVec &v, size_t L, size_t R) const;
};
