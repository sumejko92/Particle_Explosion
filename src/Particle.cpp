#include "../include/Particle.h"
#include <math.h>
#include <random>

static double getRandomFloatIn01() {
  static thread_local std::random_device rnd_dev; 
  static thread_local std::mt19937 rng_gen(rnd_dev());
  static thread_local std::uniform_real_distribution<double> rnd_dst(0, 1);
  return rnd_dst(rnd_gen);
}

Particle::Particle() : x_(0), y_(0) {
  direction_ = 2.0 * M_PI * getRandomFloatIn01();
  speed_ = speed_seed_ * getRandomFloatIn01();
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
