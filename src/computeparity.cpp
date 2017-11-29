#include "computeparity.h"
#include <iostream>
using namespace std;

ComputeParity::ComputeParity() : UnitTest(false)
{
}

int ComputeParity::computeParity(int value) {

    if (verbose())
        cout << value << endl;
    bool even = true;
    int bits = sizeof(value)*8;
    int tmpValue = value;
    for (int shift=0;shift<bits;shift++) {
        int bit = 1 & tmpValue;
        if (bit)
            even = !even;
        tmpValue = tmpValue >> 1;
        if (verbose())
            cout << bit;
    }
    if (verbose()) {
        cout << endl;
        if (even)
            cout << "Even" << endl;
        else
            cout << "Odd" << endl;
        cout << endl;
    }
    if (even)
        return 0;
    else
        return 1;
}

UnitTest::TestResult ComputeParity::test()
{
    if (verbose())
        cout << "ComputeParity running test" << endl;

    int expectedResult[10] = {0,1,1,0,1,0,0,1,1,0};

    for (int i=0;i<10;i++) {
        int parity = computeParity(i);
        if (parity != expectedResult[i])
            return FAIL;
    }
    return PASS;
}
