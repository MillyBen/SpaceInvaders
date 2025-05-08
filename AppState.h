#ifndef APP_STATE_HEADER
#define APP_STATE_HEADER
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

class AppState {

    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        uint64_t lastStep;

    public:

        SDL_Window* getWindow();
        SDL_Window** getWindowPointer();
        SDL_Renderer* getRenderer();
        SDL_Renderer** getRendererPointer();
        uint64_t getLastStep();
        void setLastStep(uint64_t newStep);

        void incrementStep(uint64_t increment);
};
#endif