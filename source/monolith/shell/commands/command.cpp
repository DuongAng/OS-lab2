#include "command.h"
#include "cmd_echo.h"
#include "cmd_cd.h"
#include <iostream>
#include <sstream>
#include <windows.h>

#include "cmd_help.h"
#include "notfound.h"

using namespace std;

void executeCommand(const string& command) {
    istringstream iss(command);
    string cmd;
    iss >> cmd;

    if (cmd == "echo") {
        handleEcho(iss);
        return;
    } else if (cmd == "cd") {
        handleCd(iss);
        return;
    } else if (cmd == "help") {
        handleHelp(iss);
    } else {
        handleNot(iss);
        return;
    }
}
