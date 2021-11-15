#include "Actor.h"


void Actor::initialStatRoller() {
    this->health = 30;
    this->stats.attack = 2;
    this->stats.defense = 2;
    this->stats.speed = 2;
    this->stats.luck = 2;
}