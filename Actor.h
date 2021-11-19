/*
* The basis of a charater in the game
*/
#ifndef GRAPHICS_ACTOR_H
#define GRAPHICS_ACTOR_H

//Stats are currently based on the NES game EarthBound

#include <string>

struct Stats {
    int attack;
    int defense;
    int speed;
    int luck;
};

struct Health {
    int max;
    int current;
};

class Actor {
private:
    std::string name;

    int level;
    Health health;

    Stats stats;

    //This creates the beginner stats for an actor
    void initialStatRoller();
public:
    Actor();
    Actor(std::string name);
    Actor(int level);
    Actor(std::string name, int level);

    //Will handle levels, returns a formatted string for the level up screen
    std::string levelUp();
    void changeHealth(int health);

    std::string getName();
    int getLevel();
    Health getHealth();
    Stats getStats();
};

#endif