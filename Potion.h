/*
* Potion
*/
#ifndef GRAPHICS_POTION_H
#define GRAPHICS_POTION_H

#include <vector>
#include "Item.h"

enum potionType { HEALING, XP, RESISTANCE, TELEPORTATION, STRENGTH, END };

class Potion : public Item {
private:
    potionType type;
public:
    Potion();
    Potion(potionType type);
    int potionCount();
};

#endif