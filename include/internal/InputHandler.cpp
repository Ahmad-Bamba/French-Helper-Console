#include <iostream>
#include <algorithm>
#include <cctype>

#include "InputHandler.h"
#include "Console.h"

InputHandler::InputHandler(bool debug) {
    m_debug = debug;
    m_status = -1;
}

void InputHandler::Run() {
    if(m_debug) {
        std::cout << "DEBUG: Starting French Helper (Console) in Debug mode!" << std::endl;
        std::cout << "Screen is: " << Console::GetInstance()->GetWindowWidth() << "x" << Console::GetInstance()->GetWindowHeight() << std::endl;
    }
    std::cout << "FR> ";
    std::string x;
    std::getline(std::cin, x);
    CommandToLower(x);
    std::cout << std::endl << x << std::endl;
    if(x == "exit" || x == "quit" || x == "q")
        m_status = 0;
}

int InputHandler::GetStatus() { return m_status; }

void InputHandler::Clean() {
    //TODO clean assets
}

void InputHandler::CommandToLower(std::string& x) {
    for(int i = 0; i < x.size(); i++) {
        x[i] = static_cast<char>(std::tolower(static_cast<int>(x[i])));
    }
}
