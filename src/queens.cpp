#include <algorithm>

#include "queens.h"

using namespace std;

UnitTest::TestResult Queens::test()
{
    const int MAX_BOARD_SIZE = 5;

    // board size =>           0,1,2,3,4, 5,6, 7, 8,  9, 10
    int expectedSolutions[] = { 1,1,0,0,2,10,4,40,92,352,724 };

    //! Run the queens algorithm for each size
    for (int i = 0; i <= MAX_BOARD_SIZE; i++) {
        mSet.clear();
        mCount = 0;

        // Run the problem
        Board b(i);
        placeQueens(b, i);

        // Output results
        int solutions = (int)mSet.size();
        if (mVerbose)
            cout << "Board size " << i << " has " << solutions << " solutions of " << mCount << " attempts." << endl;

        // Report any errors
        if (solutions != expectedSolutions[i])
            return TestResult::FAIL;
    }

    return TestResult::PASS;
}

void Queens::saveBoard(Board &b, bool verbose)
{
    stringstream ss;
    b.printQueens(ss);
    string result = ss.str();

    // record the attempt
    mCount++;

    // Save the solution if it is unique and new
    if (mSet.find(result) == mSet.end()) {
        mSet.insert(result);

        if (verbose) {
            stringstream ssv;
            b.printFull(ssv);
            cout << ssv.str();
        }
    }
}

bool Queens::placeQueens(Board &b, int nQueens)
{
    // base case for solved board
    if (nQueens == 0) {
        saveBoard(b, mVerbose);
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
    for (int i = 0; i < numEmpty; i++) {
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
        return placeQueens(bCopy, nQueens - 1);
    }

    return false;
}