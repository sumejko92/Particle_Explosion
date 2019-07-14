#include "../include/Particle.h"
#include <math.h>

Particle::Particle() : x_(0), y_(0) {
  direction_ = (2.0 * M_PI * rand()) / RAND_MAX;
  speed_ = (0.0001 * rand()) / RAND_MAX;
}

void Particle::update(int interval) {
  auto xspeed = speed_ * cos(direction_);
  auto yspeed = speed_ * sin(direction_);

  x_ = x_ + xspeed * interval;
  y_ = y_ + yspeed * interval;

  // change speed if window limits are reached
  if (x_ < -1.0 || x_ > 1.0) {
    speed_ = -speed_;
  }
  if (y_ < -1.0 || y_ > 1.0) {
    speed_ = -speed_;
  }
}