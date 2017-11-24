#pragma once

#ifdef _MSC_VER
#include <windows.h>
#include <sstream>
#include <iostream>
#define DEBUG_PRINT(STR) do {                   \
        std::stringstream ss;                   \
        ss << (STR) << std::endl;               \
        OutputDebugString(ss.str().c_str());    \
    } while(0)

#else

#define DEBUG_PRINT(STR) (std::cout << (STR) << std::endl )

#endif