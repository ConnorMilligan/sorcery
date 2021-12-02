#include "Dungeon.h"

Dungeon::Dungeon() {
    this->layout = {};
    this->end = {0,0};
}

Dungeon::Dungeon(std::vector<std::vector<bool>> layout, point end) {
    this->layout = layout;
    this->end = end;
    this->visited = layout;

    for(int y=0;y<layout.size();y++) {
        for(int x=0;x<layout[0].size();x++) {
            visited[y][x] = true; // Because walls are read in as true, so will unexplored areas be
        }

    }
}
void Dungeon::setVisited(point p) {
    visited[p.y][p.x] = false; // haha this seems backwards right?
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
bool Dungeon::isVisited(point p) {
    return !visited[p.y][p.x];
}
std::string Dungeon::getMapText(point start, point pos) {

    // Each character width
    // 34 characters will fit on this screen
    float padding = (31-visited.size())/2 - visited.size()/2;
    std::string empty = "";
    std::string title = "~~ DUNGEON MAP ~~";
    for(int i=0;i<padding;i++) empty += " ";

    std::string map = empty + title;
    for(int y=0;y<visited.size();y++) {
        map += "\n" + empty;
        for(int x=0;x<visited[0].size();x++) {
            if(y == start.y && x == start.x) map += "S ";
            else if(y == pos.y && x == pos.x) map += "O ";
            else map += visited[y][x] ? "_ " : "X ";
        }

    }
    map += "\nO - PLAYER\nX - EXPLORED\n_ - UNEXPLORED\nS - START";
    return map;
}