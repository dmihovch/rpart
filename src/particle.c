#include "../include/particle.h"

Particle* alloc_rand_nparticles(int n)
{
	Particle* p = malloc(n*sizeof(Particle));
	if(!p) 
	{
		return NULL;
	}

	for(int i = 0; i < n; ++i)
	{
		p[i] = create_rand_particle();
	}

	return p;

}

Particle create_rand_particle()
{
	Particle p;
	p.x = rand_float(0,WIDTH);
	p.y = rand_float(0,HEIGHT);
	p.vx = rand_float(-2.0,2.0);
	p.vy = rand_float(-2.0,2.0);
	p.r = 3.;
	p.col = rand_color();
	return p;
}

float rand_float(float tmin, float tmax)
{
	float rmin = 0.;
	float rmax = 1.;
	float ret = (float)rand()/RAND_MAX;
	ret = ret - rmin;
	ret = ret / (rmax - rmin);
	return ret * (tmax - tmin) + tmin;
}

Color rand_color()
{
	Color colors[] = {RAYWHITE,RED,BLUE,PURPLE,PINK,YELLOW,ORANGE,GREEN};
	return colors[rand()%8];
}

