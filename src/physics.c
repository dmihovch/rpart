#include "../include/physics.h"
#include <raylib.h>


void update_particles(Particle* p, int particle_count){
	reset_accelerations(p,particle_count);
	accumulate_forces(p,particle_count);
	move_particles_handle_walls(p,particle_count);
	handle_particle_collisions(p,particle_count);
}

void reset_accelerations(Particle* p, int particle_count)
{
	for(int i = 0; i<particle_count; ++i)
	{
		vec2_zero(&p[i].acc);
	}
}

void accumulate_forces(Particle* p, int particle_count)
{
	for(int i = 0; i<particle_count; ++i)
	{
		for(int j = i + 1; j<particle_count; ++j)
		{
			//calculate the forces for both i and j
		}
	}
}

void move_particles_handle_walls(Particle* p, int particle_count)
{
	for(int i = 0; i<particle_count; ++i)
	{
		vec2_add_ip(&p[i].vel,p[i].acc);
		vec2_add_ip(&p[i].pos,p[i].vel);

		if(p[i].pos.x + p[i].r > WIDTH)
		{
			p[i].pos.x = WIDTH - p[i].r;
			p[i].vel.x = -p[i].vel.x * ELASTICITY;
		}
		else if(p[i].pos.x - p[i].r < 0)
		{
			p[i].pos.x = p[i].r;
			p[i].vel.x = -p[i].vel.x * ELASTICITY;
		}
		if(p[i].pos.y + p[i].r > HEIGHT)
		{
			p[i].pos.y = HEIGHT - p[i].r;
			p[i].vel.y = -p[i].vel.y * ELASTICITY;
		}
		else if(p[i].pos.y - p[i].r < 0)
		{
			p[i].pos.y = p[i].r;
			p[i].vel.y = -p[i].vel.y * ELASTICITY;
		}
	}
	
}

void handle_particle_collisions(Particle* p, int particle_count)
{
	for(int i = 0; i < particle_count; ++i)
	{
		for(int j = i+1; j<particle_count; ++j)
		{
			//handle particle collisions
		}
	}
}

void dep_update_particles(Particle* p, int particle_count)
{

	for(int i = 0; i<particle_count; i++)
	{
		for(int j = 0; j<particle_count; j++)
		{
			if(i == j)continue;
			
			if(CheckCollisionCircles(p[i].pos, p[i].r, p[j].pos ,p[j].r))
			{
				vec2_negate_ip(&p[i].vel);
			}
		}			
	}
	
}
