#ifndef ENTITY_HEADER
#define ENTITY_HEADER
// Abstract class to represent entities in the game
class Entity {

    // Entities are represented as rectangles in the game
    protected:
        int x;
        int y;
        int width;
        int height;


    public:
        Entity(int aX, int aY, int aWidth, int aHeight);

        int getX();
        int getY();
        int getWidth();
        int getHeight();
};
#endif