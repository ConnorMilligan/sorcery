/*
* Stores the Monster and all of its stats.
*/
#ifndef GRAPHICS_MONSTER_H
#define GRAPHICS_MONSTER_H

#include <vector>
#include <string>
#include "Actor.h"
#include "Sprite.h"

//I want to make this so that it will eventually use 2 sprites, one for the head and another for the body.
class Monster : public Actor {
private:
    Sprite sprite;
    point coordinates;
public:
    Monster();
    Monster(int level);
    Monster(Sprite sprite);
    Monster(Sprite sprite, int level);

    void setCoordinates(point coordinates);

    Sprite getSprite();
    void draw();
};

#endif