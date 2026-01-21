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
	const int particles_count = PARTICLES;


	Particle* particles = alloc_rand_nparticles(particles_count);
	if(particles == NULL){
		CloseWindow();
		return 1;
	}
	double frametime_start;
	double render_start;
	double update_start;
	double frametime_end;
	double render_end;
	double update_end;
	
	bool running = true;
	SetTargetFPS(FPS);
	while(!WindowShouldClose() && GetKeyPressed() != KEY_Q)
	{
		if(IsKeyPressed(KEY_P))
		{
			running = !running;
			printf("toggled\n");
		}

		frametime_start = GetTime();
		BeginDrawing();
		ClearBackground(GRAY);
		if(running)
		{
			render_start = GetTime();
			draw_particles(particles, particles_count);
			render_end = GetTime();

			update_start = GetTime();
			update_particles(particles, particles_count);
			update_end = GetTime();
		}
				
		DrawFPS(0, 0);

		frametime_end = GetTime();
		
		draw_diagnostics(frametime_start, frametime_end, render_start, render_end, update_start, update_end);
		EndDrawing();

	}


	free(particles);
	CloseWindow();
	return 0;
}
