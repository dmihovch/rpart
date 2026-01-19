#include "../include/physics.h"
#include <raymath.h>
#include <raylib.h>



void update_particles(Particle* p, int particle_count)
{

	for(int i = 0; i<particle_count; i++)
	{
		for(int j = 0; j<particle_count; j++)
		{
			if(i == j)continue;
			
			if(CheckCollisionCircles((Vector2){p[i].x, p[i].y}, p[i].r, (Vector2){p[j].x, p[j].y}, p[j].r))
			{
				float pjvx = p[j].vx;
				float pjvy = p[j].vy;
				p[i].vx = -pjvx;
				p[i].vy = -pjvy;
			}
			
		}
	
		if(p[i].x + p[i].vx + p[i].r > WIDTH || (p[i].x + p[i].vx) - p[i].r < 0)
		{
			p[i].vx = -p[i].vx;
		}
		if(p[i].y + p[i].vy + p[i].r > HEIGHT || (p[i].y + p[i].vy) - p[i].r < 0)
		{
			p[i].vy = -p[i].vy;
		}

	}
	for(int i = 0; i<particle_count; i++){
		p[i].x += p[i].vx;
		p[i].y += p[i].vy;
	}
		return;
}
