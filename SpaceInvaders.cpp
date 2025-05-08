#define SDL_WINDOW_WIDTH 600
#define SDL_WINDOW_HEIGHT 600
#define MS_STEP_RATE 125

#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "AppState.h"

static SDL_AppResult handle_key_event_(SDL_Scancode key_code)
{
    switch (key_code) {
    /* Quit. */
    case SDL_SCANCODE_ESCAPE:
    case SDL_SCANCODE_Q:
        return SDL_APP_SUCCESS;
    default:
        break;
    }
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* appState) {

    AppState* as = (AppState*) appState;

    const Uint64 now = SDL_GetTicks();

    while ((now - as->getLastStep()) >= MS_STEP_RATE) {

        as->incrementStep(MS_STEP_RATE);
    }

    SDL_SetRenderDrawColor(as->getRenderer(), 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(as->getRenderer());

    SDL_RenderPresent(as->getRenderer());

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appState, SDL_Event* event) {

    AppState* as = (AppState*) appState;

    switch(event->type) {
        case SDL_EVENT_QUIT:
            return SDL_APP_SUCCESS;
        case SDL_EVENT_KEY_DOWN:
            return handle_key_event_(event->key.scancode);
    }

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppInit(void** appState, int argc, char *argv[]) {

    if (!SDL_SetAppMetadata("Space Invaders Practice Clone", "1.0", "invaders")) {
        return SDL_APP_FAILURE;
    }

    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK)) {
        SDL_Log("Could not initialise SDL %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    AppState* as = (AppState*)SDL_calloc(1, sizeof(AppState));

    *appState = as;

    if (!SDL_CreateWindowAndRenderer("Space Invaders", SDL_WINDOW_WIDTH, SDL_WINDOW_HEIGHT, 0, as->getWindowPointer(), as->getRendererPointer())) {
        return SDL_APP_FAILURE;
    }

    as->setLastStep(SDL_GetTicks());

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* appState, SDL_AppResult res) {

    if (appState != NULL) {
        
        AppState* as = (AppState*) appState;
        SDL_DestroyRenderer(as->getRenderer());
        SDL_DestroyWindow(as->getWindow());
        SDL_free(as);
    }
}