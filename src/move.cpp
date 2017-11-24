#include <utility>
#include <exception> 

#include "move.h"
#include "os.h"

using namespace std;

UnitTest::TestResult Move::test() 
{
    int COUNT = 1000;
    // Create some data
    Move m1(COUNT);
    if (!m1.values.size() == COUNT) return FAIL;

    // Copy construct
    Move m2(m1);
    if (!m1.values.size() == COUNT) return FAIL;
    if (!m2.values.size() == COUNT) return FAIL;
    
    // Move construct
    Move m3(std::move(m1));
    if (!m1.values.size() == 0) return FAIL;
    if (!m2.values.size() == COUNT) return FAIL;
    if (!m3.values.size() == COUNT) return FAIL;
    DEBUG_PRINT("TEST");

    m3 = move(m2);
    if (!m2.values.size() == 0) return FAIL;
    if (!m3.values.size() == COUNT) return FAIL;

    m2 = m3;
    if (!m2.values.size() == COUNT) return FAIL;
    if (!m3.values.size() == COUNT) return FAIL;

    return PASS;
}

// ctor
Move::Move()
{
}

Move::Move(size_t size)
{
    for (size_t i = 0; i < size; i++) {
        values.push_back(i);
    }
}

//dtor
Move::~Move()
{
    values.clear();
}

// copy ctor
Move::Move(const Move & rhs)
{
    DEBUG_PRINT("copy ctor");
    values = rhs.values;
}

// move ctor
Move::Move(Move && rhs)
{
    DEBUG_PRINT("move ctor");
    values = forward<vector<int>>(rhs.values);
}

// copy assign
Move & Move::operator=(const Move & rhs)
{  
    DEBUG_PRINT("copy assign");
    values = rhs.values;
    return *this;
}

// move assign
Move & Move::operator=(Move && rhs)
{
    DEBUG_PRINT("move assign");
    values = forward<vector<int>>(rhs.values);
    return *this;
}
