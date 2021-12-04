#include "Potion.h"

Potion::Potion() : Item() {
    this->type = HEALING;
}

Potion::Potion(potionType type) {
    switch (type) {
        case XP:
            this->setName("XP Potion");
            break;
        case RESISTANCE:
            this->setName("Resistance Potion");
            break;
        case STRENGTH:
            this->setName("Strength Potion");
            break;
        case HEALING:
            this->setName("Healing Potion");
            break;
        case TELEPORTATION:
            this->setName("Teleportation Potion");
            break;
    default:
        this->type = HEALING;
        this->setName("Healing Potion");
        break;
    }

    this->type = type;
}

int Potion::potionCount() {
    int count = 0;

    for(int i=0;i<END;i++) {
        count++;
    }
    return count;
}