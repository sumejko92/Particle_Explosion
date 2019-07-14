#include "../include/Particle.h"
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

  Particle particle;
  int x = (particle.x_ + 1) * (Screen::SCREEN_WIDTH / 2);
  int y = (particle.y_) * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT / 2;

  while (true) {
    screen.update();

    screen.setPixel(x, y, 255, 0, 0);

    if (screen.processEvents()) {
      break;
    }
  }

  screen.destroyScreen();

  return 0;
}