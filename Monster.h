/*
* Stores the Monster and all of its stats.
*/
#ifndef GRAPHICS_MONSTER_H
#define GRAPHICS_MONSTER_H

#include <vector>
#include <string>
#include "Actor.h"


class Monster : public Actor {
private:

public:
    Monster();

    //Info as an actior
    std::string playerInfo();
};

#endif