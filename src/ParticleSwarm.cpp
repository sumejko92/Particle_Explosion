#include "../include/ParticleSwarm.h"

ParticleSwarm::ParticleSwarm() : last_time_(0) {
  Particles_ = new Particle[NPARTICLES];
}

ParticleSwarm::~ParticleSwarm() { 
  delete[] Particles_; 
}

void ParticleSwarm::update(int elapsed) {

  int interval = elapsed - last_time_;

  for (auto const& particle : Particles_)
    particle.update(interval);

  last_time_ = elapsed;
}
