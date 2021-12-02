#include "Viewer.h"

Viewer::Viewer(color fill, point center, unsigned int width, unsigned int height) : Window(fill, center, width, height) {
    this->surrounding.front = {0,0};
    this->surrounding.left = {0,0};
    this->surrounding.right = {0,0};
}

Viewer::Viewer(color fill, point center, unsigned int width, unsigned int height, Player *player) : Window(fill, center, width, height) {
    this->surrounding.front = {0,0};
    this->surrounding.left = {0,0};
    this->surrounding.right = {0,0};
    this->player = player;
}

Surrounding Viewer::getSurroundings() {
    return this->surrounding;
}

void Viewer::surroundingProcessor() {
    this->surrounding.left = this->player->getLocation();
    this->surrounding.right = this->player->getLocation();
    this->surrounding.front = this->player->getLocation();

    switch (this->player->getDirection()) {
        case NORTH:
            this->surrounding.left.x--;
            this->surrounding.right.x++;
            this->surrounding.front.y--;
            break;
        case EAST:
            this->surrounding.left.y--;
            this->surrounding.right.y++;
            this->surrounding.front.x++;
            break;
        case SOUTH:
            this->surrounding.left.x++;
            this->surrounding.right.x--;
            this->surrounding.front.y++;
            break;
        case WEST:
            this->surrounding.left.y++;
            this->surrounding.right.y--;
            this->surrounding.front.x--;
            break;
        
        default:
            break;
    }
    
}

void Viewer::wallHelper(float xStart, float xEnd, float yTStart, float yTEnd, float yBStart, float yBEnd, bool diag) {
    // First vertical line
    glVertex2i(xStart, yTStart);
    glVertex2i(xStart, yBStart);


    // Vertical lines to split walls
    glVertex2i(xStart, yTStart);
    glVertex2i(xEnd, yTEnd);

    glVertex2i(xEnd, yTEnd);
    glVertex2i(xEnd, yBEnd);

    // Horizontal lines adjoining ceiling
    glVertex2i(xStart, yBStart);
    glVertex2i(xEnd, yBEnd);

    if (diag) {
        glVertex2i(xStart, yTStart);
        glVertex2i(xEnd, yBEnd);
    } else {
        glVertex2i(xStart, yBStart);
        glVertex2i(xEnd, yTEnd);
    }
}

// Create walls procedurally given:
// left - boolean denoting if this is the left, or inferrable right wall
// int width - desired width of the wall
// int height - desired height of the wall
//
//
void Viewer::drawWall(bool l, bool r, bool f) {

    bool diag = true; // Should diagonal start at top or bottom?
    float tWidth = width/2;
    float tHeight = height/2;

    int curr = 0; // Current section(1/5 && 2/4 && 3)
    float section = (float)width/5;

    bool drawL = l;
    bool drawR = r;
    //bool left = direction == "L";

    tWidth -= tWidth/2;
    tHeight /= 2;

    float offsetX = 0;
    float offsetY = 0;

    float lastX = 0;

    float xLStart = Quad::getLeftX() + offsetX;
    float xRStart = Quad::getRightX() - offsetX;
    float xLEnd = Quad::getLeftX() + tWidth + offsetX;
    float xREnd = Quad::getRightX() - tWidth - offsetX;

    float yTStart; // The top of y's upper corner
    float yBStart; // The bottom of y's upper corner
    float yTEnd; // The top of y's upper corner
    float yBEnd; // The bottom of y's lower corner

    bool condition = true;

    // If we want a long hallway, we check for height and width of our new piece to be small enough
    // Otherwise, we check for each to reach 1/3 of the screen, for a 1/3 gap
    while(tHeight > 1 && tWidth > 10) {




        // Next generation's height for pre-emptive end point
        float newHt = tHeight / 2;

        yTStart = Quad::getTopY() + offsetY;
        yBStart = Quad::getBottomY() - offsetY;
        yTEnd = Quad::getTopY() + newHt + offsetY;
        yBEnd = Quad::getBottomY() - newHt - offsetY;

//        if(!((curr == 0 || curr == 2 || curr == 1) && !l)) { // Regular wall forward
        if(!((curr == 2 || curr == 1) && !l)) { // Regular wall forward
            wallHelper(xLStart, xLEnd, yTStart, yTEnd, yBStart, yBEnd, diag);
        } else { // Break in wall
            if(curr == 1) {

//                int tYTEnd = Quad::getTopY() + (newHt/2) + offsetY;
//                int tYBEnd = Quad::getBottomY() - (newHt/2)- offsetY;
                glVertex2i(xLEnd, yTEnd);
                glVertex2i(xLStart, yTEnd);

                glVertex2i(xLEnd, yBEnd);
                glVertex2i(xLStart, yBEnd);
            } else {
                glVertex2i(xLEnd, yTEnd);
                glVertex2i(xLStart, yTEnd);

                glVertex2i(xLEnd, yBEnd);
                glVertex2i(xLStart, yBEnd);
            }



//            glVertex2i(xLEnd, yTEnd);
//            glVertex2i(Quad::getLeftX(), yTEnd);
//
//            glVertex2i(xLEnd, yBEnd);
//            glVertex2i(Quad::getLeftX(), yBEnd);

        }
        if(!((curr == 2 || curr == 1) && !r)) { // Regular wall forward
            wallHelper(xRStart, xREnd, yTStart, yTEnd, yBStart, yBEnd, diag);
        } else { // Break in wall
            glVertex2i(xREnd, yTEnd);
            glVertex2i(xRStart, yTEnd);

            glVertex2i(xREnd, yBEnd);
            glVertex2i(xRStart, yBEnd);
//            glVertex2i(xREnd, yTEnd);
//            glVertex2i(Quad::getRightX(), yTEnd);
//
//            glVertex2i(xREnd, yBEnd);
//            glVertex2i(Quad::getRightX(), yBEnd);
        }

        if(curr == 2 && f) {
            glVertex2i(xLEnd, yTEnd);
            glVertex2i(xREnd, yTEnd);

            glVertex2i(xLEnd, yBEnd);
            glVertex2i(xREnd, yBEnd);
            break;
        }

        offsetX += tWidth;
        offsetY = Quad::getBottomY()-yBEnd;

        tWidth -= tWidth/2;
        tHeight = newHt;

        xLStart = (Quad::getLeftX() + offsetX);
        xRStart = (Quad::getRightX() - offsetX);
        xLEnd = (Quad::getLeftX() + tWidth + offsetX);
        xREnd = (Quad::getRightX() - tWidth - offsetX);

        diag = !diag; // Invert diagonal

        curr++; // Next section of wall


    }
//    if(!f) {
//        glVertex2i(xLStart, yTEnd+(offsetY/6));
//        glVertex2i(xRStart, yTEnd+(offsetY/6));
//
//        glVertex2i(xLStart, yBEnd-(offsetY/6));
//        glVertex2i(xRStart, yBEnd-(offsetY/6));
//    }


}





void Viewer::draw() {
    Window::draw();

    point left = this->surrounding.left;
    point front = this->surrounding.front;
    point right = this->surrounding.right;

    bool l = this->player->getDungeon().getTile(left);
    bool r = this->player->getDungeon().getTile(right);
    bool f = this->player->getDungeon().getTile(front);

    glBegin(GL_LINES);
    glColor3f(WHITE);


    drawWall(l, r, f);






//    glVertex2i(Quad::getLeftX() + 140, Quad::getTopY() + 50);
//    glVertex2i(Quad::getLeftX() + 140, Quad::getBottomY());
//
//    glVertex2i(Quad::getRightX() - 140, Quad::getTopY() + 50);
//    glVertex2i(Quad::getRightX() - 140, Quad::getBottomY());
//
//
//
//    if (l) {
//        glVertex2i(Quad::getLeftX() + 40, Quad::getTopY());
//        glVertex2i(Quad::getLeftX() + 40, Quad::getBottomY());
//
//        glVertex2i(Quad::getLeftX() + 140, Quad::getTopY() + 50);
//        glVertex2i(Quad::getLeftX() + 40, Quad::getTopY());
//    } else {
//        glVertex2i(Quad::getLeftX() + 140, Quad::getTopY() + 50);
//        glVertex2i(Quad::getLeftX(), Quad::getTopY() + 50);
//    }
//
//    if (r) {
//        glVertex2i(Quad::getRightX() - 40, Quad::getTopY());
//        glVertex2i(Quad::getRightX() - 40, Quad::getBottomY());
//
//        glVertex2i(Quad::getRightX() - 140, Quad::getTopY() + 50);
//        glVertex2i(Quad::getRightX() - 40, Quad::getTopY());
//    } else {
//        glVertex2i(Quad::getRightX() - 140, Quad::getTopY() + 50);
//        glVertex2i(Quad::getRightX(), Quad::getTopY() + 50);
//    }
//
//    if (f) {
//        glVertex2i(Quad::getRightX() - 140, Quad::getTopY() + 50);
//        glVertex2i(Quad::getLeftX() + 140, Quad::getTopY() + 50);
//    }




    
    glEnd();
}