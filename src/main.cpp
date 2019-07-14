#include "../include/Particle.h"
#include "../include/ParticleSwarm.h"
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

  ParticleSwarm swarm;

  int elapsed = SDL_GetTicks();

  while (true) {
    int elapsed = SDL_GetTicks();

    swarm.update(elapsed);

    const Particle *const particles = swarm.getParticles();

    for (int i = 0; i < ParticleSwarm::NPARTICLES; i++) {
      Particle particle = particles[i];

      int x = (particle.x_ + 1) * (Screen::SCREEN_WIDTH / 2);
      int y =
          (particle.y_) * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT / 2;

      screen.setPixel(x, y, 255, 0, 0);
    };

    if (screen.processEvents()) {
      break;
    }

    screen.update();
  }

  screen.destroyScreen();

  return 0;
}