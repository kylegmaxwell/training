#include "pairsum.h"

#include <vector>
#include <algorithm>

using namespace std;

PairSum::PairSum()
{
}

bool PairSum::hasPairSum(PairSum::IntVec &vec, int querySum)
{
    // Initialize an index at the start and end of the array
    int iMin = 0;
    int iMax = vec.size() - 1;

    // Move the indexes up or down until the sum is found or they cross
    while (iMin < iMax) {

        const int minVal = vec[iMin];
        const int maxVal = vec[iMax];
        const int currentSum = minVal + maxVal;

        // check if we have found the sum
        if (currentSum == querySum)
            return true;

        // Move the appropriate index
        if (currentSum > querySum)
            iMax--;
        else // currentSum < querySum
            iMin++;
    }
    return false;
}

UnitTest::TestResult PairSum::test()
{

    std::vector<int> values;
    values.push_back(1);
    values.push_back(3);
    values.push_back(7);
    values.push_back(18);
    values.push_back(27);
    values.push_back(99);
    values.push_back(105);
    values.push_back(111);
    values.push_back(118);

    sort(values.begin(), values.end());

    if (hasPairSum(values, 50))
        return FAIL;

    if (!hasPairSum(values, 112))
        return FAIL;

    return PASS;
}
