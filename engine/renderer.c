#include "renderer.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include "texture.h"

static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;
static SDL_Texture* tex = NULL;
SDL_FRect default_rect = {100,100,256,256};
//Default image test texture

 
bool Dry_RendererInit(const Dry_AppInfo* app, int width, int height){
	
	
	if(!SDL_CreateWindowAndRenderer(app->appname, width ,height, 0, &window, &renderer)){
        	SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        	return false;
	}

	tex = load_my_image(renderer, "res/img/square.png");		
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
   	//tex = load_my_image(renderer, "res/img/square.png");		
	SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255); 
	SDL_RenderClear(renderer);
}

void Dry_EndFrame(){
	
	//Main Draw Call
	SDL_SetRenderDrawColor(renderer, 100, 0, 20, 255); 
	Dry_Color red = {0, 0, 255, 255};
	//Dry_DrawRect(100, 100, 100, 100, &red);
	//Dry_DrawRect(300, 300, 20, 50, &red);
 	if (!SDL_RenderTexture(renderer, tex, NULL, &default_rect))
{
    SDL_Log("Render failed: %s", SDL_GetError());
}	//Final Draw
	SDL_RenderPresent(renderer);
}
void Dry_DrawRect(const int w, const int h, const int x, const int y, const Dry_Color* color){
	SDL_FRect rect = {x,y,w,h};
	SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a);
	SDL_RenderFillRect(renderer, &rect);	
}

