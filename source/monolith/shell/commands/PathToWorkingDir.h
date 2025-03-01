//
// Created by duongang on 12/6/2024.
//

#ifndef PATHTOWORKINGDIR_H
#define PATHTOWORKINGDIR_H

#include "../Command.h"

class PathToWorkingDirectoryCommand : public Command {
public:
  PathToWorkingDirectoryCommand(const std::vector<std::string>& args) : Command(args) {
  }

  int Run() override;
};
#endif //PATHTOWORKINGDIR_H
