#include "../include/Particle.h"
#include <math.h>

Particle::Particle() : x_(0), y_(0) {
  direction_ = (2.0 * M_PI * rand()) / RAND_MAX;
  speed_ = (0.0001 * rand()) / RAND_MAX;
}
