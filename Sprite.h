#ifndef GRAPHICS_VIEWER_H
#define GRAPHICS_VIEWER_H

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
    Dimensions dimensions;
    char* pixels;
public:
    Sprite(int width, int height, char* pixels);
    
    void draw();
};

#endif