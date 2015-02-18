#ifndef QUEENS_H
#define QUEENS_H

#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <map>

#include "unittest.h"

// Represents one tile on the chess board
//struct Tile {
//    int row;
//    int col;
//};


class Board {
public:
    enum TileState { QUEEN, ATTACKED, EMPTY };

    Board(int size);

    void setState(int row, int col, TileState state);

    TileState getState(int row, int col);

    void print(std::ostream &stream);

    // offset is how many places to skip to find the empty
    // return true if a place was found
    bool findEmpty(int &row, int &col, int offset=0);

    void placeQueen(int row, int col);

    int getNumEmpty();

private:

    int mSize;
    std::vector<TileState> mEntries;
    int mNumEmpty;
};



class Queens : public UnitTest
{
public:

    Queens();

    virtual TestResult test();

    void saveBoard(Board &b);

    // return true on success
    bool placeQueens(Board &b, int nQueens);
    bool placeQueensHelper(Board &b, int nQueens, int offset);

private:
    std::set<std::string> mSet;
};

#endif // QUEENS_H
