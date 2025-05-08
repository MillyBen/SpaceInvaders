#include "Entity.h"

Entity::Entity(int aX, int aY, int aWidth, int aHeight) {
    x = aX;
    y = aY;
    width = aWidth;
    height = aHeight;
}

int Entity::getX() {
    return x;
}

int Entity::getY() {
    return y;
}

int Entity:: getWidth() {
    return width;
}

int Entity:: getHeight() {
    return height;
}