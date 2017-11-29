#pragma once

#include <vector>
#include <algorithm>

#include "unittest.h"

class BinarySearch : public UnitTest
{
public:

    BinarySearch();

    virtual TestResult test();

    /*!
     * \brief Search for the index of the given value.
     * \param value The value to look for in the array
     * \return The index, or -1 if not found.
     */
    template <typename T>
    static size_t search(std::vector<T> &values, T value);

    /*!
     * \brief Search for the leftmost index of the given value.
     * \param index The index of a known occurence of the searched value
     * \return The index, or -1 if not found.
     */
    template <typename T>
    size_t searchLeft(std::vector<T> &values, size_t index);
};
