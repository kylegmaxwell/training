#include <math.h>
#include <unordered_map>
#include <sstream>
#include <vector>

#include "convertbase.h"

using namespace std;

UnitTest::TestResult ConvertBase::test()
{
    if (mVerbose)
        cout << "convert base" << endl;

    TestResult state = TestResult::PASS;
    string begin = "A08";

    string result = convertBase(16, begin, 2);
    string expectedResult = "101000001000";
    if (!stringEqual(result, expectedResult))
        state = TestResult::FAIL;

    string result2 = convertBase(2, result, 16);
    if (!stringEqual(begin, result2))
        state = TestResult::FAIL;

    string result3 = convertBase(16, begin, 8);
    if (!stringEqual(result3, "5010"))
        state = TestResult::FAIL;

    string result4 = convertBase(7, "615", 13);
    if (!stringEqual(result4, "1A7"))
        state = TestResult::FAIL;

    return state;
}

// Assumptions
// Number is an integer
// Hex uses capital letters
string ConvertBase::convertBase(int baseIn, string number, int baseOut)
{
    // check if the string is a valid number
//TODO

    // check if the base is between 2 and 16
//TODO

    // check for negative and remove from string
//TODO

    std::unordered_map<char, int> charToInt;
    std::unordered_map<int, char> intToChar;
    for (int i = 0; i < 10; i++) {
        char c = i + '0';
        charToInt[c] = i;
        intToChar[i] = c;
    }
    for (int i = 0; i < 6; i++) {
        char c = i + 'A';
        charToInt[c] = i + 10;
        intToChar[i + 10] = c;
    }

    // the value of the number string as an integer
    int value = 0;

    // convert the number from a string to an int using base
    int multiplier = 1;
    for (int i = (int)number.size() - 1; i >= 0; i--) {
        char c = number[i];
        int digitValue = charToInt[c];
        value += digitValue * multiplier;
        multiplier *= baseIn;
    }

    // convert the integer to a string in the new base
    std::vector<char> numberChars;
    multiplier = 1;
    int shifted = 0;
    do {
        shifted = value / multiplier;
        int digit = shifted % baseOut;

        numberChars.push_back(intToChar[digit]);
        multiplier *= baseOut;
    } while (shifted > 0);

    // reverse
    stringstream ss;
    // start at one before the last character, to drop extra zero
    for (int i = (int)numberChars.size() - 2; i >= 0; i--) {
        char digit = numberChars[i];
        ss << digit;
    }

    return ss.str();
}