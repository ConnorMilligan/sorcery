/*
* Stores the player itself for keeping track of location within the maze.
*/
#ifndef GRAPHICS_PLAYER_H
#define GRAPHICS_PLAYER_H

#include <vector>
#include <string>
#include <typeinfo>
#include "Dungeon.h"
#include "Actor.h"
#include "Potion.h"

#define MAX_ITEMS 9
#define XP_FACTOR 2

enum Direction { NORTH, EAST, SOUTH, WEST };

class Player : public Actor {
private:
    int xp;
    int score;
    point location;
    point startLocation;
    Direction direction;
    Dungeon dungeon;
    std::vector<Item> inventory;
public:
    Player();
    Player(point location, Dungeon dungeon);
    Player(point location, Dungeon dungeon, std::string name);

    //This will move the player (relative position)
    bool move(int x, int y);
    //Gets the current location of the player.
    point getLocation();
    point getStartLocation();
    void setLocation(point p);
    void setStartLocation(point p);
    Dungeon getDungeon();
    void setDungeon(Dungeon d);
    Direction getDirection();
    std::string getDirectionString();

    int getScore();
    void changeScore(int dc);

    //This returns a vector of the names of all the items in the inventory
    std::vector<std::string> getInventoryString();

    std::string addItem(Item item);
    std::string removeItem(int index);

    //to Drink a potion
    std::string use(int index);

    //Checks the XP needed for the next level
    int nextLvlXp();

    std::string addXp(int xp);
    int getXp();

    std::string levelUp();

    //Movement
    void turnRight();
    void turnLeft();
    bool advance();
    void retreat();

    //Info as an actor
    std::string playerInfo();
    std::string playerInfoDetailed();
    std::string helpString();
};

#endif