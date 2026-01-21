#ifndef PHYSICS_H
#define PHYSICS_H
#include "particle.h"
#include "constants.h"
#include "maths.h"
#include <math.h>
void update_particles(Particle* p, int particle_count);
void reset_accelerations(Particle* p, int particle_count);
void accumulate_forces(Particle* p, int particle_count);
void move_particles_handle_walls(Particle* p, int particle_count);
void handle_particle_collisions(Particle* p, int particle_count);
Vector2 check_collisions_circles(float* scalar_dist,Vector2 apos, float ar, Vector2 bpos, float br);
float calculate_impulse(Particle a, Particle b, Vector2 normal);
bool collision_occured(Vector2 normal);
void handle_penetration(Particle* a, Particle* b,Vector2 normal, float scalar_distance);
#endif //PHYSICS_H
