/*
* This is how sprites are handeled in the game
*/

#ifndef GRAPHICS_SPRITE_H
#define GRAPHICS_SPRITE_H

#include "Quad.h"
#include "spriteSheet.h"

//How large the quad representing a pixel will be drawn
#define PIXEL_SIZE 2

//This converts a string exported by gimp into an array that holds each RGB value of a pixel
#define HEADER_PIXEL(data,pixel) {\
pixel[0] = (((data[0] - 33) << 2) | ((data[1] - 33) >> 4)); \
pixel[1] = ((((data[1] - 33) & 0xF) << 4) | ((data[2] - 33) >> 2)); \
pixel[2] = ((((data[2] - 33) & 0x3) << 6) | ((data[3] - 33))); \
data += 4; \
}

struct Dimensions {
    int width;
    int height;
};

class Sprite {

private:
    point origin;
    Dimensions dimensions;
    const char *pixels;
public:
    Sprite();
    Sprite(spriteSheet sprite);
    Sprite(spriteSheet sprite, point origin);
    Sprite(int width, int height, const char *pixels);
    Sprite(int width, int height, point origin, const char *pixels);
    
    void setCoords(point coords);
    
    void draw();
};

#endif