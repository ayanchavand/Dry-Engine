#pragma once
#include <SDL3/SDL.h>

// Declares the function. It accepts the active renderer and file path.
SDL_Texture* load_my_image(SDL_Renderer* renderer, const char* filepath);
