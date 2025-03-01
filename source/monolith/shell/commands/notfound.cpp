//
// Created by TGDD on 2/21/2025.
//

#include "notfound.h"
#include <iostream>

using namespace  std;
void handleNot(istringstream& iss) {
    string message;
    getline(iss,message);
    cout << "Error: Command not found " + message << endl;
}