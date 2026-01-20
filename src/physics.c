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
			
			Vector2 normal = check_collisions_circles(p[i].pos, p[i].r, p[j].pos, p[j].r);
			if(normal.x != 0 && normal.y != 0){ //collision occured
				Vector2 relative_vel = vec2_sub(p[i].vel, p[j].vel);
				//need to read that doc
			}
		}
	}
}

Vector2 check_collisions_circles(Vector2 apos, float ar, Vector2 bpos, float br)
{
	Vector2 delta = vec2_sub(apos, bpos);
	float distsq = vec2_dot(delta,delta);
	float rsq = (ar+br) * (ar+br);
	if(distsq >= rsq)
	{
		return (Vector2){0,0};
	}
	if(distsq == 0.)
	{
		return (Vector2)
		{
			rand_float_nonzero(-1, 1),
			rand_float_nonzero(-1,1)
		};
	} 

	float dist = sqrtf(distsq);
	return (Vector2){delta.x/dist, delta.y/dist};
}














