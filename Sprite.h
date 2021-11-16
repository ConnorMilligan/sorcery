#ifndef GRAPHICS_SPRITE_H
#define GRAPHICS_SPRITE_H

#include "Quad.h"

#define PIXEL_SIZE 2

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
    Sprite(int width, int height, const char *pixels);
    Sprite(int width, int height, point origin, const char *pixels);
    //Sprite(point origin, spriteSheet sheet);
    void draw();
};

#endif