#ifndef PHYSICS_H
#define PHYSICS_H
#include "particle.h"
#include "constants.h"
#include "maths.h"
void update_particles(Particle* p, int particle_count);
void reset_accelerations(Particle* p, int particle_count);
void accumulate_forces(Particle* p, int particle_count);
void move_particles_handle_walls(Particle* p, int particle_count);
void handle_particle_collisions(Particle* p, int particle_count);
bool check_collisions_circles(Vector2 apos, float ar, Vector2 bpos, float br);
#endif //PHYSICS_H
