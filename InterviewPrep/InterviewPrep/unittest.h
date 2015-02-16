#ifndef UNITTEST_H
#define UNITTEST_H

class UnitTest
{
public:
    UnitTest(bool iVerbose = true);

    virtual bool test();

protected:
    bool mVerbose;

    bool verbose()
    { return mVerbose; }
};

#endif // UNITTEST_H
