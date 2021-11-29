#include "Actor.h"

#include <vector>
#include <cmath>



Actor::Actor() {

    this->name = "The Actor";
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

// Making this create the string every time is not particularly efficient considering it is only use by the player
// Good thing i'm not writing this for an embedded system.
std::string Actor::levelUp() {
    int newHealth = 15;

    Stats newLevel;
    newLevel.attack = rand() % 3 + 1;
    newLevel.defense = rand() % 3 + 1;
    newLevel.speed = rand() % 3 + 1;
    newLevel.luck = rand() % 3 + 1;

    this->health.max += newHealth;
    this->health.current = newHealth;
    this->stats.attack += newLevel.attack;
    this->stats.defense += newLevel.defense;
    this->stats.speed += newLevel.speed;
    this->stats.luck += newLevel.luck;

    this->level++;

    return "        ~~ Level Up! ~~\nYour level increased to " + std::to_string(this->level) + "!\n" +
            "Your max health increased by " +  std::to_string(newHealth) + '\n' +
            "Your attack increased by " +  std::to_string(newLevel.attack) + '\n' +
            "Your defense increased by " +  std::to_string(newLevel.defense) + '\n' +
            "Your speed increased by " +  std::to_string(newLevel.speed) + '\n' +
            "Your luck increased by " +  std::to_string(newLevel.luck);
}

void Actor::changeHealth(int newHealth) {
    this->health.current += newHealth;
}

std::string Actor::getName() {
    return this->name;
}
void Actor::setName(std::string newName) {
    this->name = newName;
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