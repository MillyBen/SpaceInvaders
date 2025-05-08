#include "AppState.h"

SDL_Window* AppState::getWindow() {
    return window;
}

SDL_Window** AppState::getWindowPointer() {
    return &window;
}

SDL_Renderer* AppState::getRenderer() {
    return renderer;
}

SDL_Renderer** AppState::getRendererPointer() {
    return &renderer;
}

uint64_t AppState::getLastStep() {
    return lastStep;
}

void AppState::setLastStep(uint64_t newStep) {
    lastStep = newStep;
}

void AppState::incrementStep(uint64_t increment) {
    lastStep += increment;
}