//
// Created by duongang on 11/25/2024.
//

#include "../shell/Shell.h"

namespace monolith::app {
void Main() {
  auto shell = Shell();
  shell.Start();
}
}  // namespace monolith::app

int main() {
  monolith::app::Main();
}
