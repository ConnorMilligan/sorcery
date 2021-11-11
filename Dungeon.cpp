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