/*
* Stores the player itself for keeping track of location within the maze.
*/
#ifndef GRAPHICS_PLAYER_H
#define GRAPHICS_PLAYER_H

#include <vector>
#include <string>
#include "Dungeon.h"
#include "Actor.h"

enum Direction { NORTH, EAST, SOUTH, WEST };

class Player : public Actor {
private:
    point location;
    Direction direction;
    Dungeon dungeon;
public:
    Player();
    Player(point location, Dungeon dungeon);

    //This will move the player (relative position)
    void move(int x, int y);
    //Gets the current location of the player.
    point getLocation();
    Dungeon getDungeon();
    Direction getDirection();
    std::string getDirectionString();

    void turnRight();
    void turnLeft();
    void advance();
    void retreat();

    std::string playerInfo();
};

#endif