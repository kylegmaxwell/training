#ifndef CONVERTBASE_H
#define CONVERTBASE_H

#include "unittest.h"
#include <iostream>
#include <string>

class ConvertBase : public UnitTest
{
public:
    ConvertBase();

    virtual TestResult test();

private:
    /*!
     * \brief Convert a number from one base to another.
     * \param baseIn The base that number is represented in
     * \param number The number to be converted
     * \param baseOut The new base to change the number into
     * \return The number after conversion to the new base
     */
    std::string convertBase(int baseIn, std::string number, int baseOut);
};

#endif // CONVERTBASE_H
