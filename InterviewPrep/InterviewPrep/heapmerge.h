#ifndef HEAPMERGE_H
#define HEAPMERGE_H

#include "unittest.h"
#include <vector>
#include <queue> // priority_queue
#include <cstdlib> // rand
#include <algorithm>
#include <unordered_map>
#include <memory>

/*!
 * \brief The HeapMerge class solves the problem of merging sorted lists.
 * The lists are said to be files containing records sorted by time stamp.
 * For simplicity in this example the time stamp is the sorting metric and the data.
 */
class HeapMerge : public UnitTest
{
public:

    // number of files or arrays of data records
    const static int NumFiles;// = 123;

    // number of records per file
    const static int ArraySize;// = 100;

    //! The type of the data records / time stamps in the files
    typedef double DataType;

    // < Data Record, File Index>
    typedef std::pair<DataType, int> DataPair;

    //! File containing a list of data records
    typedef std::vector<DataType> DataVector;
    typedef std::shared_ptr<DataVector> DataVectorPtr;

    // Constructor
    HeapMerge();

    //! Fill an array to represent the data recorded in the file
    void fillArray(DataVector &v);

    //! Run the unit test simulation
    virtual TestResult test();
};

#endif // HEAPMERGE_H
