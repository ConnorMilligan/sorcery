#include "Actor.h"

Actor::Actor() {
    this->name = "Actor";
    this->level = 1;
    this->initialStatRoller();
}

Actor::Actor(std::string name) {
    this->name = name;
    this->level = 1;
    this->initialStatRoller();
}

Actor::Actor(int level) : Actor() {
    for (int i = 1; i < level; i++)
        this->levelUp();
}

Actor::Actor(std::string name, int level) : Actor(name) {
    for (int i = 1; i < level; i++)
        this->levelUp();
}

void Actor::initialStatRoller() {
    this->health.max = 30;
    this->health.current = this->health.max;
    this->stats.attack = 2;
    this->stats.defense = 2;
    this->stats.speed = 2;
    this->stats.luck = 2;
}

void Actor::levelUp() {
    this->level++;

    this->health.max += 15;
    this->health.current = this->health.max;
    this->stats.attack += rand() % 3 + 1;
    this->stats.defense += rand() % 3 + 1;
    this->stats.speed += rand() % 3 + 1;
    this->stats.luck += rand() % 3 + 1;
}

std::string Actor::getName() {
    return this->name;
}

int Actor::getLevel() {
    return this->level;
}

Health Actor::getHealth() {
    return this->health;
}

Stats Actor::getStats() {
    return this->stats;
}