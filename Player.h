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
    int score;
    point location;
    Direction direction;
    Dungeon dungeon;
public:
    Player();
    Player(point location, Dungeon dungeon);
    Player(point location, Dungeon dungeon, std::string name);

    //This will move the player (relative position)
    bool move(int x, int y);
    //Gets the current location of the player.
    point getLocation();
    Dungeon getDungeon();
    Direction getDirection();
    std::string getDirectionString();
    int getScore();

    //Movement
    void turnRight();
    void turnLeft();
    bool advance();
    void retreat();

    //Info as an actior
    std::string playerInfo();
};

#endif