#include "Dungeon.h"

Dungeon::Dungeon() {
    this->layout = {};
    this->end = {0,0};
}

Dungeon::Dungeon(std::vector<std::vector<bool>> layout, point end) {
    this->layout = layout;
    this->end = end;
}

bool Dungeon::getTile(int x, int y) {
    return this->layout[y][x];
}

bool Dungeon::getTile(point point) {
    return this->layout[point.y][point.x];
}

point Dungeon::getEnd() {
    return this->end;
}
std::string Dungeon::getMapText(int width, point pos) {

    std::string map = "-- DUNGEON MAP --\n";
    for(int y=0;y<layout.size();y++) {
        for(int x=0;x<layout[0].size();x++) {
            if(y == pos.y && x == pos.x) map += "O ";
            else map += layout[y][x] ? "_ " : "X ";
        }
        map += "\n";
    }
    return map;
}