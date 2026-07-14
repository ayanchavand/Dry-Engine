#include "renderer.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

bool Dry_RendererInit(const char *title, int width, int height){
	

	if(!SDL_CreateWindowAndRenderer(title, width ,height, 0, &window, &renderer)){
        	SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create windoiw and renderer: %s", SDL_GetError());
        	return false;
	}
	return true;
	
}

bool Dry_RendererInitDefault(const char *title){
	return Dry_RendererInit(title, DRY_DEFAULT_WINDOW_WIDTH, DRY_DEFAULT_WINDOW_HEIGHT);
}

