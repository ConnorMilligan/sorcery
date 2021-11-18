#include "Window.h"

Window::Window(color fill, point center, unsigned int width, unsigned int height) : Quad(fill, center, width, height) {};

void Window::draw() {
    //Draw the corners
    int relativeX, relativeY;
    for (int i = 0; i < 4; i++) {
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1,1,1);

        relativeX = (i == 1 || i == 2) ? origin.x + width - BORDER_THICKNESS : origin.x + BORDER_THICKNESS;
        relativeY = (i == 2 || i == 3) ? origin.y + BORDER_THICKNESS : origin.y + height - BORDER_THICKNESS;

        for (double j = 0; j < 2.0*PI+0.05; j += (2.0*PI)/360.0) {
            glVertex2f(relativeX + (BORDER_THICKNESS * cos(j)),
                    relativeY + (BORDER_THICKNESS * sin(j)));
        }
        glEnd();
    }

    glBegin(GL_QUADS);

    //Draw borders
    glColor3f(1,1,1);
    glVertex2i(origin.x + BORDER_THICKNESS, origin.y);
    glVertex2i(origin.x + width - BORDER_THICKNESS, origin.y);
    glVertex2i(origin.x + width - BORDER_THICKNESS, origin.y + height);
    glVertex2i(origin.x + BORDER_THICKNESS, origin.y + height);

    glVertex2i(origin.x, origin.y + BORDER_THICKNESS);
    glVertex2i(origin.x + width, origin.y + BORDER_THICKNESS);
    glVertex2i(origin.x + width, origin.y + height - BORDER_THICKNESS);
    glVertex2i(origin.x, origin.y + height - BORDER_THICKNESS);

    //Draw inside
    glColor3f(fill.red,fill.green,fill.blue);

    glVertex2i(origin.x + BORDER_THICKNESS, origin.y + BORDER_THICKNESS);
    glVertex2i(origin.x+width - BORDER_THICKNESS, origin.y + BORDER_THICKNESS);
    glVertex2i(origin.x+width - BORDER_THICKNESS, origin.y+height - BORDER_THICKNESS);
    glVertex2i(origin.x + BORDER_THICKNESS, origin.y+height - BORDER_THICKNESS);

    glEnd();
}