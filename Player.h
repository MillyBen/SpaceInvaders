#ifndef PLAYER_HEADER
#define PLAYER_HEADER
#include "Entity.h"

class Player: public Entity {

    public:
        Player(int aX, int aY, int aWidth, int aHeight);
};

#endif