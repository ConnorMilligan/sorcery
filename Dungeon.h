/*
* Stores the dungeon as well as the end tile
*/
#ifndef GRAPHICS_DUNGEON_H
#define GRAPHICS_DUNGEON_H

#include <vector>
#include "Quad.h"

//The encounter rate in the dungeon out of 100 (percentage per movement)
#define ENCOUNTER_RATE 25

class Dungeon {
private:
    std::vector<std::vector<bool>> layout;
    std::vector<std::vector<bool>> visited;
    point end;
public:
    Dungeon();
    Dungeon(std::vector<std::vector<bool>> layout, point end);

    //Returns the value of the tile at a given point.
    bool getTile(int x, int y);
    bool getTile(point point);
    std::string getMapText(int width, point pos);
    point getEnd();
    void setVisited(point p);
};

#endif