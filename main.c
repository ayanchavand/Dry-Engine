//TODO: Just bring up a window running
#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include "engine/renderer.h"


int main (int argc, char *argv[]){
	/*
	const char* appname = "myGame";
	const char* appversion = "0.01";
	const char* appidentifier = "com.ayan.game";
	*/
	
	Dry_AppInfo app_data = { "myGame","0.01","com.ayan.game"};
	 
	bool done = false;

	int check = SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	
	SDL_SetAppMetadata(app_data.appname
		    , app_data.appversion
		    , app_data.appidentifier
		    );
	
	Dry_RendererInitDefault(&app_data);

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
	
	

		while(!done){
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_EVENT_QUIT){
				done = true;
			}
		}
		
		//Background
		Dry_BeginFrame();
		Dry_EndFrame();

}
	
	
	Dry_RendererShutdown();
	SDL_Quit();
	return 0;
}
