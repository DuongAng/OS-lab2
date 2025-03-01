// Shell.h
#ifndef SHELL_H
#define SHELL_H

#include <stack>
#include <string>

class Shell {
private:
  bool running_;
  inline static const std::string PromptString = "> ";
  std::stack<std::string> history_;
  std::string working_directory_;

  static Shell* instance_;

public:
  Shell();
  static Shell* getInstance();
  void Start();
  void Run();
  void Stop();
  std::stack<std::string>& GetHistory();
  std::string GetWorkingDirectory();
  void SetWorkingDirectory(const std::string&);
  static std::string ReadNextCommandString();
};

#endif //SHELL_H
