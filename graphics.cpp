#include "graphics.h"
#include "dungeonLayouts.h"
#include "Viewer.h"
#include "Player.h"
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

GLdouble width, height;
int wd;

Dungeon dungeon(fungeon2, {8,6});
Player player({1, 8} , dungeon);

Viewer screen({BLACK}, {10, 10}, 440, 280, &player);
Quad info({BLACK}, {460, 10}, 170, 460);
Quad console({BLACK}, {10, 300}, 440, 170);
enum Screens { STARTING_SCREEN, MAIN_SCREEN, ENDING_SCREEN };
Screens currScreen;


void init() {
    width = 640;
    height = 480;
    currScreen = STARTING_SCREEN;
    screen.surroundingProcessor();
    srand(time(0));
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);
    
    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);
    
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    if(currScreen == STARTING_SCREEN) {

        string label = "SORCERY";
        messageWriter(width/2 - (4 * label.length()), height/2, label);

    } else if(currScreen == MAIN_SCREEN) {



        screen.draw();
        info.draw();
        console.draw();
        screen.surroundingProcessor();


        console.write("Surroundings: " + to_string(dungeon.getTile(screen.getSurroundings().left)) + " " +
                                to_string(dungeon.getTile(screen.getSurroundings().front)) + " " +
                                to_string(dungeon.getTile(screen.getSurroundings().right)));

        //info.write( "Location: (" + to_string(player.getLocation().x) + ',' + to_string(player.getLocation().y) + ')' + "  \nFacing: " + player.getDirectionString());
        info.write(player.playerInfo());

        currScreen = (player.getLocation().x == dungeon.getEnd().x) && (player.getLocation().y == dungeon.getEnd().y) ? ENDING_SCREEN :  MAIN_SCREEN;

    } else if(currScreen == ENDING_SCREEN) {

        string label = "You Win!";
        messageWriter(width/2 - (4 * label.length()), height/2, label);

    }

    glFlush();  // Render now
}

void kbd(unsigned char key, int x, int y) {
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }
    if ((key == 115 || key == 83) && currScreen == STARTING_SCREEN) {
        currScreen = MAIN_SCREEN;
    }

    glutPostRedisplay();
}

void kbdS(int key, int x, int y) {
    if(currScreen == MAIN_SCREEN) {
        screen.surroundingProcessor();

        switch (key) {
            case GLUT_KEY_DOWN:
                player.retreat();
                break;
            case GLUT_KEY_LEFT:
                player.turnLeft();
                break;
            case GLUT_KEY_RIGHT:
                player.turnRight();
                break;
            case GLUT_KEY_UP:
                player.advance();
                break;
        }

    }

    glutPostRedisplay();
}

void timer(int dummy) {
    glutPostRedisplay();
    glutTimerFunc(30, timer, dummy);
}

void messageWriter(int x, int y, std::string message) {
    glColor3f(WHITE);
    glRasterPos2i(x, y);

    for (const char &letter : message) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    
    init();
    
    glutInit(&argc, argv);          // Initialize GLUT
    
    glutInitDisplayMode(GLUT_RGBA);
    
    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(100, 200); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("SORCERY!" /* title */ );
    
    // Register callback handler for window re-paint event
    glutDisplayFunc(display);
    
    // Our own OpenGL initialization
    initGL();
    
    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);
    
    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);
    
    // handles timer
    glutTimerFunc(0, timer, 0);
    
    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}
