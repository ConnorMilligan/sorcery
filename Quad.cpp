#include "Quad.h"

Quad::Quad() {
    fill = {0, 0, 0};
    origin = {0, 0};
    width = 50;
    height = 50;
}

Quad::Quad(color fill, point origin, unsigned int width, unsigned int height) {
    this->fill = fill;
    this->origin = origin;
    this->width = width;
    this->height = height;
}

int Quad::getCenterX() const {
    return origin.x + (width/2);
}

int Quad::getLeftX() const {
    return origin.x;
}

int Quad::getRightX() const {
    return origin.x + width;
}

int Quad::getCenterY() const {
    return origin.y + (height/2);
}

int Quad::getTopY() const {
    return origin.y;
}

int Quad::getBottomY() const {
    return origin.y + height;
}

point Quad::getCenter() const {
    return {getCenterX(), getCenterY()};
}

double Quad::getRed() const {
    return fill.red;
}

double Quad::getGreen() const {
    return fill.green;
}

double Quad::getBlue() const {
    return fill.blue;
}

color Quad::getFill() const {
    return fill;
}

unsigned int Quad::getWidth() const {
    return width;
}

unsigned int Quad::getHeight() const {
    return height;
}

void Quad::setColor(double red, double green, double blue) {
    fill = {red, green, blue};
}

void Quad::setColor(color fill) {
    this->fill = fill;
}

void Quad::move(int deltaX, int deltaY) {
    origin.x += deltaX;
    origin.y += deltaY;
}

void Quad::resize(unsigned int width, unsigned int height) {
    this->width = width;
    this->height = height;
}

void Quad::draw() const {
    glBegin(GL_QUADS);

    //Draw border
    glColor3f(1,1,1);
    glVertex2i(origin.x, origin.y);
    glVertex2i(origin.x+width, origin.y);
    glVertex2i(origin.x+width, origin.y+height);
    glVertex2i(origin.x, origin.y+height);

    //Draw inside
    glColor3f(fill.red,fill.green,fill.blue);

    glVertex2i(origin.x + BORDER_THICKNESS, origin.y + BORDER_THICKNESS);
    glVertex2i(origin.x+width - BORDER_THICKNESS, origin.y + BORDER_THICKNESS);
    glVertex2i(origin.x+width - BORDER_THICKNESS, origin.y+height - BORDER_THICKNESS);
    glVertex2i(origin.x + BORDER_THICKNESS, origin.y+height - BORDER_THICKNESS);

    glEnd();

}

void Quad::write(std::string message) {
    glColor3f(WHITE);
    glRasterPos2i(this->getLeftX() + TEXT_PADDING_X, this->getTopY() + TEXT_PADDING_Y);
    int count = 0, line = 1;

    for (const char &letter : message) {
        if (count*9+this->getLeftX() < (this->getRightX()) - TEXT_PADDING_X && letter != '\n') {
            ++count;
        } 
        else {
            glRasterPos2i(this->getLeftX() + TEXT_PADDING_X, this->getTopY() + (++line*TEXT_PADDING_Y));
            count = 0;
            continue;
        }
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }
}