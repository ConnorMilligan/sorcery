#ifndef GRAPHICS_WINDOW_H
#define GRAPHICS_WINDOW_H

#include "Quad.h"
#include "graphics.h"
#include <vector>

class Window : public Quad {
public:
    Window(color fill, point center, unsigned int width, unsigned int height);
    virtual void draw();

};


#endif