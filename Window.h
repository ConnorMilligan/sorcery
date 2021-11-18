#ifndef GRAPHICS_WINDOW_H
#define GRAPHICS_WINDOW_H

#define BORDER_THICKNESS 5

#include "Quad.h"
#include "graphics.h"
#include <vector>
#include <math.h>

const double PI = 2*acos(0.0);

class Window : public Quad {
public:
    Window(color fill, point center, unsigned int width, unsigned int height);
    virtual void draw();

};


#endif