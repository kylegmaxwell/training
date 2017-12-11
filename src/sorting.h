#pragma once

#include "unittest.h"

#include <vector>
#include <cstdlib> // rand
#include <functional>

class Sorting : public UnitTest
{
public:

    using IntVec = std::vector<int>;

    Sorting();

    virtual TestResult test() override;

private:
    /*!
    * \brief testSort Test a sorting algorithm that operates on a vector
    * \param func The function to call on the vector to sort it
    * \param numElements The number of elements to add to the vector
    * \param numValues The range of values in the vector is from zero to this value
    */
    TestResult testSort(std::function<void(Sorting::IntVec&)> func, size_t numElements, size_t numValues);

    //! print all elements in a vector
    static void printVec(IntVec &v);

    //! check if a vector is sorted increasing
    static TestResult checkVec(const IntVec &v);

    //! populate a random vector
    static void randomVec(IntVec &v, size_t size, size_t range);

    /*!
     * \brief mergeSort sort using divide and conquer O(n*log(n))
     * \param v vector to sort
     */
    static void mergeSort(IntVec &v);

    /*!
    * \brief mergeSortHelper helper to sort a specific range
    * \param v vector to sort
    * \param L fist valid index
    * \param R last valid index
    * \param d recursion depth
    */
    static void mergeSortHelper(IntVec &v, size_t L, size_t R, size_t d);

    /*!
    * \brief Selection sort to use for benchmarking O(n^2)
    * \param v vector to sort
    */
    static void selectionSort(IntVec &v);
};
