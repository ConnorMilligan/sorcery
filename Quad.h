#ifndef GRAPHICS_QUAD_H
#define GRAPHICS_QUAD_H
#include <GL/glut.h>

#ifdef _WIN32
#include <windows.h>
#endif

#include <string>
#include "graphics.h"

#define BORDER_THICKNESS 5
#define TEXT_PADDING_X 25
#define TEXT_PADDING_Y 30

struct color {
    double red;
    double green;
    double blue;
};

struct point {
    int x;
    int y;
};

class Quad {
protected:
    color fill;
    point origin;
    unsigned int width;
    unsigned int height;

public:
    Quad();
    Quad(color fill, point center, unsigned int width, unsigned int height);

    int getCenterX() const;
    int getLeftX() const;
    int getRightX() const;
    int getCenterY() const;
    int getTopY() const;
    int getBottomY() const;
    point getCenter() const;

    double getRed() const;
    double getGreen() const;
    double getBlue() const;
    color getFill() const;

    unsigned int getWidth() const;
    unsigned int getHeight() const;

    void setColor(double red, double green, double blue);
    void setColor(color fill);
    void move(int deltaX, int deltaY);
    void resize(unsigned int width, unsigned int height);

    virtual void draw() const;
    void write(std::string message);
};

#endif
