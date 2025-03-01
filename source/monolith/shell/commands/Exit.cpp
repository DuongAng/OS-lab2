//
// Created by duongang on 12/6/2024.
//

#include "Exit.h"
#include <iostream>

int ExitCommand::Run() {
  if (this->shell_ == nullptr) {
    std::cout << "This command requires a shell to run." << std::endl;
    return -1;
  }
  std::cout << "Exiting shell..." << std::endl;
  shell_->Stop();
  return 0;
}