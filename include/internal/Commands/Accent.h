#pragma once

#include "../CommandBase.h"

class Accent : public CommandBase {
public:
    Accent(std::vector<std::string> args);
    void Run() override final;
};
