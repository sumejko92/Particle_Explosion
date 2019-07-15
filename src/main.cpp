#include "../include/Particle.h"
#include "../include/ParticleSwarm.h"
#include "../include/Screen.h"
#include <chrono>
#include <iostream>

using namespace std;
using milli = std::chrono::milliseconds;

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
    // auto start = std::chrono::high_resolution_clock::now();

    int elapsed = SDL_GetTicks();

    screen.clear();
    swarm.update(elapsed);

    // generate changing color based on ticks
    double green = (1 + sin(elapsed * 0.001)) * 128;
    double red = (1 + sin(elapsed * 0.002)) * 128;
    double blue = (1 + sin(elapsed * 0.003)) * 128;

    const Particle *const particles = swarm.getParticles();

    for (int i = 0; i < ParticleSwarm::NPARTICLES; i++) {
      Particle particle = particles[i];

      int x = (particle.x_ + 1) * (Screen::SCREEN_WIDTH / 2);
      int y =
          (particle.y_) * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT / 2;

      screen.setPixel(x, y, red, green, blue);
    };

    if (screen.processEvents()) {
      break;
    }

    screen.update();

    // auto finish = std::chrono::high_resolution_clock::now();
    // std::cout << "loop() took "
    //           << std::chrono::duration_cast<milli>(finish - start).count()
    //           << " milliseconds\n";
  }

  screen.destroyScreen();

  return 0;
}