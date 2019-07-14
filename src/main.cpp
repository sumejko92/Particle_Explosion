#include "../include/Screen.h"
#include <iostream>

using namespace std;

int main() {

  Screen screen;

  if (!screen.init()) {
    cout << "Error: could not initialize screen" << endl;
    screen.destroyScreen();
    return 1;
  }

  while (true) {
    screen.update();

    if (screen.processEvents()) {
      break;
    }
  }

  screen.destroyScreen();

  return 0;
}