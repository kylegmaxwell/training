#include "maxstack.h"
#include <algorithm>
#include <climits>

using namespace std;

MaxStack::MaxStack() : UnitTest(false)
{
    mStack.clear();
    mMax.clear();
}

void MaxStack::push(int value)
{
    int oldMax = INT_MIN;
    if (mMax.size() > 0)
        oldMax = mMax[mMax.size()-1];
    int newMax = std::max<int>(oldMax, value);

    mStack.emplace_back(value);
    mMax.emplace_back(newMax);
}

int MaxStack::pop()
{
    if (mStack.size() == 0) {
        if (mVerbose)
            cerr << "WARNING: Popping empty stack" << endl;
        return INT_MIN;
    }

    int value = mStack[mStack.size()-1];
    mStack.pop_back();

    int maxValue = mMax[mMax.size()-1];
    mMax.pop_back();

    if (mVerbose) {
        cout << "pop " << value << endl;
        cout << "max " << maxValue << endl;
    }
    return maxValue;
}

void MaxStack::getMaxValue()
{

}

UnitTest::TestResult MaxStack::test()
{
    push(2);
    push(7);
    push(5);

    if (pop() != 7)
        return FAIL;

    if (pop() != 7)
        return FAIL;

    if (pop() != 2)
        return FAIL;

    return PASS;
}
