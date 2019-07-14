# Particle_Explosion

This repo contains an example of particle explosion using the SDL library. The project was done as part of a C++ course.  

## Setup
Ubuntu: Ubuntu 18.04  
Language: C++  
IDE: Visual Studio Code  

## How to run
Make sure that you have SDL installed:  
https://wiki.libsdl.org/Installation  

Navigate to your project directory.  
Compile with:  
g++ src/main.cpp src/Screen.cpp src/Particle.cpp src/ParticleSwarm.cpp -lSDL2 -lSDL2main -o bin/particle_explosion  

Run with:  
./bin/particle_explosion  

When executed, a number of particles will be created in the center of the screen and will simulate a particle explosion in all directions with particles constantly changing color. In addition the particles are bouncing off the window edges and contained inside the window.  
The number of particles can be set using the NPARTICLES variable in ParticleSwarm.h  
The speed of the particles can be set using the speed_seed_ variable in Particle.h  

## Results

<p align="center">
  <img src="https://raw.githubusercontent.com/sumejko92/Particle_Explosion/master/results/explosion.png" width="450" /> 
</p>

