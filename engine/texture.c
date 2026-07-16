#include "texture.h"

SDL_Texture* Dry_LoadTexture(SDL_Renderer* renderer, const char* filepath) {
    // This executes at runtime when called, completely avoiding the compiler error
    SDL_Texture* texture = IMG_LoadTexture(renderer, filepath);
    
    if (!texture) {
        SDL_Log("Error loading %s: %s", filepath, SDL_GetError());
    }
    else
    {
        float w, h;
        SDL_GetTextureSize(texture, &w, &h);
        SDL_Log("Texture size = %.0f x %.0f", w, h);
    }
    
    return texture;
}

