//
// Created by duongang on 12/6/2024.
//

#include "History.h"
#include <iostream>

static int PrintHistory(std::stack<std::string>& history_stack, size_t history_size);

int HistoryCommand::Run() {
  if (this->shell_ == nullptr) {
    std::cout << "This command requires a shell to run." << std::endl;
    return -1;
  }

  size_t history_size = 5;
  std::stack<std::string> history = this->shell_->GetHistory();

  try {
    switch (this->args_.size()) {
      case 0: {
        return PrintHistory(history, history_size);
      }
      case 1: {
        int history_size_parsed = std::stoi(this->args_[0]);
        if (history_size_parsed < 0) {
          std::cout << "Cannot print a negative number of history entries." << std::endl;
          return 1;
        }
        history_size = static_cast<size_t>(history_size_parsed);
        return PrintHistory(history, history_size);
      }
      default: {
        std::cout << "Too many arguments for `history` command (<= 1 expected)" << std::endl;
        return 2;
      }
    }
  } catch (const std::exception& e) {
    std::cout << "An error has occurred when running the command: " << e.what() << std::endl;
    return -2;
  }
}

static int PrintHistory(std::stack<std::string>& history_stack, size_t history_size) {
  history_size = std::min(history_size, history_stack.size());

  if (history_size == 0) {
    std::cout << "History is empty." << std::endl;
    return 0;
  }

  // Copy stack (?)
  auto temp_history_stack = std::stack(history_stack);

  for (size_t i = 0; i < history_size; ++i) {
    auto elem = temp_history_stack.top();
    std::cout << "- " << elem << std::endl;
    temp_history_stack.pop();
  }

  return 0;
}