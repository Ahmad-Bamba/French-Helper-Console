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
        Console::GetInstance()->PrintLn("DEBUG: Starting French Helper (Console) in Debug mode!");
        Console::GetInstance()->PrintLn("Screen is: " + std::to_string(Console::GetInstance()->GetWindowWidth()) + "x" + std::to_string(Console::GetInstance()->GetWindowHeight()));
    }
    Console::GetInstance()->Print("FR>");
    std::string x;
    Console::GetInstance()->GetInput(x);
    CommandToLower(x);
    if(m_debug)
        Console::GetInstance()->PrintLn(x, true, 2);
    if(x == "exit" || x == "quit" || x == "q")
        m_status = 0;
}

int InputHandler::GetStatus() { return m_status; }

void InputHandler::Clean() {
    //TODO clean assets
    if(m_debug) {
        for (auto s : Console::GetInstance()->GetInputs())
            Console::GetInstance()->Print(s + ", ");
    }
}

void InputHandler::CommandToLower(std::string& x) {
    for(int i = 0; i < x.size(); i++) {
        x[i] = static_cast<char>(std::tolower(static_cast<int>(x[i])));
    }
}
