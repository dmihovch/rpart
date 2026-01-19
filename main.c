#include "include/drawing.h"
#include "include/particle.h"
#include "include/physics.h"


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
	

	SetTargetFPS(FPS);
	while(!WindowShouldClose() && GetKeyPressed() != KEY_Q)
	{
		double frametime_start = GetTime();
		BeginDrawing();
		ClearBackground(GRAY);
		
		double render_start = GetTime();
		draw_particles(particles, particles_count);
		double render_end = GetTime();
			
		double update_start = GetTime();
		update_particles(particles, particles_count);
		double update_end = GetTime();

		DrawFPS(0, 0);

		double frametime_end = GetTime();
		
		draw_diagnostics(frametime_start, frametime_end, render_start, render_end, update_start, update_end);
		EndDrawing();

	}


	free(particles);
	CloseWindow();
	return 0;
}
