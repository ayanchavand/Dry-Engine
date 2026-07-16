#pragma once

#include <stdbool.h>

#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>

#include "../core/color.h"
#include "../core/transform.h"
#define DRY_DEFAULT_WINDOW_WIDTH 640
#define DRY_DEFAULT_WINDOW_HEIGHT 480

typedef struct {
	const char* appname;
	const char* appversion;
	const char* appidentifier;
} Dry_AppInfo;

//Inits
bool Dry_RendererInit(const Dry_AppInfo* app , int width, int height);
bool Dry_RendererInitDefault(const Dry_AppInfo* app);

void Dry_RendererShutdown(void);

void Dry_BeginFrame(void);
void Dry_EndFrame(void);

//Draw CalLs
void Dry_DrawRect(const int w,const int h, const int x, const int y, const Dry_Color* color);

void Dry_DrawTexture(SDL_Texture* tex, Dry_Transform* tranform);

