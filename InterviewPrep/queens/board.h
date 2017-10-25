#ifndef QUEENS_BOARD_H
#define QUEENS_BOARD_H

#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_set>
#include <unordered_map>

#include "../unittest.h"
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

#endif // QUEENS_BOARD_H
