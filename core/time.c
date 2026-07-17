#include "time.h"
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_timer.h>

static Uint64 lastCounter;
static float deltaTime;
//Frequency is a double and not Uint64 cuz in the end 
//it doesn't even matter 
//(we are gonna divide them as floating valuese)
static double frequency;

void Dry_TimeInit(){
	lastCounter =  SDL_GetPerformanceCounter();
	frequency =  (double)SDL_GetPerformanceFrequency();
	deltaTime = 0.0f;
}

void Dry_TimeUpdate(void)
{
    Uint64 current = SDL_GetPerformanceCounter();

    deltaTime = (float)((current - lastCounter) / frequency);
    lastCounter = current;
}

float Dry_GetDeltaTime(){
	return deltaTime;
}
