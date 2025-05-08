#ifndef ENEMY_HEADER
#define ENEMY_HEADER
#include "Entity.h"

// The individual enemies that make up the invading swarm
class Enemy: public Entity {

    private:
        // How many points the enemy is worth when shot
        int points;

    public: 
        Enemy(int aX, int aY, int aWidth, int aHeight);
};
#endif