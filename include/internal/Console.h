#pragma once

#include <memory>

enum class OPERATING_SYSTEM { WINDOWS, UNIX, MAC, CYGWIN };

class Console {
    OPERATING_SYSTEM GetOS();
    static Console* s_instance;
public:
    Console() = default;
    //Console(Console*& copy);
    ~Console();

    int GetWindowHeight();
    int GetWindowWidth();
    static Console* GetInstance();
};
