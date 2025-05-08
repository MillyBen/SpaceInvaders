#define SDL_WINDOW_WIDTH 600
#define SDL_WINDOW_HEIGHT 600
#define MS_STEP_RATE 125

#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "AppState.h"

// Process user inputs from the keyboard
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

// Update the game and draw to the window
SDL_AppResult SDL_AppIterate(void* appState) {

    AppState* as = (AppState*) appState;

    // Check the current time of the iteration
    const Uint64 now = SDL_GetTicks();

    // Process the number of steps of ga,e which have occured
    while ((now - as->getLastStep()) >= MS_STEP_RATE) {

        as->incrementStep(MS_STEP_RATE);
    }

    // Clear the renderer
    SDL_SetRenderDrawColor(as->getRenderer(), 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(as->getRenderer());

    // Display the renderer on the window
    SDL_RenderPresent(as->getRenderer());

    return SDL_APP_CONTINUE;
}

// Processes events
SDL_AppResult SDL_AppEvent(void* appState, SDL_Event* event) {

    AppState* as = (AppState*) appState;

    // Check what the event representss
    switch(event->type) {
        // The game is finished
        case SDL_EVENT_QUIT:
            return SDL_APP_SUCCESS;
        // An input from the keyboard has been provided
        case SDL_EVENT_KEY_DOWN:
            return handle_key_event_(event->key.scancode);
        // The event doesn't require handling
        default:
            break;
    }

    return SDL_APP_CONTINUE;
}

// Set up required to start the game
SDL_AppResult SDL_AppInit(void** appState, int argc, char *argv[]) {

    // Set the metadata
    if (!SDL_SetAppMetadata("Space Invaders Practice Clone", "1.0", "invaders")) {
        return SDL_APP_FAILURE;
    }

    // Initalise and check for errors
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK)) {
        SDL_Log("Could not initialise SDL %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    // Create the object which will hold the data on the game
    AppState* as = (AppState*)SDL_calloc(1, sizeof(AppState));

    *appState = as;

    // Create the window and its renderer
    if (!SDL_CreateWindowAndRenderer("Space Invaders", SDL_WINDOW_WIDTH, SDL_WINDOW_HEIGHT, 0, as->getWindowPointer(), as->getRendererPointer())) {
        return SDL_APP_FAILURE;
    }

    // Get the start time for calculating game steps
    as->setLastStep(SDL_GetTicks());

    return SDL_APP_CONTINUE;
}

// Handles cleanup upon quitting the game
void SDL_AppQuit(void* appState, SDL_AppResult res) {

    // Check if the app state needs cleaning
    if (appState != NULL) {
        
        AppState* as = (AppState*) appState;
        // Destroy the renderer and its window
        SDL_DestroyRenderer(as->getRenderer());
        SDL_DestroyWindow(as->getWindow());
        // Free the memory allocated to the app state
        SDL_free(as);
    }
}