#ifndef UNITTEST_H
#define UNITTEST_H

#include <iostream>
#include <string>

class UnitTest
{
public:

    enum TestResult {PASS, FAIL};

    UnitTest(bool iVerbose = true);

    virtual TestResult test();

protected:
    bool mVerbose;

    bool verbose()
    { return mVerbose; }

    bool stringEqual(std::string a, std::string b) {
        return a.compare(b)==0;
    }
};

#endif // UNITTEST_H
