#include "include/drawing.h"
#include "include/particle.h"
#include "include/physics.h"
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include "include/raygui.h"


int main(/* int argc, char** argv */){
	InitWindow(WIDTH, HEIGHT, "Particle Simulation [ NAIVE ]");
	if(!IsWindowReady())
	{
		return 1;
	}
	srand(time(NULL));
	int particle_count = 100;
	int new_particle_count;
	float gui_particles = particle_count;


	Particle* particles = alloc_rand_nparticles(particle_count);
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

		new_particle_count = (int)gui_particles;
		if(new_particle_count > particle_count)
		{
			err = realloc_rand_nparticles(&particles,new_particle_count,particle_count);
			if(err)
			{
				break;
			}
		}

		if(new_particle_count != particle_count)
		{
			particle_count = new_particle_count;	
		}
	
			// realloc_nparticles(p, particles_count, particles_count+5);
			// might handle this more gracefully later, but for now we can just not render and compute the particles that are 'removed'

		frametime_start = GetTime();
		BeginDrawing();
		ClearBackground(BLACK);
		if(running)
		{
			render_start = GetTime();
			draw_particles(particles, particle_count);
			render_end = GetTime();

			update_start = GetTime();
			update_particles(particles, particle_count);
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
		// draw_options(&gui_particles);
		GuiSliderBar((Rectangle){100,175,100,25}, "N-Particles",TextFormat("%d",(int)gui_particles),&gui_particles,1,3000);
		GuiCheckBox((Rectangle){WIDTH-100,100,25,25},"Pause",&running);
		EndDrawing();


	}


	free(particles);
	CloseWindow();
	return 0;
}
