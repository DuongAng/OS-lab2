//
// Created by duongang on 12/6/2024.
//

#ifndef RUN_H
#define RUN_H

#include "../Command.h"
class RunCommand : public Command {
public:
  RunCommand(const std::vector<std::string>& args) : Command(args) {
  }

  int Run() override;
};

#endif //RUN_H
