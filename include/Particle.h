#pragma once

class Particle {

public:
private:
  double speed_;
  double direction_;
  double speed_seed_ = 0.0001;

public:
  double x_;
  double y_;

  Particle();
  void update(int interval);
};