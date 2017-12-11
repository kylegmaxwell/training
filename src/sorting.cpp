#include <climits>
#include <future>

#include "sorting.h"
#include "logger.h"

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
    randomVec(v, 1'000, 100);

    if (mVerbose)
        printVec(v);

    auto t0 = chrono::steady_clock::now();

    //sort(v.begin(), v.end()); // fast
    mergeSort(v, 0, v.size() - 1, 0); // medium
    //selectionSort(v); // slow

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

void Sorting::mergeSort(Sorting::IntVec &v, size_t L, size_t R, size_t d)
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
    // This should impove performance on multi threaded machines
    // Though the improvement on my laptop is negligible
    if (d > 1) {
        mergeSort(v, L, M, d + 1);
        mergeSort(v, M + 1, R, d + 1);
    }
    else {
        auto policy = launch::async;
        auto taskL = async(policy, [&v, L, M, d] {mergeSort(v, L, M, d + 1); });
        taskL.wait();
        auto taskR = async(policy, [&v, M, R, d] {mergeSort(v, M + 1, R, d + 1); });
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