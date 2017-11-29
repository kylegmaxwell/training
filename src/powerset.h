#pragma once

#include "unittest.h"
#include <queue>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <sstream>

class PowerSet : public UnitTest
{
public:
    PowerSet();

    typedef std::vector<std::string> StringList;

    void makePowerSetRecursive(StringList startSet, std::string element, StringList &powerSet);

    void makePowerSetIterative(StringList startSet, StringList &powerSet);

    void printSet(std::ostream &stream, StringList &set);

    virtual TestResult test();
};
