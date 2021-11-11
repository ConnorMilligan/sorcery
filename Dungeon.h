/*
* Stores the dungeon as well as the end tile
*/
#ifndef GRAPHICS_DUNGEON_H
#define GRAPHICS_DUNGEON_H

#include <vector>
#include "Quad.h"

class Dungeon {
private:
    std::vector<std::vector<bool>> layout;
    point end;
public:
    Dungeon();
    Dungeon(std::vector<std::vector<bool>> layout, point end);

    //Returns the value of the tile at a given point.
    bool getTile(int x, int y);
    bool getTile(point point);
    point getEnd();
};

#endif