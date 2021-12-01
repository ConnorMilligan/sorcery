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

        // wallHelper(float xStart, float xEnd, float yTStart, float yTEnd, float yBStart, float yBEnd, bool diag)
//        if(!((curr == 1 || curr == 2) && !l)) wallHelper(xLStart, xLEnd, yTStart, yTEnd, yBStart, yBEnd, diag);
//        if(!((curr == 1 || curr == 2) && !r)) wallHelper(xRStart, xREnd, yTStart, yTEnd, yBStart, yBEnd, diag);
        if(!(curr == 1 && !l)) { // Regular wall forward
            wallHelper(xLStart, xLEnd, yTStart, yTEnd, yBStart, yBEnd, diag);
        } else { // Break in wall
            glVertex2i(xLEnd, yTEnd);
            glVertex2i(xLStart, yTEnd);

            glVertex2i(xLEnd, yBEnd);
            glVertex2i(xLStart, yBEnd);
        }
        if(!(curr == 1 && !r)) { // Regular wall forward
            wallHelper(xRStart, xREnd, yTStart, yTEnd, yBStart, yBEnd, diag);
        } else { // Break in wall
            glVertex2i(xREnd, yTEnd);
            glVertex2i(xRStart, yTEnd);

            glVertex2i(xREnd, yBEnd);
            glVertex2i(xRStart, yBEnd);
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



        diag = !diag;


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
// Returns a point where the wall is finished drawing
point Viewer::drawWall(std::string direction, bool inf, bool open) {

    bool diag = true; // Should diagonal start at top or bottom?
    float tWidth = width/2;
    float tHeight = height/2;

    float end = (float)width/5;

    bool left = direction == "L";

    tWidth -= tWidth/2;
    tHeight /= 2;

    float offsetX = 0;
    float offsetY = 0;

    float xStart = left ? Quad::getLeftX() + offsetX : Quad::getRightX() - offsetX;
    float xEnd = left ? Quad::getLeftX() + tWidth + offsetX : Quad::getRightX() - tWidth - offsetX;

    float yTStart; // The top of y's upper corner
    float yBStart; // The bottom of y's upper corner
    float yTEnd; // The top of y's upper corner
    float yBEnd; // The bottom of y's lower corner

    bool condition = true;
    bool wallCondition = !open; // Is a wall drawn here

        // If we want a long hallway, we check for height and width of our new piece to be small enough
        // Otherwise, we check for each to reach 1/3 of the screen, for a 1/3 gap
        while(condition) {

        // Next generation's height for pre-emptive end point
        float newHt = tHeight / 2;

        yTStart = Quad::getTopY() + offsetY;
        yBStart = Quad::getBottomY() - offsetY;
        yTEnd = Quad::getTopY() + newHt + offsetY;
        yBEnd = Quad::getBottomY() - newHt - offsetY;

            glVertex2i(xStart, yTStart);
            glVertex2i(xStart, yBStart);

        if(wallCondition) {

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

        offsetX += tWidth;
        offsetY = Quad::getBottomY()-yBEnd;

        tWidth -= tWidth/2;
        tHeight = newHt;

        xStart = left ? (Quad::getLeftX() + offsetX) : (Quad::getRightX() - offsetX);
        xEnd = left ? (Quad::getLeftX() + tWidth + offsetX) : (Quad::getRightX() - tWidth - offsetX);


        diag = !diag;
        condition = inf ? tHeight > 1 && tWidth > 15 : (left && xStart < end) || (!left && xStart > ((float)width-end));
        wallCondition = !open && ((left && !(xStart > width/5 && xEnd < ((2*width)/5))) ||
                        (!left && !(xStart < (4*width)/5 && xEnd > (3*width)/5)));
    }

    return {(int)xStart, (int)yTEnd};

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