#ifndef PHYSICS_H
#define PHYSICS_H
#include "particle.h"
#include "constants.h"
void update_particles(Particle* p, int particle_count);
void reset_accelerations(Particle* p, int particle_count);
void accumulate_forces(Particle* p, int particle_count);
void move_particles_handle_walls(Particle* p, int particle_count);
void handle_particle_collisions(Particle* p, int particle_count);
#endif //PHYSICS_H
