//
// Created by duongang on 12/6/2024.
//

#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include <memory>
#include <string>
#include <vector>

#include "../Command.h"

std::unique_ptr<Command> CommandFactory(
    const std::string& command_name, const std::vector<std::string>& args
);

std::vector<std::string> SplitString(const std::string& inp);

bool IsBlank(const std::string& inp);

std::string StringToLower(const std::string& inp);

#endif //COMMANDFACTORY_H
