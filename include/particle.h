#ifndef PARTICLE_H
#define PARTICLE_H
#include <stdlib.h>
#include "raylib.h"
#include "raymath.h"
#include "constants.h"
#include "time.h"
typedef struct {
	float x,y,vx,vy,r;
	Color col;
}Particle;
Particle* alloc_rand_nparticles(int n);
Particle create_rand_particle();
float rand_float(float tmin, float tmax);
Color rand_color();
#endif //PARTICLE_H
