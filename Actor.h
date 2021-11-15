/*
* The basis of a charater in the game
*/
#ifndef GRAPHICS_ACTOR_H
#define GRAPHICS_ACTOR_H

//Stats are currently based on the NES game EarthBound

#include <string>

struct stats {
    int attack;
    int defense;
    int speed;
    int luck;
};

class Actor {
private:
    std::string name;

    int level;
    int health;

    stats stats;

    void initialStatRoller();
public:
    Actor();
    Actor(std::string name);
    Actor(int level);
    Actor(std::string name, int level);

    void levelUp();
};

#endif