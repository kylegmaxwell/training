#pragma once

#include <vector>

#include "unittest.h"

/*!
 * \brief The Array class stores n x m array of data
 */
template <class T>
class Array2D {
public:

    Array2D(size_t rows, size_t cols);

    //! Set the value at row, col in the array
    void setState(size_t row, size_t col, T state);

    //! Get the value at row, col in the array
    T getState(size_t row, size_t col) const;

    //! print a visual record of the board
    void printFull(std::ostream &stream) const;

    //! Return the dimensions of the array as a rows, cols pair
    std::pair<size_t, size_t> getSize() const;

    //! Return the number of rows
    size_t getRows() const { return mRows; }

    //! Return the number of columns
    size_t getCols() const { return mCols; }

private:

    //! number of squares along one side of the baord
    size_t mRows;
    size_t mCols;

    //! The elements of the board
    std::vector<T> mEntries;
};

/*!
 * \brief The Combinations class calculates the combination function in probability theory.
 * This class caches the results as it goes to speed up redundant lookups
 */
class Combinations {
public:

    // Define int 64 for big numbers
    typedef long long int Int;

    // Define vector of integers type
    typedef std::vector<Int> IntVec;

    //! Constructor, does some initialization of the cache
    Combinations();

    //! Destructor cleans up IntVec array
    ~Combinations();

    //! Evaluate the choose function n C k
    Int choose(Int n, Int k);

    //! Print out the cache array
    void print();

private:
    std::vector<IntVec*> cache;

    // check how many rows have been cached
    size_t numRows();

    // Adds a row to the cache allowing a value of n one higher to be evaluated
    // Dynamically allocates an IntVec with memory managed interally to this class
    void addRow();
};

class DynamicProgramming : public UnitTest
{
public:
    //Note: factorial is not implemented with or used for the dynamic programming algorithm at this time
    // factorial used to compute expected result when no barriers are present
    Combinations::Int factorial(Combinations::Int n);

    //Note: this version of calculating combinations uses factiorals,
    // which can easily go out of bounds for large inputs
    Combinations::Int chooseFlawed(Combinations::Int n, Combinations::Int k);

    //Note: this will have trouble with large values of n
    // use factorial to compute combinations
    Combinations::Int chooseVeryFlawed(Combinations::Int n, Combinations::Int k);

    // count the number of paths from (row,col) to (mRows-1, mCols-1)
    int countPaths(const Array2D<bool> &board, Array2D<int> &cache, size_t row, size_t col);

    //! Test the factorial function
    TestResult testFactorial();

    //! Test the combinations class
    TestResult testChoose(Combinations &comb);

    //! Run the dynamic programming exercise
    TestResult testPaths(Combinations &comb);

    virtual TestResult test() override;
};
