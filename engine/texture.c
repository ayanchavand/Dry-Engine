#include "texture.h"
#include <SDL3_image/SDL_image.h>

SDL_Texture* load_my_image(SDL_Renderer* renderer, const char* filepath) {
    // This executes at runtime when called, completely avoiding the compiler error
    SDL_Texture* texture = IMG_LoadTexture(renderer, filepath);
    
    if (!texture) {
        SDL_Log("Error loading %s: %s", filepath, SDL_GetError());
    }
    
    return texture;
}

