//
// Created by duongang on 12/6/2024.
//

#ifndef HISTORY_H
#define HISTORY_H
#include "../Command.h"

class HistoryCommand : public Command {
public:
  HistoryCommand(const std::vector<std::string>& args) : Command(args) {
  }

  int Run() override;
};

#endif //HISTORY_H
