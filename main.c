//TODO: Just bring up a window running
#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_render.h>

#define SCREEN_W 640
#define SCREEN_H 480

int main (int argc, char *argv[]){

	const char* appname = "myGame";
	const char* appversion = "0.01";
	const char* appidentifier = "com.ayan.game";
	
	SDL_Window *window;
	SDL_Renderer *renderer; 
	bool done = false;

	int check = SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	SDL_SetAppMetadata(appname, appversion, appidentifier);
	
	//Seperate init for Debug purposes
	/*	
	window = SDL_CreateWindow(appname, SCREEN_W, SCREEN_H, 0);
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
	*/

	if(!SDL_CreateWindowAndRenderer(appname,SCREEN_W ,SCREEN_H, 0, &window, &renderer)){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create windoiw and renderer: %s", SDL_GetError());
        return 3;
	}
	while(!done){
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_EVENT_QUIT){
				done = true;
			}
		}

		SDL_SetRenderDrawColor(renderer, 100, 100, 20, 255); 
		SDL_RenderClear(renderer);

		

		SDL_RenderPresent(renderer);
	}
	
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
