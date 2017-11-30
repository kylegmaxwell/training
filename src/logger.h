#pragma once

#include <iostream>
#include <sstream>

#ifdef _MSC_VER
#include <windows.h>
#endif

class Logger {
public:
    template <typename T>
    static void DEBUG_WORD(T in) {
        std::stringstream ss;
        ss << in;
#ifdef _MSC_VER
        OutputDebugString(ss.str().c_str());
#else
        std::cout << ss.str();
#endif
    }

    template <typename T>
    static void DEBUG(T in) {
        std::stringstream ss;
        ss << in << std::endl;
        DEBUG_WORD(ss.str());
    }

    static void ENDL() {
        DEBUG("");
    }
};
