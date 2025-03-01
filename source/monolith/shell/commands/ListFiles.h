//
// Created by duongang on 12/6/2024.
//

#ifndef LISTFILES_H
#define LISTFILES_H
#include "../Command.h"

class ListFilesCommand : public Command {
public:
  ListFilesCommand(const std::vector<std::string>& args) : Command(args) {
  }

  int Run() override;
};


#endif //LISTFILES_H
