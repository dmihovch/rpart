#include "include/drawing.h"
#include "include/particle.h"
#include "include/physics.h"
#include <raylib.h>


int main(int argc, char** argv){
	InitWindow(WIDTH, HEIGHT, "Particle Simulation [ NAIVE ]");
	if(!IsWindowReady())
	{
		return 1;
	}
	srand(time(NULL));
	int cur_particles = 100;
	int new_particles;


	Particle* particles = alloc_rand_nparticles(cur_particles);
	if(particles == NULL){
		CloseWindow();
		return 1;
	}
	
	particles[0] = (Particle)
	{
		.pos = {WIDTH/2.,HEIGHT/2.},
		.vel = {0,0},
		.acc = {0,0},
		.r = 10.,
		.m = 1000.,
		.color = YELLOW
	};

	double frametime_start;
	double render_start;
	double update_start;
	double frametime_end;
	double render_end;
	double update_end;
	
	bool running = true;
	SetTargetFPS(FPS);
	int err;
	while(!WindowShouldClose() && GetKeyPressed() != KEY_Q)
	{
		if(IsKeyPressed(KEY_P))
		{
			running = !running;
			printf("toggled\n");
		}
		if(IsKeyPressed(KEY_MINUS))
		{
			cur_particles = cur_particles-100;
			printf("--\n");

			// realloc_nparticles(p, particles_count, particles_count+5);
			// might handle this more gracefully later, but for now we can just not render and compute the particles that are 'removed'
		}
		if(IsKeyPressed(KEY_EQUAL))
		{
			new_particles = cur_particles + 100;
			err = realloc_rand_nparticles(&particles,new_particles,cur_particles);
			if(err)
			{
				break;
			}
			cur_particles = new_particles;
		}

		frametime_start = GetTime();
		BeginDrawing();
		ClearBackground(GRAY);
		if(running)
		{
			render_start = GetTime();
			draw_particles(particles, cur_particles);
			render_end = GetTime();

			update_start = GetTime();
			update_particles(particles, cur_particles);
			update_end = GetTime();
		}
		else {
			render_start = GetTime();
			render_end = GetTime();
			update_start = GetTime();
			update_end = GetTime();
		}
				
		DrawFPS(0, 0);

		frametime_end = GetTime();
		
		draw_diagnostics(frametime_start, frametime_end, render_start, render_end, update_start, update_end);
		draw_options(cur_particles);
		EndDrawing();

	}


	free(particles);
	CloseWindow();
	return 0;
}
