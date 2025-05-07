#define SDL_WINDOW_WIDTH 600
#define SDL_WINDOW_HEIGHT 600

#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "Enemy.h"
#include "Player.h"

SDL_AppResult SDL_AppIterate(void* appState) {

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appState, SDL_Event* event) {

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

    if (!SDL_CreateWindowAndRenderer("Space Invaders", SDL_WINDOW_WIDTH, SDL_WINDOW_HEIGHT, 0, NULL, NULL)) {
        return SDL_APP_FAILURE;
    }

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* appState, SDL_AppResult res) {

    if (appState != NULL) {
        
    }
}