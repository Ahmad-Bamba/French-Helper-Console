#pragma once

#include <string>

class InputHandler {
    int m_status;
    bool m_debug;
    void CommandToLower(std::string& x);
public:
    InputHandler(bool debug = false);
    void Run();
    int GetStatus();
    void Clean();
};
