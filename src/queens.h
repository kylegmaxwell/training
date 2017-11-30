#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_set>
#include <unordered_map>

#include "unittest.h"
#include "board.h"

/*!
 * \brief The Queens class uses the queens board to solve the N Queens problem
 * http://en.wikipedia.org/wiki/Eight_queens_puzzle
 */
class Queens : public UnitTest
{
public:

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
    void saveBoard(Board &b, bool debug = false);

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
    std::unordered_set<std::string> mSet{};

    //! Total number of completed boards tested, either successful or failed
    int mCount{ 0 };
};
