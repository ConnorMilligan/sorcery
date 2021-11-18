/*
* Inherits from the quad,
* will display the dungeon view to the player.
*/

#ifndef GRAPHICS_VIEWER_H
#define GRAPHICS_VIEWER_H

#include "Window.h"
#include "Player.h"

//THis really makes a lot more sense to store a point as opposed to an enum since the dungeon is boolean anyway
struct Surrounding {
    point left;
    point right;
    point front;
};

class Viewer : public Window {
private:
    Surrounding surrounding;
    Player* player;
public:
    Viewer(color fill, point center, unsigned int width, unsigned int height);
    Viewer(color fill, point center, unsigned int width, unsigned int height, Player *player);

    Surrounding getSurroundings();
    void surroundingProcessor();
    virtual void draw() const;
    virtual void drawWall(bool left, int width, int height, int slices);
};


#endif