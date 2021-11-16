#include "Sprite.h"

Sprite::Sprite(int width, int height, const char *pixels) {
    this->dimensions.width = width;
    this->dimensions.height = height;
    this->pixels = pixels;
}

void Sprite::draw() {
    int pixColor[3];
    char *pixel = (char*)this->pixels;

    for (int i = 0; i < this->dimensions.height; i++) {
        for (int j = 0; j < this->dimensions.width; j++) {
            HEADER_PIXEL(pixel, pixColor);
            printf("%lf %lf %lf\n", double(pixColor[0])/255, double(pixColor[1])/255, double(pixColor[2])/255);
            Quad(color{(double)(pixColor[0])/255, (double)(pixColor[1])/255, (double)(pixColor[2])/255}, point{j*16,i*16}, 16, 16).draw();
        }
    }
    
}