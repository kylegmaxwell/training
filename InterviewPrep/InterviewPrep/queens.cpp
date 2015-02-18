#include <algorithm>

#include "queens.h"

using namespace std;

Queens::Queens() : UnitTest(false), mSet(), mCount(0)
{
}

UnitTest::TestResult Queens::test()
{
    // board size =>           0,1,2,3,4, 5,6, 7, 8,  9, 10
    int expectedSolutions[] = {1,1,0,0,2,10,4,40,92,352,724};

    //! Run the queens algorithm for each size
    for (int i = 0; i <= 8; i++) {
        mSet.clear();
        mCount = 0;

        // Run the problem
        Board b(i);
        placeQueens(b, i);

        // Output results
        int solutions = mSet.size();
        if (mVerbose)
            cout << "Board size "<< i << " has " << solutions << " solutions of " << mCount << " attempts." << endl;

        // Report any errors
        if (solutions != expectedSolutions[i])
            return FAIL;
    }

    return PASS;
}

void Queens::saveBoard(Board &b, bool debug)
{
    stringstream ss;
    if (debug)
        b.printFull(ss);
    else
        b.printQueens(ss);
    string result = ss.str();

    // record the attempt
    mCount++;

    // Save the solution if it is unique and new
    if (mSet.find(result)== mSet.end()) {
        mSet.insert(result);

        if (debug)
            cout << result;
    }
}

bool Queens::placeQueens(Board &b, int nQueens)
{
    // base case for solved board
    if (nQueens == 0) {
        saveBoard(b, false);
        return true;
    }

    int numEmpty = b.getNumEmpty();
    // Placement of queens is not possible
    if (numEmpty < nQueens) {
        mCount++; // record attempt
        return false;
    }

    bool foundPlacement = false;

    // optimization
    int maxSize = nQueens; // dont process repeat solutions
    if (numEmpty > maxSize)
        numEmpty = maxSize;

    // try every possible move
    for (int i=0; i<numEmpty; i++) {

        // Copy the board so the recursive call will not overwrite parent's data
        Board bCopy = b;
        if (placeQueensHelper(bCopy, nQueens, i))
            foundPlacement = true;

    }
    return foundPlacement;
}

bool Queens::placeQueensHelper(Board &b, int nQueens, int offset)
{
    // base case for solved board
    if (nQueens == 0) {
        saveBoard(b);
        return true;
    }

    // Copy the board so the recursive call will not overwrite parent's data
    Board bCopy = b;

    // Find the nth next empty cell
    int row, col;
    if (bCopy.findEmpty(row, col, offset)) {
        bCopy.placeQueen(row, col);

        // Solve the problem with one fewer queen to place
        return placeQueens(bCopy, nQueens-1);
    }

    return false;
}

Board::Board(int size) : mSize(size),
    mEntries(size*size, EMPTY),
    mNumEmpty(size*size),
    mQueens()
{
}

void Board::setState(int row, int col, Board::TileState state)
{
    TileState oldState = getState(row, col);
    // Never overwrite queen
    if (oldState == QUEEN)
        return;

    // An empty tile is filled
    if ((state == QUEEN || state == ATTACKED) && (oldState == EMPTY)) {
        mNumEmpty--;
    }

    // A new queen has been placed, record it
    if (state == QUEEN && oldState != QUEEN)
        mQueens.push_back(row * mSize + col);

    // Set the actual value in the array, convert from two to one dimensional indexing
    mEntries[row * mSize + col] = state;
}

Board::TileState Board::getState(int row, int col)
{
    // return the entry after converting from 2D to 1D indexing
    return mEntries[row * mSize + col];
}

void Board::printFull(std::ostream &stream)
{
    // Iterate over entire board
    for (int r = 0; r < mSize; r++) {
        for (int c = 0; c < mSize; c++) {

            // Select the appropriate character for the square
            switch(getState(r,c)) {
            case QUEEN: {
                stream << "Q";
                break;
            }
            case ATTACKED: {
                stream << "x";
                break;
            }
            case EMPTY:
            default: {
                stream << ".";
                break;
            }
            }
            stream << " ";
        }
        stream << endl;
    }
    stream << endl;
}

void Board::printQueens(std::ostream &stream) {

    // Sort so that equivalent solutions compare equal as strings
    std::sort(mQueens.begin(), mQueens.end());

    // Write out the queens placement as a string
    for (auto itr = mQueens.begin(); itr != mQueens.end(); itr++) {
        int index = *itr;
        stream << index << " ";
    }
    stream << endl;
}

bool Board::findEmpty(int &row, int &col, int offset)
{
    for (int r = 0; r < mSize; r++) {
        for (int c = 0; c < mSize; c++) {

            // check if an empty cell has been found
            if (getState(r,c) == EMPTY ) {

                // Check whether to select this empty cell
                if (offset == 0) {
                    row = r;
                    col = c;
                    return true;
                }
                else { // skip this empty cell
                    offset--;
                }
            }
        }
    }
    return false;
}

void Board::placeQueen(int row, int col)
{
    // setState will not overwrite cells set to Queen
    setState(row, col, QUEEN);

    // rook

    // attack row
    for (int r = 0; r < mSize; r++) {
        setState(r, col, ATTACKED);
    }
    // attack col
    for (int c = 0; c < mSize; c++) {
        setState(row, c, ATTACKED);
    }

    // bishop

    // first diagonal
    int pMin = std::min<int>(row,col);
    int r0 = row - pMin;
    int c0 = col - pMin;

    while (r0 < mSize && c0 < mSize ) {
        setState(r0,c0,ATTACKED);
        r0++;
        c0++;
    }

    // second diagonal
    r0 = row - 1;
    c0 = col + 1;
    while (r0 >= 0 && c0 < mSize) {
        setState(r0, c0, ATTACKED);
        r0--;
        c0++;
    }
    r0 = row + 1;
    c0 = col - 1;
    while (r0 < mSize && c0 >= 0) {
        setState(r0, c0, ATTACKED);
        r0++;
        c0--;
    }
}

int Board::getNumEmpty()
{
    return mNumEmpty;
}

int Board::getSize()
{
    return mSize;
}
