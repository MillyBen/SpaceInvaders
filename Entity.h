#ifndef ENTITY_HEADER
#define ENTITY_HEADER
class Entity {
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