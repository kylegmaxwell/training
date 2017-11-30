#include "powerset.h"

using namespace std;

void PowerSet::makePowerSetRecursive(StringList startSet, string element, StringList &powerSet)
{
    if (startSet.empty()) {
        powerSet.push_back(element);
        return;
    }

    // extract first element of start set
    string newElem = startSet.back();
    startSet.pop_back();

    // make subsets not containing the element
    makePowerSetRecursive(startSet, element, powerSet);

    // make subsets containing the element
    element.append(newElem);
    makePowerSetRecursive(startSet, element, powerSet);
}

void PowerSet::makePowerSetIterative(PowerSet::StringList startSet, PowerSet::StringList &powerSet)
{
    powerSet.push_back("");

    // base case: bail if start set is empty
    while (!startSet.empty()) {
        // extract first element of start set
        string elem = startSet.back();
        startSet.pop_back();

        // double the set
        size_t size = powerSet.size();

        // add set without element
        // keep what is already in power set

        // add set with element
        // duplicate each element and add new element
        for (size_t i = 0; i < size; i++) {
            string newElem = powerSet[i];
            newElem.append(elem);
            powerSet.push_back(newElem);
        }
    }
}

void PowerSet::printSet(ostream &stream, StringList &set)
{
    sort(set.begin(), set.end(),
        [](const string &a, const string &b) -> bool {
        if (a.size() == b.size())
            return a < b;
        else
            return a.size() < b.size();
    }
    );

    //cout << "Power Set:" << endl;
    for (auto itr = set.begin(); itr != set.end(); itr++) {
        stream << "'" << *itr << "' ";
    }
}

UnitTest::TestResult PowerSet::test()
{
    string expectedResult = "'' 'A' 'B' 'C' 'AB' 'AC' 'BC' 'ABC' ";

    StringList startSet;
    startSet.push_back("A");
    startSet.push_back("B");
    startSet.push_back("C");

    reverse(startSet.begin(), startSet.end());

    StringList powerSet1;
    makePowerSetIterative(startSet, powerSet1);

    stringstream ss1;
    printSet(ss1, powerSet1);
    if (!stringEqual(ss1.str(), expectedResult))
        return FAIL;

    StringList powerSet2;
    makePowerSetRecursive(startSet, "", powerSet2);

    stringstream ss2;
    printSet(ss2, powerSet2);
    if (!stringEqual(ss2.str(), expectedResult))
        return FAIL;

    return PASS;
}