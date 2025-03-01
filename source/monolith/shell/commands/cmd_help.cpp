//
// Created by TGDD on 2/21/2025.
//

#include "cmd_help.h"
#include <iostream>

using namespace std;

void handleHelp(istringstream& iss) {
    cout << "Available commands:\n";
    cout << "  echo [message]   - Print message to the screen\n";
    cout << "  cd [directory]   - Change current directory\n";
    cout << "  help             - Show available commands\n";
    cout << "  exit             - Exit the shell\n";
    cout << "\n";
}
