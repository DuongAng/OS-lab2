//
// Created by duongang on 12/6/2024.
//

#include "ChangeDir.h"
#include <iostream>
#include "../utils/Path.h"

int ChangeDirectoryCommand::Run() {
  if (this->shell_ == nullptr) {
    std::cout << "This command requires a shell to run." << std::endl;
    return -1;
  }

  if (this->args_.size() != 1) {
    std::cout << "Error: Wrong arguments count for command `cd` (1 expected)" << std::endl;
    return 3;
  }

  auto [pwd_string, pwd_status_code] = cd(this->args_[0]);

  if (pwd_status_code) {
    std::cout << "Error: " << pwd_string << std::endl;
    return pwd_status_code;
  }

  this->shell_->SetWorkingDirectory(pwd_string);
  return 0;
}