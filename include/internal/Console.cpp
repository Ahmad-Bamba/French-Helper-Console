#include <iostream>

#include "Console.h"

#ifdef WIN64
#include <windows.h>
#define WINDOWS_INCLUDED
#elif WIN32
#include <windows.h>
#define WINDOWS_INCLUDED
#else
#include <unistd.h>
#include <sys/ioctl.h>
#endif

Console* Console::s_instance = nullptr;

Console::Console() {
    m_inputs.fill("");
}

Console::~Console() {
    delete s_instance;
}

OPERATING_SYSTEM Console::GetOS() {
#ifdef WIN64
    return OPERATING_SYSTEM::WINDOWS;
#elif WIN32
    return OPERATING_SYSTEM::WINDOWS;
#elif __unix__
    return OPERATING_SYSTEM::UNIX;
#elif __CYGWIN__
    return OPERATING_SYSTEM::CYGWIN;
#elif __APPLE__
    return OPERATING_SYSTEM::MAC;
#endif
}

int Console::GetWindowHeight() {
    int height = 0;
    switch(GetOS()) {
        case OPERATING_SYSTEM::CYGWIN:
        case OPERATING_SYSTEM::MAC:
        case OPERATING_SYSTEM::UNIX:
#ifndef WINDOWS_INCLUDED
            struct winsize w;
            ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
            height = w.ws_row;
            //delete &w;
#endif
            break;
        case OPERATING_SYSTEM::WINDOWS:
#ifdef WINDOWS_INCLUDED
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
            height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
            //delete &csbi;
#endif
            break;
    }
    //std::cout << "Returning " << height << __LINE__ << std::endl;
    return height;
}

int Console::GetWindowWidth() {
    int width = 0;
    switch(GetOS()) {
        case OPERATING_SYSTEM::CYGWIN:
        case OPERATING_SYSTEM::MAC:
        case OPERATING_SYSTEM::UNIX:
#ifndef WINDOWS_INCLUDED
            struct winsize w;
            ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
            width = w.ws_col;
            //delete &w;
#endif
            break;
        case OPERATING_SYSTEM::WINDOWS:
#ifdef WINDOWS_INCLUDED
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
            width = csbi.srWindow.Right - csbi.srWindow.Top + 1;
            //delete &csbi;
#endif
            break;
    }
    //std::cout << "Returning " << width << __LINE__ << std::endl;
    return width;
}

void Console::Print(std::string x) {
    std::cout << x;
}

void Console::PrintLn(std::string x, bool on_new, int lines) {
    if(on_new)
        std::cout << std::endl;
    std::cout << x;
    for(int i = 0; i < lines; i++)
        std::cout << std::endl;
}

void Console::PrintLn(std::string x, int lines) {
    std::cout << x;
    for(int i = 0; i < lines; i++)
        std::cout << std::endl;
}

void Console::GetInput(std::string &x) {
    for(int i = 0; i < m_inputs.size() - 1; i++) {
        m_inputs[i] = m_inputs[i + 1];
    }
    std::getline(std::cin, x);
    m_inputs[m_inputs.size() - 1] = x;
}

Console* Console::GetInstance() {
    if(s_instance == nullptr)
        s_instance = new Console();
    return s_instance;
}

std::array<std::string, 20> Console::GetInputs() {
    return m_inputs;
}
