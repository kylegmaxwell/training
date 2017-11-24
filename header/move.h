#pragma once

#include <vector>

#include "unittest.h"

class Move : public UnitTest
{
public:
    Move();
    Move(size_t size);
    ~Move();
    Move(const Move & move);
    Move(Move && move);
    Move& operator=(const Move& move);
    Move& operator=(Move && move);

    std::vector<int> values;

    virtual UnitTest::TestResult test() override;

private:
};