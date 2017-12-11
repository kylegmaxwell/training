#include <climits>
#include <future>
#include <algorithm>

#include "sorting.h"
#include "logger.h"

using namespace std;

Sorting::Sorting()
{
    srand(0);
}

UnitTest::TestResult Sorting::test()
{
    size_t numElements = 1'000;
    size_t numValues = numElements / 10;

    // performance slow - O(n^2)
    auto t1 = testSort(selectionSort, numElements, numValues);

    // performance medium (concurrent and O(n*log(n))
    auto t2 = testSort(mergeSort, numElements, numValues);

    // performance fast - use std::sort, TODO compare to quick sort
    auto t3 = testSort([](Sorting::IntVec& v) { sort(v.begin(), v.end()); }, numElements, numValues);

    // Do nothing, should fail
    auto t4 = testSort([](Sorting::IntVec& v) {}, numElements, numValues);

    if (t1 != TestResult::PASS || t2 != TestResult::PASS ||
        t3 != TestResult::PASS || t4 != TestResult::FAIL) {
        return TestResult::FAIL;
    }
    return TestResult::PASS;
}

UnitTest::TestResult Sorting::testSort(function<void(Sorting::IntVec&)> sortFunc, size_t numElements, size_t numValues)
{
    if (mVerbose)
        Logger::DEBUG("SORT");

    IntVec v;
    randomVec(v, numElements, numValues);

    if (mVerbose)
        printVec(v);

    auto t0 = chrono::steady_clock::now();

    sortFunc(v);

    auto t1 = chrono::steady_clock::now();

    if (mVerbose) {
        std::chrono::duration<double> fp_s = t1 - t0;
        Logger::DEBUG(fp_s.count());
        printVec(v);
    }

    if (checkVec(v) == TestResult::FAIL)
        return TestResult::FAIL;

    return TestResult::PASS;
}

void Sorting::printVec(Sorting::IntVec &v)
{
    for (auto itr = v.begin(); itr != v.end(); itr++) {
        Logger::DEBUG_WORD(*itr);
        if (itr != v.end())
            Logger::DEBUG_WORD(", ");
    }
    Logger::ENDL();
}

UnitTest::TestResult Sorting::checkVec(const Sorting::IntVec &v)
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

void Sorting::randomVec(Sorting::IntVec &v, size_t size, size_t range)
{
    for (size_t i = 0; i < size; i++) {
        v.push_back(rand() % range);
    }
}

void Sorting::mergeSort(Sorting::IntVec &v)
{
    // Sort the whole range with initial recusion depth of zero
    mergeSortHelper(v, 0, v.size() - 1, 0);
}

void Sorting::mergeSortHelper(Sorting::IntVec &v, size_t L, size_t R, size_t d)
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

    // Use threads for the first two tiers
    // This will impove performance on multi threaded machines up to about 4 cores
    if (d > 1) {
        mergeSortHelper(v, L, M, d + 1);
        mergeSortHelper(v, M + 1, R, d + 1);
    }
    else {
        auto policy = launch::async;
        auto taskL = async(policy, [&v, L, M, d] {mergeSortHelper(v, L, M, d + 1); });
        auto taskR = async(policy, [&v, M, R, d] {mergeSortHelper(v, M + 1, R, d + 1); });
        taskL.wait();
        taskR.wait();
    }

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

void Sorting::selectionSort(IntVec & v)
{
    for (size_t i = 0; i < v.size() - 1; i++) {
        auto lowest = v[i];
        auto idx = i;
        for (size_t j = i + 1; j < v.size(); j++) {
            if (v[j] < v[idx]) {
                idx = j;
                lowest = v[j];
            }
        }
        if (idx > i) {
            swap(v[i], v[idx]);
        }
    }
}