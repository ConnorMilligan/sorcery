#include "Sprite.h"

Sprite::Sprite(int width, int height, const char *pixels) {
    this->dimensions.width = width;
    this->dimensions.height = height;
    this->origin = {0,0};
    this->pixels = pixels;
}

Sprite::Sprite(int width, int height, point origin, const char *pixels) {
    this->dimensions.width = width;
    this->dimensions.height = height;
    this->origin = origin;
    this->pixels = pixels;
}



void Sprite::draw() {
    int pixColor[3];
    char *pixel = (char*)this->pixels;

    for (int i = 0; i < this->dimensions.height; i++) {
        for (int j = 0; j < this->dimensions.width; j++) {
            HEADER_PIXEL(pixel, pixColor);
            Quad(color{(double)(pixColor[0])/255, (double)(pixColor[1])/255, (double)(pixColor[2])/255}, point{this->origin.x+ j*PIXEL_SIZE,this->origin.y + i*PIXEL_SIZE}, PIXEL_SIZE, PIXEL_SIZE).draw();
        }
    }
    
}