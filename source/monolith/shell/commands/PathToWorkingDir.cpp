//
// Created by duongang on 12/6/2024.
//

#include "PathToWorkingDir.h"
#include <iostream>
#include "../utils/Path.h"

int PathToWorkingDirectoryCommand::Run() {
  auto [pwd_string, pwd_status_code] = pwd();

  if (pwd_status_code != 0) {
    std::cout << "Error: ";
  }

  std::cout << pwd_string << std::endl;

  return pwd_status_code;
}