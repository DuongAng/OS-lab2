//
// Created by duongang on 12/6/2024.
//

#include "Run.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <userenv.h>


LONGLONG GetCurrentTimeInMicroseconds() {
    LARGE_INTEGER frequency;
    LARGE_INTEGER counter;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&counter);

    return (counter.QuadPart * 1000000) / frequency.QuadPart;  // Convert to microseconds
}

int RunCommand::Run() {
    if (args_.empty()) {
        std::cout << "No binary specified to run." << std::endl;
        return 1;
    }

    std::string binary = args_[0];
    std::string command_line;

    // Join arguments into a single command line
    for (size_t i = 0; i < args_.size(); ++i) {
        command_line += args_[i];
        if (i != args_.size() - 1) {
            command_line += " ";
        }
    }

    // Set up the STARTUPINFO and PROCESS_INFORMATION structures
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    //get the token of the current process
    HANDLE hToken;
    if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ALL_ACCESS, &hToken)) {
      std::cout << "OpenProcessToken failed with error code " << GetLastError() << std::endl;
      return 2;
    }

    // Measure the start time
    LONGLONG start_time = GetCurrentTimeInMicroseconds();

    // Launch the binary as the user of the current process
  if (!CreateProcessAsUser(
          hToken,                        // User token
          nullptr,                       // No module name (use command line)
          const_cast<char*>(command_line.c_str()),  // Command line
          nullptr,                       // Process handle not inheritable
          nullptr,                       // Thread handle not inheritable
          FALSE,                         // Set handle inheritance to FALSE
          0,                             // No creation flags
          nullptr,                       // Use parent's environment block
          nullptr,                       // Use parent's starting directory
          &si,                           // Pointer to STARTUPINFO structure
          &pi)                           // Pointer to PROCESS_INFORMATION structure
  ) {
    const DWORD return_code = GetLastError();
    std::cout << "CreateProcessAsUser failed with error code " << return_code << std::endl;
    CloseHandle(hToken); // Close handle token
    return 2;
  }

    // Wait until child process exits
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Measure the end time
    LONGLONG end_time = GetCurrentTimeInMicroseconds();
    LONGLONG exec_time = end_time - start_time;

    // Output the execution time in milliseconds
    std::cout << "Execution time: " << (exec_time / 1000.0) << " ms" << std::endl;

    // Close process and thread handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    CloseHandle(hToken); // Close handle token

    return 0;
}

