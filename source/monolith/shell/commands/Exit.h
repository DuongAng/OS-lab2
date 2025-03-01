//
// Created by duongang on 12/6/2024.
//

#ifndef EXIT_H
#define EXIT_H
#include "../Command.h"

class ExitCommand : public Command {
public:
  ExitCommand(const std::vector<std::string>& args) : Command(args) {}

  int Run() override;
};

#endif //EXIT_H
