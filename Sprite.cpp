#include "Sprite.h"

Sprite::Sprite(int width, int height, const char *pixels) {
    this->dimensions.width = width;
    this->dimensions.height = height;
    this->pixels = pixels;
}

void Sprite::draw() {
    int pixColor[3];
    char *pixel = (char *) malloc(sizeof(this->pixels));;

    strncpy(pixel, this->pixels, sizeof(pixel));

    for (int i = 0; i < this->dimensions.width; i++) {
        for (int j = 0; j < this->dimensions.height; j++) {
            HEADER_PIXEL(pixel, pixColor);
            Quad(color{(double)(pixColor[0]/255), (double)(pixColor[1]/255), (double)(pixColor[2]/255)}, point{i,j}, 1, 1).draw();
        }
    }

    free(pixel);
    
}