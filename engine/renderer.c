#include "renderer.h"
#include <SDL3/SDL.h>

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

//Rect init
 static SDL_FRect square = {30, 30, 100,100};

bool Dry_RendererInit(const Dry_AppInfo* app, int width, int height){
	

	if(!SDL_CreateWindowAndRenderer(app->appname, width ,height, 0, &window, &renderer)){
        	SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        	return false;
	}
	return true;
	
}

bool Dry_RendererInitDefault(const Dry_AppInfo* app){
	return Dry_RendererInit(app, DRY_DEFAULT_WINDOW_WIDTH, DRY_DEFAULT_WINDOW_HEIGHT);
}

void Dry_RendererShutdown(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void Dry_BeginFrame(){

	SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255); 
		SDL_RenderClear(renderer);
}

void Dry_EndFrame(){
	
	//Main Draw Call
	SDL_SetRenderDrawColor(renderer, 100, 0, 20, 255); 
	SDL_RenderFillRect(renderer, &square);
		
	//Final Draw
	SDL_RenderPresent(renderer);
}

