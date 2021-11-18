/*
* Inherits from the quad,
* This functions identically to the quad, but will draw a border of a determined thickness around it.
*/

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
    virtual void draw() const;

};


#endif