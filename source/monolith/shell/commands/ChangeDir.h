//
// Created by duongang on 12/6/2024.
//

#ifndef CHANGEDIR_H
#define CHANGEDIR_H

#include "../Command.h"

class ChangeDirectoryCommand : public Command {
public:
  ChangeDirectoryCommand(const std::vector<std::string>& args) : Command(args) {
  }

  int Run() override;
};

#endif //CHANGEDIR_H
