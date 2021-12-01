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

// Create walls procedurally given:
// left - boolean denoting if this is the left, or inferrable right wall
// int width - desired width of the wall
// int height - desired height of the wall
//
//
void Viewer::drawWall(bool left, int width, int height, int a) {

    bool diag = true; // Should diagonal start at top or bottom?


    width -= width/2;
    height /= 2;

    float offsetX = 0;
    float offsetY = 0;

    float xStart = left ? Quad::getLeftX() + offsetX : Quad::getRightX() - offsetX;
    float xEnd = left ? Quad::getLeftX() + width + offsetX : Quad::getRightX() - width - offsetX;

    while(width > 1 && height > 1) {



        float newHt = height / 2;


//        int yStart = Quad::getTopY() + height + offsetY;
//        int yEnd = Quad::getBottomY() - height - offsetY;
        float yTStart = Quad::getTopY() + offsetY;
        float yBStart = Quad::getBottomY() - offsetY;
        float yTEnd = Quad::getTopY() + newHt + offsetY;
        float yBEnd = Quad::getBottomY() - newHt - offsetY;

        // Vertical lines to split walls
        glVertex2i(xStart, yTStart);
        glVertex2i(xEnd, yTEnd);

        glVertex2i(xEnd, yTEnd);
        glVertex2i(xEnd, yBEnd);

        // Horizontal lines adjoining ceiling
        glVertex2i(xStart, yBStart);
        glVertex2i(xEnd, yBEnd);

        if(diag) {
            glVertex2i(xStart, yTStart);
            glVertex2i(xEnd,yBEnd);
        } else {
            glVertex2i(xStart, yBStart);
            glVertex2i(xEnd, yTEnd);
        }
//
//        glVertex2i(xStart, yEnd);
//        glVertex2i(xEnd,Quad::getBottomY()-offsetY);

        //float ht = Quad::getBottomY() - Quad::getTopY();
        offsetX += width;
        offsetY = Quad::getBottomY()-yBEnd;

        width -= width/2;
        height = newHt;




        xStart = left ? (Quad::getLeftX() + offsetX) : (Quad::getRightX() - offsetX);
        xEnd = left ? (Quad::getLeftX() + width + offsetX) : (Quad::getRightX() - width - offsetX);


        diag = !diag;

    }

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
    bool openCondition = open;

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

        if(openCondition) {

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
        openCondition = (left && !(xStart > width/5 && xEnd < ((2*width)/5))) ||
                        (!left && !(xStart < (4*width)/5 && xEnd > (3*width)/5));
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


    point rEnd = r ? drawWall("R", true, false) : drawWall("R", false, true);
    point lEnd = l ? drawWall("L", true, false) : drawWall("L", false, true);
    int bottom = Quad::getBottomY();

    if(f) {
        glVertex2i(rEnd.x, rEnd.y);
        glVertex2i(lEnd.x, lEnd.y);

        glVertex2i(rEnd.x, bottom-rEnd.y);
        glVertex2i(lEnd.x, bottom-rEnd.y);
    }

//    if(!f) {
//        point lEnd = drawWall("L", true);
//        point rEnd = drawWall("R", true);
//    }
//    point lEnd = drawWall("L", true);
//    point rEnd = drawWall("R", false);
//
//    glVertex2i(rEnd.x, rEnd.y);
//    glVertex2i(lEnd.x, rEnd.y);
//
//    glVertex2i(rEnd.x, Quad::getBottomY()-rEnd.y+6);
//    glVertex2i(lEnd.x, Quad::getBottomY()-rEnd.y+6);

//    glVertex2i(Quad::getLeftX() + 140, Quad::getTopY() + 50);
//    glVertex2i(Quad::getLeftX() + 140, Quad::getBottomY());
//
//    glVertex2i(Quad::getRightX() - 140, Quad::getTopY() + 50);
//    glVertex2i(Quad::getRightX() - 140, Quad::getBottomY());

    // Standard wall width open and closed
    int wwc = 90;
    int wwo = 50;

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