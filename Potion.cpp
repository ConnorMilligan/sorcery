#include "Potion.h"

Potion::Potion() : Item() {
    this->type = HEALING;
}

Potion::Potion(potionType type) {
    switch (type) {
    case HEALING:
        Item("Healing Potion");
        break;
    
    default:
        this->type = HEALING;
        Item("Healing Potion");
        break;
    }

    this->type = type;
}