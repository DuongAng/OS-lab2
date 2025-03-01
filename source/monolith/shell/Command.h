//
// Created by duongang on 12/6/2024.
//

#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>
#include "Shell.h"

class Command {
protected:
  std::vector<std::string> args_; // Arguments passed to the command
  Shell* shell_; // Pointer to Shell

public:
  Command(const std::vector<std::string>& args) : args_(args), shell_(nullptr) {}

  virtual ~Command() = default;

  void BindToShell(Shell* shell);

  virtual int Run() = 0;  // Pure virtual function to be implemented by derived classes

  std::vector<std::string> GetArgs() const;
};

#endif //COMMAND_H
