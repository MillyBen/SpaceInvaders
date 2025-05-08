#ifndef ENEMY_HEADER
#define ENEMY_HEADER
#include "Entity.h"

class Enemy: public Entity {

    private:
        int points;

    public: 
        Enemy(int aX, int aY, int aWidth, int aHeight);
};
#endif