#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <SDL3_image/SDL_image.h>

SDL_Texture* Dry_LoadTexture(SDL_Renderer* renderer,
                             const char* filepath);
// Declares the function. It accepts the active renderer and file path.
SDL_Texture* Dry_LoadTexture(SDL_Renderer* renderer, const char* filepath);

//TODO:IMAGE OPERATION FUNCTIONS(MODIFY COLOR, CHANGE IMAGE MODE)
//TODO:RENDER FUNCTUION
