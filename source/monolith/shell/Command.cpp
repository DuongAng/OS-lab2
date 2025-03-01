//
// Created by duongang on 12/6/2024.
//

#include "Command.h"
#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <functional>

#include "Shell.h"
void Command::BindToShell(Shell* shell) {
  shell_ = shell;
}

std::vector<std::string> Command::GetArgs() const {
  return args_;
}