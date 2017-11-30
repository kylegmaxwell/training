#include "dynamicprogramming.h"

using namespace std;

Combinations::Int DynamicProgramming::factorial(Combinations::Int n)
{
    Combinations::Int result = 1;
    while (n > 1) {
        result *= n;
        n--;
    }
    return result;
}

Combinations::Int DynamicProgramming::chooseFlawed(Combinations::Int n, Combinations::Int k)
{
    // valid input check
    if (k > n)
        return 0;

    // Instead of calling factorial directly try to take advantage of
    // some cancelling in the numerator and denominator
    Combinations::Int d = n - k;

    Combinations::Int result = 1;
    while (n > d) {
        result *= n;
        cout << result << endl;
        n--;
    }

    while (k > 1) {
        result /= k;
        k--;
    }
    return result;
}

Combinations::Int DynamicProgramming::chooseVeryFlawed(Combinations::Int n, Combinations::Int k)
{
    // cant compute directly due to overflow
    // this was my first attempt, which is even more flawed
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int DynamicProgramming::countPaths(const Array2D<bool> &board, Array2D<int> &cache, size_t row, size_t col)
{
    size_t maxR = board.getRows() - 1;
    size_t maxC = board.getCols() - 1;

    if ((row == maxR) && (col == maxC))
        return 1;

    //cout << "r " << row << " c " << col << endl;
    int cachedVal = cache.getState(row, col);
    if (cachedVal != -1)
        return cachedVal;

    int paths = 0;

    if (row < maxR) {
        size_t newRow = row + 1;
        if (!board.getState(newRow, col)) // make sure space is empty
            paths += countPaths(board, cache, newRow, col);
    }

    if (col < maxC) {
        size_t newCol = col + 1;
        if (!board.getState(row, newCol)) // make sure space is empty
            paths += countPaths(board, cache, row, newCol);
    }

    cache.setState(row, col, paths);

    return paths;
}

UnitTest::TestResult DynamicProgramming::testFactorial()
{
    vector<int> expectedResults;
    expectedResults.push_back(1);
    expectedResults.push_back(1);
    expectedResults.push_back(2);
    expectedResults.push_back(6);
    expectedResults.push_back(24);
    expectedResults.push_back(120);
    expectedResults.push_back(720);
    expectedResults.push_back(5040);
    expectedResults.push_back(40320);
    expectedResults.push_back(362880);

    for (size_t i = 0; i < 10; i++) {
        Combinations::Int fact = factorial(i);
        if (mVerbose)
            cout << fact << endl;
        if (fact != expectedResults[i])
            return TestResult::FAIL;
    }

    return TestResult::PASS;
}

UnitTest::TestResult DynamicProgramming::testChoose(Combinations &comb)
{
    if (mVerbose)
        comb.print();

    if (comb.choose(5, 5) != 1)
        return TestResult::FAIL;

    if (comb.choose(8, 4) != 70)
        return TestResult::FAIL;

    if (comb.choose(8, 3) != 56)
        return TestResult::FAIL;

    if (comb.choose(8, 5) != 56)
        return TestResult::FAIL;

    if (comb.choose(34, 19) != 1855967520)
        return TestResult::FAIL;

    return TestResult::PASS;
}

UnitTest::TestResult DynamicProgramming::testPaths(Combinations &comb)
{
    //----Test with no barriers

    // Initialize Board

    size_t rows = 20;
    size_t cols = 16;
    Array2D<bool> board(rows, cols);
    for (size_t r = 0; r < rows; r++) {
        for (size_t c = 0; c < cols; c++) {
            board.setState(r, c, false);
        }
    }

    // Initialize dynamic programming cache
    // This cache makes it WAY faster to terminate

    Array2D<int> cache(rows, cols);
    for (size_t r = 0; r < rows; r++) {
        for (size_t c = 0; c < cols; c++) {
            cache.setState(r, c, -1);
        }
    }

    // Count paths and test result

    Combinations::Int paths = countPaths(board, cache, 0, 0);

    if (mVerbose)
        cout << "num paths " << paths << endl;

    size_t overs = cols - 1;
    size_t downs = rows - 1;
    Combinations::Int expectedResult = comb.choose(overs + downs, downs);

    if (paths != expectedResult) {
        if (mVerbose)
            cout << "expected " << expectedResult << endl;
        return TestResult::FAIL;
    }

    //---- Test with barriers set

    // Clear cache

    for (size_t r = 0; r < rows; r++) {
        for (size_t c = 0; c < cols; c++) {
            cache.setState(r, c, -1);
        }
    }

    // Create barrier

    // by leaving only one gap on the right this barrier creates a puzzle that is
    // equivalent to only having 5 rows, so its easy to compute the expected result
    for (size_t c = 0; c < cols - 1; c++) {
        board.setState(5, c, true);
    }

    // Test again

    paths = countPaths(board, cache, 0, 0);
    downs = 5 - 1;
    expectedResult = comb.choose(overs + downs, downs);

    if (paths != expectedResult) {
        return TestResult::FAIL;
    }

    return TestResult::PASS;
}

UnitTest::TestResult DynamicProgramming::test()
{
    if (testFactorial() == TestResult::FAIL)
        return TestResult::FAIL;

    Combinations c;

    if (testChoose(c) == TestResult::FAIL)
        return TestResult::FAIL;

    if (testPaths(c) == TestResult::FAIL)
        return TestResult::FAIL;

    return TestResult::PASS;
}

template <class T>
Array2D<T>::Array2D(size_t rows, size_t cols)
    : mRows(rows), mCols(cols), mEntries(rows*cols)
{
}

template <class T>
void Array2D<T>::setState(size_t row, size_t col, T state)
{
    mEntries[row * mCols + col] = state;
}

template <class T>
T Array2D<T>::getState(size_t row, size_t col) const
{
    return mEntries[row * mCols + col];
}

template <class T>
void Array2D<T>::printFull(ostream &stream) const
{
    stream << "Printing board " << mRows << "x" << mCols << endl;
    for (size_t r = 0; r < mRows; r++) {
        for (size_t c = 0; c < mCols; c++) {
            cout << getState(r, c) << " ";
        }
        cout << endl;
    }
}

template <class T>
std::pair<size_t, size_t> Array2D<T>::getSize() const
{
    return std::pair<size_t, size_t>(mRows, mCols);
}

Combinations::Combinations()
{
    while (numRows() < 10) {
        addRow();
    }
}

Combinations::~Combinations()
{
    for (size_t i = 0; i < cache.size(); i++) {
        IntVec *v = cache[i];
        delete v;
    }
    cache.clear();
}

void Combinations::addRow()
{
    IntVec *newRow = new IntVec(numRows() + 1);
    cache.push_back(newRow);

    size_t rows = numRows();
    if (rows == 1) {
        (*newRow)[0] = 1;
    }
    else {
        IntVec *prevRow = cache[rows - 2];
        (*newRow)[0] = 1;
        for (size_t j = 1; j < rows - 1; j++) {
            (*newRow)[j] = (*prevRow)[j] + (*prevRow)[j - 1];
        }
        (*newRow)[rows - 1] = 1;
    }
}

size_t Combinations::numRows()
{
    return cache.size();
}

Combinations::Int Combinations::choose(Combinations::Int n, Combinations::Int k)
{
    // check for valid input
    if (k > n || k < 0 || n < 0)
        return 0;

    if (k == n)
        return 1;

    // n > k

    // build up cache to support current evaluation
    while ((size_t)n >= numRows()) {
        addRow();
    }

    // retrieve result from cache
    IntVec *v = cache[(size_t)n];
    Int value = (*v)[(size_t)k];

    return value;
}

void Combinations::print()
{
    for (size_t i = 0; i < cache.size(); i++) {
        cout << i << ": ";
        IntVec *v = cache[i];
        for (size_t j = 0; j <= i; j++) {
            cout << (*v)[j] << " ";
        }
        cout << endl;
    }
}