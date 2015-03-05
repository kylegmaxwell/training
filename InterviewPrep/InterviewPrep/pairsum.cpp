#include "pairsum.h"

#include <vector>
#include <algorithm>

using namespace std;

PairSum::PairSum() : UnitTest(false)
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

bool PairSum::hasThreeSum(PairSum::IntVec &vec, int querySum)
{
    for (size_t i = 0; i < vec.size(); i++) {
        int value = vec[i];
        int queryPairSum = querySum - value;
        if (hasPairSum(vec, queryPairSum))
            return true;
    }
    return false;
}

bool PairSum::hasThreeSumFast(PairSum::IntVec &vec, int querySum)
{// WARNING: Does not work

    // Initialize an index at the start and end of the array
    int iMin = 0;
    int iMax = vec.size() - 1;

    // Move the indexes up or down until the sum is found or they cross
    while (iMin < iMax) {

        //cout << "LOOP " << iMin << " " << iMax << endl;
        const int minVal = vec[iMin];
        const int maxVal = vec[iMax];
        const int currentPartialSum = minVal + maxVal;
        //cout << "sum " << currentPartialSum << endl;
        const int searchValue = querySum - currentPartialSum;
        //cout << "looking for " << searchValue << endl;

        // check if we have found the sum
        int closest=0;
        int closestIdx=0;
        if (binarySearch(vec, searchValue, iMin, iMax, closest, closestIdx)!=-1) {
            if (mVerbose)
                cout << "Three sum is found for " << querySum << endl;
            return true;
        }
        //cout << "close " << closest  << endl;
        const int fullSum = currentPartialSum + closest;
        //cout << "full " << fullSum << endl;
        const int iMid = iMin + (iMax - iMin) / 2;

        // Move the appropriate index
        //if (currentPartialSum > querySum)
        //if (searchValue > querySum)
        //if (fullSum > querySum)
        if (iMid == closestIdx) {
            if (fullSum > querySum)
                iMax--;
            else // currentSum < querySum
                iMin++;
        }
        else {
            if (iMid > closestIdx)
                iMax--;
            else // currentSum < querySum
                iMin++;
        }

    }

    if (mVerbose)
        cout << "No three sum found for " << querySum << endl;
    return false;
}

int PairSum::binarySearch(PairSum::IntVec &values, int searchValue, size_t firstIndex, size_t lastIndex, int &closest, int &closestIdx)
{
    if (values.empty() || firstIndex > lastIndex)
        return -1;

    int  left = firstIndex;//0
    int  right = lastIndex;//values.size()-1;
    while (left <= right) {
//cout << "left " << left << "right " << right << endl;
        int middle = left + (right - left) / 2;
        closest = values[middle];
        closestIdx = middle;

        int middleL = middle;
        if (middleL > (int)firstIndex)
            middleL-=1;
        int middleR = middle;
        if (middleR < (int)lastIndex)
            middleR+=1;
        if (std::abs(values[middleR] - searchValue) < std::abs(closest-searchValue) ){
            closest = values[middleR];
            closestIdx = middleR;
        }
        if (std::abs(values[middleL] - searchValue) < std::abs(closest-searchValue) ) {
            closest = values[middleL];
            closestIdx = middleL;
        }
        int arrayValue = values[middle];

        if (arrayValue == searchValue) {
            return middle;
        }

        if (arrayValue < searchValue) {
            left = middle+1;
        }
        else { // arrayValue > searchValue
            right = middle-1;
        }
    }

    return -1;
}

UnitTest::TestResult PairSum::test()
{
    IntVec values;
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

    IntVec data;
    data.push_back(-14);//
    data.push_back(-10);
    data.push_back(2);
    data.push_back(108);
    data.push_back(108);
    data.push_back(243);//
    data.push_back(285);//
    data.push_back(285);
    data.push_back(285);
    data.push_back(401);

    if (hasThreeSum(data, 0))
        return FAIL;

    if (!hasThreeSum(data, 100))
        return FAIL;

    for (size_t i = 0; i < data.size(); i++) {
        for (size_t j = i+1; j < data.size(); j++) {
            for (size_t k = j+1; k < data.size(); k++) {

                if (mVerbose)
                    cout << "testing " << i << " " << j << " " << k << endl;

                if (!hasThreeSum(data, data[i]+data[j]+data[k]))
                    return FAIL;
            }
        }
    }
    return PASS;
}
