#include "binarysearch.h"

using namespace std;

UnitTest::TestResult BinarySearch::test()
{
    vector<int> data{
       -14,-10,2,108,108,243,285,285,285,401
    };
    vector<int> expectedResults{
        0,1,2,3,3,5,6,6,6,9
    };

    sort(data.begin(), data.end());

    for (size_t i = 0; i < data.size(); i++) {
        auto index = BinarySearch::search(data, data[i]);
        // The item in the list should always be found
        if (index == -1)
            return FAIL;

        // Find the left most occurrence of the item
        auto leftIndex = searchLeft(data, index);

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
        auto middle = left + (right - left) / 2;

        T arrayValue = values[middle];
        if (arrayValue == searchValue) {
            return middle;
        }

        if (arrayValue < searchValue) {
            left = middle + 1;
        }
        else { // arrayValue > searchValue
            right = middle - 1;
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
    auto right = index;
    while (left <= right) {
        if (left == right)
            return left;
        auto middle = left + (right - left) / 2;

        T arrayValue = values[middle];

        // found, so discard right half
        if (arrayValue == searchValue) {
            // was a match, so we must keep middle in consideration
            right = middle;
        }
        else { // arrayValue > searchValue
            // not a match, so we can discard the middle index
            left = middle + 1;
        }
    }
    return -1;
}