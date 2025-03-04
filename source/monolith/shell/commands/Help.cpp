//
// Created by duongang on 12/6/2024.
//

#include "Help.h"
#include <map>
#include <iostream>

const std::map<std::string, std::string> CommandNameToDescription = {
  {"List all commands are available in shell",""},
  { "exit", "Exit the shell." },
  { "help", "Output the list of available commands or info about a specific command. Usage: `help [command_name]`" },
  { "history", "Output last N commands (default N: 5). Usage: `history [n]`" },
  { "ls", "Lists all files in the working directory." },
  { "cd", "Changes the working directory. Usage: `cd <directory_path>` (path is mandatory)" },
  { "pwd", "Prints the path to the working directory." },
  { "run", "Runs the executable and times execution. Usage: `run [program_name]`"}
};

int HelpCommand::Run() {
  try {
    switch (this->args_.size()) {
      case 0: {
        for (auto it = CommandNameToDescription.begin();
          it != CommandNameToDescription.end();
          ++it) {
          std::cout << "- " << it->first << ": " << it->second << std::endl;
          }
        return 0;
      }
      case 1: {
        auto command_name = this->args_[0];
        auto it = CommandNameToDescription.find(command_name);
        if (it != CommandNameToDescription.end()) {
          std::cout << "- " << command_name << ": " << CommandNameToDescription.at(command_name)
            << std::endl;
          return 0;
        }
        std::cout << "No command name was found: " << command_name << std::endl;
        return 1;
      }
      default: {
        std::cout << "Too many arguments for `help` command (<= 1 expected)" << std::endl;
        return 2;
      }
    }
  } catch (const std::exception& e) {
    std::cout << "An error has occurred when running the command: " << e.what() << std::endl;
    return -2;
  }
}