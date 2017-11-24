#include "sorting.h"
#include <climits>

using namespace std;

Sorting::Sorting() : UnitTest(false)
{
    srand(0);
}

UnitTest::TestResult Sorting::test()
{
    IntVec v;
    randomVec(v, 100000);

    if (mVerbose)
        printVec(v);

    mergeSort(v, 0, v.size()-1);

    if (mVerbose)
        printVec(v);

    if (checkVec(v)==FAIL)
        return FAIL;

    return PASS;
}

void Sorting::swapVec(Sorting::IntVec &v, size_t L, size_t R)
{
    int tmp = v[L];
    v[L] = v[R];
    v[R] = tmp;
}

void Sorting::printVec(Sorting::IntVec &v)
{
    for (auto itr = v.begin(); itr != v.end(); itr++) {
        cout << *itr << endl;
    }
}

UnitTest::TestResult Sorting::checkVec(Sorting::IntVec &v)
{
    int prev = INT_MIN;
    for (auto itr = v.begin(); itr != v.end(); itr++) {
        if (*itr < prev)
            return FAIL;
    }
    return PASS;
}

void Sorting::randomVec(Sorting::IntVec &v, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        v.push_back(rand()%1000);
    }
}

void Sorting::mergeSort(Sorting::IntVec &v, size_t L, size_t R)
{
    // first base case
    if (L == R)
        return;

    // second base case (makes sure M+1 <= R for code below)
    if (L + 1 == R) {
        if (v[L] > v[R]) {
            swapVec(v, L, R);
        }
        return;
    }
    size_t M = L + (R - L) / 2;

    mergeSort(v, L, M);

    mergeSort(v, M+1, R);

    // merge
    size_t l = L;
    size_t r = M+1;
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
