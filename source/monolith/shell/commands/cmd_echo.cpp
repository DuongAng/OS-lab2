//
// Created by TGDD on 2/21/2025.
//
#include "cmd_echo.h"
#include <iostream>

using namespace std;

void handleEcho(istringstream& iss) {
    string message;
    getline(iss, message);
    cout << message << endl;
}
