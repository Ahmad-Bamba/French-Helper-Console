#pragma once

#include <memory>
#include <array>
#include <string>

enum class OPERATING_SYSTEM { WINDOWS, UNIX, MAC, CYGWIN };

class Console {
    OPERATING_SYSTEM GetOS();
    std::array<std::string, 20> m_inputs;
    static Console* s_instance;
public:
    Console();
    //Console(Console*& copy);
    ~Console();

    int GetWindowHeight();
    int GetWindowWidth();
    void GetInput(std::string& x);
    void Print(std::string x);
    void PrintLn(std::string x, bool on_new, int lines);
    void PrintLn(std::string x, int lines = 1);
    std::array<std::string, 20> GetInputs();
    static Console* GetInstance();
};
