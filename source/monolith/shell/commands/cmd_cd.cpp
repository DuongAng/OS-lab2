//
// Created by TGDD on 2/21/2025.
//
#include "cmd_cd.h"
#include <iostream>
#include <windows.h>

using namespace std;

void handleCd(istringstream& iss) {
    string path;
    iss >> path;

    if (SetCurrentDirectory(path.c_str())) {
        cout << "Changed directory to " << path << endl;
    } else {
        cerr << "Failed to change directory!" << endl;
    }
}
