//
// Created by duongang on 12/6/2024.
//

#ifndef HELP_H
#define HELP_H

#include "../Command.h"

class HelpCommand : public Command {
public:
  explicit HelpCommand(const std::vector<std::string>& args) : Command(args) {}

  int Run() override;
};


#endif //HELP_H
