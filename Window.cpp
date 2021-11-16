#include "Window.h"

Window::Window(color fill, point center, unsigned int width, unsigned int height) : Quad(fill, center, width, height) {};

void Window::draw() {
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