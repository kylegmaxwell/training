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
    static void printVec(IntVec &v);

    //! check if a vector is sorted increasing
    static TestResult checkVec(const IntVec &v);

    //! populate a random vector
    static void randomVec(IntVec &v, size_t size, size_t range);

    /*!
     * \brief mergeSort sort using divide and conquer O(n*log(n))
     * \param v vector to sort
     * \param L fist valid index
     * \param R last valid index
     * \param d recursion depth
     */
    static void mergeSort(IntVec &v, size_t L, size_t R, size_t d);

    /*!
    * \brief Selection sort to use for benchmarking O(n^2)
    * \param v vector to sort
    */
    static void selectionSort(IntVec &v);
};
