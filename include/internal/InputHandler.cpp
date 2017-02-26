#include "InputHandler.h"
#include <iostream>

InputHandler::InputHandler(bool debug) {
    m_debug = debug;
    m_status = -1;
}

void InputHandler::Run() {
    std::cout << "Test pls remove" << std::endl;
    m_status = 0;
}

int InputHandler::GetStatus() { return m_status; }

void InputHandler::Clean() {
    //TODO clean assets
}
