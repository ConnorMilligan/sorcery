#include "Viewer.h"

Viewer::Viewer(color fill, point center, unsigned int width, unsigned int height) : Quad(fill, center, width, height) {
    this->surrounding.front = {0,0};
    this->surrounding.left = {0,0};
    this->surrounding.right = {0,0};
}

Viewer::Viewer(color fill, point center, unsigned int width, unsigned int height, Player *player) : Quad(fill, center, width, height) {
    this->surrounding.front = {0,0};
    this->surrounding.left = {0,0};
    this->surrounding.right = {0,0};
    this->player = player;
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

// Create walls procedurally given:
// left - boolean denoting if this is the left, or inferrable right wall
// int width - desired width of the wall
// int height - desired height of the wall
// int slices - amount of wall panels to generate along the width
//
// known bugs: the algorithm is a little janky, and does not currently generate a wall of desired width
// it currently generates a wall with a width of:
// summation of n/slices * width
// So for width = 500 and slices = 3, it generates 500+250+125 = 875px
//
//
void Viewer::drawWall(bool left, int width, int height, int slices) {



    bool diag = true; // Should diagonal start at top or bottom?




    int offsetX = 0;
    int offsetY = 0;

    for(int i=slices-1;i>=0;i--) {

//        width -= ((i/slices)*width);
//        height -= ((i/slices)*height);

//        width *= i/slices;
//        height *= i/slices;

        int xStart = left ? Quad::getLeftX() + width + offsetX : Quad::getRightX() - width - offsetX;
        int xEnd = left ? Quad::getLeftX() + offsetX : Quad::getRightX() - offsetX;

//        int yStart = Quad::getTopY() + height + offsetY;
//        int yEnd = Quad::getBottomY() - height - offsetY;
        int yStart = Quad::getTopY() + height + offsetY;
        int yEnd = Quad::getBottomY() - height - offsetY;


        // Vertical lines to split walls
        glVertex2i(xStart, yEnd);
        glVertex2i(xStart, yStart);

        // Horizontal lines adjoining ceiling
        glVertex2i(xStart, yStart);
        glVertex2i(xEnd,Quad::getTopY()+offsetY);

        if(diag) {
            glVertex2i(xStart, yStart);
            glVertex2i(xEnd,getBottomY()-offsetY);
        } else {
            glVertex2i(xEnd, getTopY()+offsetY);
            glVertex2i(xStart,yEnd);
        }

        glVertex2i(xStart, yEnd);
        glVertex2i(xEnd,Quad::getBottomY()-offsetY);

        offsetX += width;
        offsetY += height;


        width /= 2;
        height /= 2;


        diag = !diag;

    }



}


Surrounding Viewer::getSurroundings() {
    return this->surrounding;
}

void Viewer::draw() {
    Quad::draw();

    point left = this->surrounding.left;
    point front = this->surrounding.front;
    point right = this->surrounding.right;

    bool l = this->player->getDungeon().getTile(left);
    bool r = this->player->getDungeon().getTile(right);
    bool f = this->player->getDungeon().getTile(front);

    glBegin(GL_LINES);
    glColor3f(WHITE);

    glVertex2i(Quad::getLeftX() + 140, Quad::getTopY() + 50);
    glVertex2i(Quad::getLeftX() + 140, Quad::getBottomY());

    glVertex2i(Quad::getRightX() - 140, Quad::getTopY() + 50);
    glVertex2i(Quad::getRightX() - 140, Quad::getBottomY());

    // Standard wall width open and closed
    int wwc = 90;
    int wwo = 50;

    if (l) {
        glVertex2i(Quad::getLeftX() + 40, Quad::getTopY());
        glVertex2i(Quad::getLeftX() + 40, Quad::getBottomY());

        glVertex2i(Quad::getLeftX() + 140, Quad::getTopY() + 50);
        glVertex2i(Quad::getLeftX() + 40, Quad::getTopY());
    } else {
        glVertex2i(Quad::getLeftX() + 140, Quad::getTopY() + 50);
        glVertex2i(Quad::getLeftX(), Quad::getTopY() + 50);
    }

    if (r) {
        glVertex2i(Quad::getRightX() - 40, Quad::getTopY());
        glVertex2i(Quad::getRightX() - 40, Quad::getBottomY());

        glVertex2i(Quad::getRightX() - 140, Quad::getTopY() + 50);
        glVertex2i(Quad::getRightX() - 40, Quad::getTopY());
    } else {
        glVertex2i(Quad::getRightX() - 140, Quad::getTopY() + 50);
        glVertex2i(Quad::getRightX(), Quad::getTopY() + 50);
    }

    if (f) { 
        glVertex2i(Quad::getRightX() - 140, Quad::getTopY() + 50);
        glVertex2i(Quad::getLeftX() + 140, Quad::getTopY() + 50);
    }


    // Front wall generation
    //int lineLeft = Quad::getLeftX() + (1.75 * (l ? wwc : wwo));
    //int lineRight = Quad::getRightX() - (1.75 * (r ? wwc : wwo));

    //int lineTop = Quad::getTopY() + (l&&r ? (wwc)*2 : wwo*1.75);
    //int lineBottom = Quad::getBottomY() - (l&&r ? (wwc)*2 : wwo*1.75);

    //glVertex2i(lineLeft, lineTop);
    //glVertex2i(lineRight, lineTop);

    //glVertex2i(lineLeft, lineBottom);
    //glVertex2i(lineRight, lineBottom);

    
    glEnd();
}