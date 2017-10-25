#ifndef QUEENS_H
#define QUEENS_H

#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_set>
#include <unordered_map>

#include "unittest.h"
/*!
 * \brief The Board class respresents an N x N chess board
 * to solve the problem of placing N Queens such that
 * the Queens do not attack each other.
 */
class Board {
public:

    //! \brief The TileState enum represents whether a queen has been placed, or can be placed
    enum TileState { QUEEN, ATTACKED, EMPTY };

    //! Create a chess board of a given size
    Board(int size);

    //! \brief Set the state at position row, col
    //! Also does some checking to prevent over writing of queens
    void setState(int row, int col, TileState state);

    //! Get the state of the board at a position
    TileState getState(int row, int col);

    //! print a visual record of the board
    void printFull(std::ostream &stream);

    //! print just the index of the queens
    //! Used to check uniqueness of solutions
    void printQueens(std::ostream &stream);

    /*!
     * \brief Find the nth empty tile
     * \param offset is how many places to skip to find the empty tile
     * \return true if a place was found
    */
    bool findEmpty(int &row, int &col, int offset=0);

    /*!
     * \brief Place a queen in the specified row and column,
     * and mark out all the squares which she attacks
     */
    void placeQueen(int row, int col);

    //! get the number of empty squares in the board
    int getNumEmpty();

    //! Get the length/width of the board in squares
    int getSize();

private:

    //! number of squares along one side of the baord
    int mSize;

    //! The elements of the board
    std::vector<TileState> mEntries;

    //! Number of spaces available in which to place queens
    int mNumEmpty;

    //! The index locations of where the queens have been placed
    std::vector<int> mQueens;
};


/*!
 * \brief The Queens class uses the queens board to solve the N Queens problem
 * http://en.wikipedia.org/wiki/Eight_queens_puzzle
 */
class Queens : public UnitTest
{
public:

    //! Default constructor
    Queens();

    /*!
     * \brief Polymorphic test function inherited from Unit Test.
     * Runs the queens problem on different board sizes and
     * checks for the right number of solutions.
     */
    virtual TestResult test();

    /*!
     * \brief When a solution is found the board state is cached
     * \param b The board that was successful
     */
    void saveBoard(Board &b, bool debug=false);

    /*!
     * \brief placeQueens calculates all possible solutions to the N Queens Problem
     * This function tries different initial placements and then calls placeQueensHelper,
     * which then places one queen and recursively calls placeQueens with one fewer queen to place
     * \param b The board to use
     * \param nQueens The size of the puzzle
     * \return true on success
     */
    bool placeQueens(Board &b, int nQueens);

    //! Parallel helper that places a queen at the nth free space as determined by offset
    bool placeQueensHelper(Board &b, int nQueens, int offset);

private:

    //! set of working solutions, used to remove exact duplicates
    std::unordered_set<std::string> mSet;

    //! Total number of completed boards tested, either successful or failed
    int mCount;

};

#endif // QUEENS_H
