#ifndef RENDERER_H
#define RENDERER_H

#include <stdbool.h>

#define DRY_DEFAULT_WINDOW_WIDTH 640
#define DRY_DEFAULT_WINDOW_HEIGHT 480

bool Dry_RendererInit(const char* title, int width, int height);

bool Dry_RendererInitDefault(const char* title);

void Dry_RendererShutdown(void);

#endif
