//TODO: Just bring up a window running
#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_render.h>

int main (int argc, char *argv[]){

	const char* appname = "myGame";
	const char* appversion = "0.01";
	const char* appidentifier = "com.ayan.game";
	
	SDL_Window *window;
	SDL_Renderer *renderer; 
	bool done = false;

	int check = SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO);
	SDL_SetAppMetadata(appname, appversion, appidentifier);
	
	window = SDL_CreateWindow(appname, 640, 480, 0);
 	if (window == NULL) {
        	SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
        	SDL_Quit();
        	return 1;
    	}

	
	renderer = SDL_CreateRenderer(window, NULL);
	if (renderer == NULL) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}
	
	while(!done){
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_EVENT_QUIT){
				done = true;
			}
		}

		SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255); 
		SDL_RenderClear(renderer);

		

		SDL_RenderPresent(renderer);
	}
	
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
