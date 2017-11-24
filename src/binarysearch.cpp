#include "binarysearch.h"

using namespace std;

BinarySearch::BinarySearch()
{
}


UnitTest::TestResult BinarySearch::test()
{
    vector<int> data;
    data.push_back(-14);
    data.push_back(-10);
    data.push_back(2);
    data.push_back(108);
    data.push_back(108);
    data.push_back(243);
    data.push_back(285);
    data.push_back(285);
    data.push_back(285);
    data.push_back(401);

    vector<int> expectedResults;
    expectedResults.push_back(0);
    expectedResults.push_back(1);
    expectedResults.push_back(2);
    expectedResults.push_back(3);
    expectedResults.push_back(3);
    expectedResults.push_back(5);
    expectedResults.push_back(6);
    expectedResults.push_back(6);
    expectedResults.push_back(6);
    expectedResults.push_back(9);

    sort(data.begin(), data.end());

    for (size_t i = 0; i < data.size(); i++) {
        size_t index = BinarySearch::search(data, data[i]);
        if (index == -1)
            return FAIL;

        size_t leftIndex = searchLeft(data, index);

        if (leftIndex != expectedResults[i]) {
            return FAIL;
        }
    }

    if (BinarySearch::search(data, 0) != -1)
        return FAIL;

    return PASS;
}

template <typename T>
size_t BinarySearch::search(std::vector<T> &values, T searchValue)
{
    if (values.empty())
        return -1;

    size_t left = 0;
    size_t right = values.size() - 1;
    while (left <= right) {
        size_t middle = left + (right - left) / 2;

        T arrayValue = values[middle];
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

template <typename T>
size_t BinarySearch::searchLeft(std::vector<T> &values, size_t index)
{
    // check for invalid
    if (index >= values.size())
        return -1;

    T searchValue = values[index];

    size_t left = 0;
    size_t right = index;
    while (left <= right) {
        if (left == right)
            return left;
        size_t middle = left + (right - left) / 2;

        T arrayValue = values[middle];

        // found, so discard right half
        if (arrayValue == searchValue) {
            // was a match, so we must keep middle in consideration
            right = middle;
        }
        else { // arrayValue > searchValue
            // not a match, so we can discard the middle index
            left = middle+1;
        }
    }
    return -1;
}
