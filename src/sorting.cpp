#include "sorting.h"
#include "logger.h"

#include <climits>

using namespace std;

Sorting::Sorting()
{
    srand(0);
}

UnitTest::TestResult Sorting::test()
{
    if (mVerbose)
        Logger::DEBUG("SORT");

    IntVec v;
    randomVec(v, 1000, 100);

    if (mVerbose)
        printVec(v);

    mergeSort(v, 0, v.size() - 1);

    if (mVerbose)
        printVec(v);

    if (checkVec(v) == TestResult::FAIL)
        return TestResult::FAIL;

    return TestResult::PASS;
}

void Sorting::printVec(Sorting::IntVec &v) const
{
    for (auto itr = v.begin(); itr != v.end(); itr++) {
        Logger::DEBUG_WORD(*itr);
        if (itr != v.end())
            Logger::DEBUG_WORD(", ");
    }
    Logger::ENDL();
}

UnitTest::TestResult Sorting::checkVec(const Sorting::IntVec &v) const
{
    int prev = INT_MIN;
    for (const auto &itr : v) {
        auto val = itr;
        if (val < prev) {
            return TestResult::FAIL;
        }
        prev = val;
    }
    return TestResult::PASS;
}

void Sorting::randomVec(Sorting::IntVec &v, size_t size, size_t range) const
{
    for (size_t i = 0; i < size; i++) {
        v.push_back(rand() % range);
    }
}

void Sorting::mergeSort(Sorting::IntVec &v, size_t L, size_t R) const
{
    // first base case
    if (L == R)
        return;

    // second base case (makes sure M+1 <= R for code below)
    if (L + 1 == R) {
        if (v[L] > v[R]) {
            swap(v[L], v[R]);
        }
        return;
    }
    size_t M = L + (R - L) / 2;

    mergeSort(v, L, M);

    mergeSort(v, M + 1, R);

    // merge
    size_t l = L;
    size_t r = M + 1;
    IntVec merged;
    // merge the minimums
    while (l <= M && r <= R) {
        if (v[l] < v[r]) {
            merged.push_back(v[l]);
            l++;
        }
        else { // v[l] >= v[r]
            merged.push_back(v[r]);
            r++;
        }
    }
    // merge the left over left side
    while (l <= M) {
        merged.push_back(v[l]);
        l++;
    }
    // merge the left over right side
    while (r <= R) {
        merged.push_back(v[r]);
        r++;
    }

    // replace the section of the vector with the merged sorted result
    size_t j = 0;
    for (size_t i = L; i <= R; i++) {
        v[i] = merged[j];
        j++;
    }
}