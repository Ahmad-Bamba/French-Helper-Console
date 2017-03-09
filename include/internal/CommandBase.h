#pragma once

#include <string>
#include <functional>
#include <vector>

class CommandBase {
    std::string m_name;
protected:
    std::vector<std::string> m_args;
public:
    CommandBase(std::string name, std::vector<std::string> args);
    std::string GetName();

    virtual void Run() = 0;
};
