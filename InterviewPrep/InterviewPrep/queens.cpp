#include "queens.h"

using namespace std;

Queens::Queens()
{
}

UnitTest::TestResult Queens::test()
{
    for (int i = 0; i < 10; i++) {
        mSet.clear();
        Board b(i);
        placeQueens(b, i);
        cout << "Number of "<< i << " solutions " << mSet.size() << endl;
    }

//    Number of 0 solutions 1
//    Number of 1 solutions 1
//    Number of 2 solutions 0
//    Number of 3 solutions 0
//    Number of 4 solutions 2
//    Number of 5 solutions 10
//    Number of 6 solutions 4
//    Number of 7 solutions 40
//    Number of 8 solutions 92

    return FAIL;
}

void Queens::saveBoard(Board &b)
{
    stringstream ss;
    b.print(ss);
    string result = ss.str();
    if (mSet.find(result)== mSet.end()) {
        mSet.insert(result);
        //cout << result;
    }
}

bool Queens::placeQueens(Board &b, int nQueens)
{
    if (nQueens == 0) {
        saveBoard(b);
        return true;
    }

    int numEmpty = b.getNumEmpty();

    if (numEmpty < nQueens)
        return false;

    bool foundPlacement = false;
    // try every possible move
    for (int i=0; i<numEmpty; i++) {

        Board bCopy = b;
        if (placeQueensHelper(bCopy, nQueens, i))
            foundPlacement = true;

    }
    return foundPlacement;
    //return false;
}

bool Queens::placeQueensHelper(Board &b, int nQueens, int offset)
{
    if (nQueens == 0) {
        saveBoard(b);
        return true;
    }

    Board bCopy = b;
    int row, col;
    if (bCopy.findEmpty(row, col, offset)) {
        bCopy.placeQueen(row, col);
        //bool foundPlacement = false;
        //int numEmpty = bCopy.getNumEmpty();
        //cout << numEmpty << endl;
        //for (int i = 0; i < numEmpty; i++) {
        //    if (placeQueensHelper(bCopy, nQueens-1, 0))
        //        foundPlacement = true;
        //}
        //return foundPlacement;

        return placeQueens(bCopy, nQueens-1);
        //return placeQueensHelper(bCopy, nQueens-1,0);
    }
    else {
        return false;
    }
}

Board::Board(int size) : mSize(size),
    mEntries(size*size, EMPTY),
    mNumEmpty(size*size)
{
    //cout << mEntries.size() << endl;
}

void Board::setState(int row, int col, Board::TileState state)
{
    TileState oldState = getState(row, col);
    if (oldState == QUEEN)
        return;
    if ((state == QUEEN || state == ATTACKED) && (oldState == EMPTY))
        mNumEmpty--;
    mEntries[row * mSize + col] = state;
}

Board::TileState Board::getState(int row, int col)
{
    return mEntries[row * mSize + col];
}

void Board::print(std::ostream &stream)
{
    for (int r = 0; r < mSize; r++) {
        for (int c = 0; c < mSize; c++) {
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

bool Board::findEmpty(int &row, int &col, int offset)
{
    for (int r = 0; r < mSize; r++) {
        for (int c = 0; c < mSize; c++) {
            if (getState(r,c) == EMPTY ) {
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

    setState(row, col, QUEEN);

    // rook

    // attack row
    for (int r = 0; r < mSize; r++) {
        //if (r != row)
            setState(r, col, ATTACKED);
    }
    // attack col
    for (int c = 0; c < mSize; c++) {
        //if (c != col)
            setState(row, c, ATTACKED);
    }

    // bishop

    //if (row >= col) {
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
