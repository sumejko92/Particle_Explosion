#include "../include/Screen.h"
#include <iostream>

using namespace std;

int main() {

  Screen screen;

  if (!screen.init()) {
    cout << "Error: could not initialize screen" << endl;
    return 1;
  }

  return 0;
}