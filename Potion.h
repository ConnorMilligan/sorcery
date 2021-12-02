/*
* Potion
*/
#ifndef GRAPHICS_POTION_H
#define GRAPHICS_POTION_H

#include "Item.h"

enum potionType { HEALING };

class Potion : public Item {
private:
    potionType type;
public:
    Potion();
    Potion(potionType type);
};

#endif