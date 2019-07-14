#include "../include/ParticleSwarm.h"

ParticleSwarm::ParticleSwarm() : last_time_(0) {
  Particles_ = new Particle[NPARTICLES];
}

ParticleSwarm::~ParticleSwarm() { delete[] Particles_; }

void ParticleSwarm::update(int elapsed) {

  int interval = elapsed - last_time_;

  for (int i = 0; i < ParticleSwarm::NPARTICLES; i++) {
    Particles_[i].update(interval);
  }

  last_time_ = elapsed;
}