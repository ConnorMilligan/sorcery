#include "Potion.h"

Potion::Potion() : Item() {
    this->type = HEALING;
}

Potion::Potion(potionType type) {
    switch (type) {
    case HEALING:
        this->setName("Healing Potion");
        break;
    
    default:
        this->type = HEALING;
        this->setName("Healing Potion");
        break;
    }

    this->type = type;
}