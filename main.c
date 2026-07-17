#include <SDL3/SDL.h>

#include "core/time.h"
#include "engine/renderer.h"

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    Dry_AppInfo app = {
        .appname = "myGame",
        .appversion = "0.01",
        .appidentifier = "com.ayan.game"
    };

    SDL_SetAppMetadata(
        app.appname,
        app.appversion,
        app.appidentifier
    );

    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO))
    {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "SDL_Init failed: %s",
            SDL_GetError()
        );
        return 1;
    }

    Dry_RendererInitDefault(&app);
    Dry_TimeInit();

    bool running = true;

    float fpsTimer = 0.0f;

    while (running)
    {
        Dry_TimeUpdate();

        // Log FPS once per second
        fpsTimer += Dry_GetDeltaTime();
        if (fpsTimer >= 1.0f)
        {
            SDL_Log("FPS: %.2f", 1.0f / Dry_GetDeltaTime());
            fpsTimer = 0.0f;
        }

        // Handle events
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_EVENT_QUIT:
                    running = false;
                    break;

                default:
                    break;
            }
        }

        // Update
        // TODO: Game logic

        // Render
        Dry_BeginFrame();

        // TODO: Draw calls

        Dry_EndFrame();
    }

    Dry_RendererShutdown();
    SDL_Quit();

    return 0;
}
