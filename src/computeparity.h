#pragma once

#include "unittest.h"

class ComputeParity : public UnitTest
{
public:
    ComputeParity();

    ~ComputeParity() = default;

    int computeParity(int value);

    virtual TestResult test();
};
