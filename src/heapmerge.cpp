#include "heapmerge.h"

using namespace std;

const int HeapMerge::NumFiles(123);
const int HeapMerge::ArraySize(100);

HeapMerge::HeapMerge()
{
    // Initialize the random number generator for consistent results
    srand(0);
}

void HeapMerge::fillArray(DataVector &v)
{
    // generate an array of random numbers
    for (int i = 0; i < ArraySize; i++) {
        double value = rand() / (double)RAND_MAX;
        value *= 1000;
        v.push_back(value);
    }

    // sort the array to fulfull the precondition on the input
    sort(v.begin(), v.end(),
        [](double i, double j) { return (i < j); } // just for practice
    );
}

UnitTest::TestResult HeapMerge::test()
{
    // collection of all the files
    vector<DataVectorPtr> files;

    // offset into the vector for each file, used to keep track of what has been processed
    vector<int> offsets;

    // comparison class used by the priority queue to compare elements
    auto comp = [](const DataPair &a, const DataPair &b) {return a.first > b.first; };

    // Create a priority queue of DataPair's with a custom comparator
    priority_queue<DataPair, vector<DataPair>, decltype(comp) > q(comp);

    for (int i = 0; i < NumFiles; i++) {
        // create the file
        DataVectorPtr tmpFile(new DataVector()); // TODO clean up dynamic allocation
        files.push_back(tmpFile);
        fillArray(*tmpFile);

        // data is the first (min) value in the file paired with index into file array
        DataPair ip((*tmpFile)[0], i);

        // add to priority queue heap
        q.push(ip);

        // initialize the progress variable
        offsets.push_back(0);
    }

    // The final merged file containing all the records in sorted order
    DataVector values;

    // Process each record by using the priority queue to find the next minimum
    while (!q.empty()) {
        // extract top of the priority queue
        DataPair ip = q.top();
        q.pop();

        // add the extracted record to the output
        values.push_back(ip.first);

        // get the file associated with the record
        int index = ip.second;
        DataVectorPtr file = files[index];

        // get the position of the next record to process in the file
        int offset = offsets[index];

        // if there are more records to process in the file
        if ((size_t)offset < file->size() - 1) {
            // get the record and increment the counter
            offset++;
            DataType value = (*file)[offset];
            offsets[index] = offset;

            // add the file back into the queue so the rest of the records will be processed
            DataPair ipNew(value, index);
            q.push(ipNew);
        }
    }

    // check to make sure all the records were processed
    if (values.size() != NumFiles * ArraySize)
        return TestResult::FAIL;

    if (mVerbose)
        cout << values.size() << endl;

    // check the final array to see if it is sorted
    for (size_t i = 1; i < values.size(); i++) {
        double prev = values[i - 1];
        double curr = values[i];
        if (prev > curr)
            return TestResult::FAIL;
    }

    return TestResult::PASS;
}