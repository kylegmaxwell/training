#ifndef HASHLETTER_H
#define HASHLETTER_H

#include <unordered_map>
#include <algorithm>

#include "unittest.h"

class HashLetter : public UnitTest
{
public:

    typedef std::unordered_map<char,int> CharIntMap;

    const static std::string Book;
    const static std::string Letter;

    HashLetter();

    virtual TestResult test();

    /*!
     * \brief countOccurrences Count the number of occurrences of each character in the given string using the map
     * \param countMap Mapping from character to number of occurrences
     * \param s String to search
     */
    void countOccurrences(CharIntMap &countMap, std::string s) ;

    void printHistogram(CharIntMap &map);
};

#endif // HASHLETTER_H
