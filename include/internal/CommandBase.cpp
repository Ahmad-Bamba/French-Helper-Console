#include "CommandBase.h"

CommandBase::CommandBase(std::string name, std::vector<std::string> args) {
    m_name = name;
    m_args = args;
}

std::string CommandBase::GetName() { return m_name; }
