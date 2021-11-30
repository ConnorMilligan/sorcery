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

struct monstSprites {
    Sprite head;
    Sprite body;
};

class Monster : public Actor {
private:
    monstSprites sprites;
    point coordinates;

    void determineMonster();
public:
    Monster();
    Monster(int level);

    void setCoordinates(point coordinates);

    monstSprites getSprites();
    void draw();
};

#endif