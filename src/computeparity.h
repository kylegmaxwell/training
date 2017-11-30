#pragma once

#include "unittest.h"

class ComputeParity : public UnitTest
{
public:
    int computeParity(int value);

    virtual TestResult test();
};
