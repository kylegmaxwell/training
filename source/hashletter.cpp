#include "hashletter.h"

using namespace std;

const string HashLetter::Book("The Time Traveller (for so it will be convenient to speak of him) was expounding a recondite matter to us. His grey eyes shone and twinkled, and his usually pale face was flushed and animated. The fire burned brightly, and the soft radiance of the incandescent lights in the lilies of silver caught the bubbles that flashed and passed in our glasses. Our chairs, being his patents, embraced and caressed us rather than submitted to be sat upon, and there was that luxurious after-dinner atmosphere when thought roams gracefully free of the trammels of precision. And he put it to us in this way—marking the points with a lean forefinger—as we sat and lazily admired his earnestness over this new paradox (as we thought it) and his fecundity. Public Domain https://www.gutenberg.org/cache/epub/35/pg35-images.html");
const string HashLetter::Letter("You are going to die");

HashLetter::HashLetter() : UnitTest(false)
{
}


UnitTest::TestResult HashLetter::test()
{
    CharIntMap bookMap;
    countOccurrences(bookMap, Book);

    if (mVerbose)
        printHistogram(bookMap);

    CharIntMap letterMap;
    countOccurrences(letterMap, Letter);

    if (mVerbose)
        printHistogram(letterMap);

    // Check to see if the book contains more of each character in the letter
    bool canPrint = true;
    for (auto itr = letterMap.begin(); itr != letterMap.end(); itr++) {
        char c = itr->first;
        int letterCount = itr->second;

        int bookCount = bookMap[c];
        if (letterCount > bookCount ) {
            canPrint = false;
        }
        if (mVerbose) {
            cout << "The letter needs " << letterCount << " '" << c
                 << "'s, and the book has " << bookCount << "." << endl;
        }
    }
    if (!canPrint)
        return FAIL;

    return PASS;
}

void HashLetter::countOccurrences(CharIntMap &countMap, string s)
{
    for (auto itr = s.begin(); itr != s.end(); itr++) {
        char c = *itr;
        c = tolower(c);

        if (countMap.find(c) == countMap.end()) {
            countMap[c] = 1;
        }
        else {
            countMap[c]++;
        }

    }
}

void HashLetter::printHistogram(CharIntMap &map)
{
    typedef pair<char,int> CharInt;
    vector<CharInt> histogram;

    for (auto itr = map.begin(); itr != map.end(); itr++) {
        char c = itr->first;
        int i = itr->second;
        //cout << itr->first << ": " << itr->second << endl;
        histogram.push_back(CharInt(c, i));
    }

    // Sort the vector by number of occurrences
    sort(histogram.begin(), histogram.end(),
        [] (const CharInt &a, const CharInt &b) { return a.second < b.second; }
    );

    // Print the sorted vector
    for (auto itr = histogram.begin(); itr != histogram.end(); itr++) {
        pair<char, int> p = *itr;
            cout << p.first << ": " << p.second << endl;
    }
}
