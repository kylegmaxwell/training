#ifndef COMPUTEPARITY_H
#define COMPUTEPARITY_H

#include "unittest.h"

class ComputeParity : public UnitTest
{
public:
    ComputeParity();

    int computeParity(int value);

    virtual TestResult test();
};

#endif // COMPUTEPARITY_H
