#pragma once
#include "../include/Particle.h"

class ParticleSwarm {
public:
  int NPARTICLES = 5000;

  ParticleSwarm();
  ~ParticleSwarm();

  const Particle *const getParticles() { return Particles_; };

  void update(int elapsed);

private:
  Particle *Particles_;
  int last_time_;
};