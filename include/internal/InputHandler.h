#pragma once

class InputHandler {
    int m_status;
    bool m_debug;
public:
    InputHandler(bool debug = false);
    void Run();
    int GetStatus();
    void Clean();
};
