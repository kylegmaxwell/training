#pragma once

#include "unittest.h"

#include <vector>
#include <cstdlib> // rand

class Sorting : public UnitTest
{
public:

    typedef std::vector<int> IntVec;

    Sorting();

    virtual TestResult test() override;

private:

    //! swap two elements in a vector
    void swapVec(IntVec &v, size_t L, size_t R);

    //! print all elements in a vector
    void printVec(IntVec &v);

    //! check if a vector is sorted increasing
    TestResult checkVec(IntVec &v);

    //! populate a random vector
    void randomVec(IntVec &v, size_t size);

    /*!
     * \brief mergeSort sort using divide and conquer
     * \param v vector to sort
     * \param L fist valid index
     * \param R last valid index
     */
    void mergeSort(IntVec &v, size_t L, size_t R);
};
