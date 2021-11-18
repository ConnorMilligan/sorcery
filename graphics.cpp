#include "graphics.h"
#include "dungeonLayouts.h"
#include "Viewer.h"
#include "Console.h"
#include "Player.h"
#include "Sprite.h"
#include "spriteSheet.h"
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

GLdouble width = 640, height = 480;
int wd;

Dungeon dungeon(fungeon2, {8,6});
Player player({1, 8} , dungeon);

//The various windows that will display on the screen
Viewer screen({BLACK}, {10, 10}, 440, 280, &player);
Window info({BLACK}, {460, 10}, 170, 460);
Console console({BLACK}, {10, 300}, 440, 170);

Window levelingWindow({BLACK}, {int(width)/2-150, int(height)/2-115}, 300, 230);

//Determine the current screen to be displayed
enum Screens { STARTING_SCREEN, MAIN_SCREEN, ENDING_SCREEN };
Screens currScreen;


string consoleText, levelUpText;

Sprite gameLogo(menuLogo.width, menuLogo.height, {50,100}, menuLogo.sprite);


void init() {
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

        string label = "Press \'Enter\' to begin.";
        messageWriter(width/2 - (4 * label.length()), height/2 + 200, label);
        gameLogo.draw();

    } else if(currScreen == MAIN_SCREEN) {



        screen.draw();
        info.draw();
        console.draw();
        screen.surroundingProcessor();


        //console.write("Surroundings: " + to_string(dungeon.getTile(screen.getSurroundings().left)) + " " +
        //                        to_string(dungeon.getTile(screen.getSurroundings().front)) + " " +
        //                        to_string(dungeon.getTile(screen.getSurroundings().right)));
        if (consoleText != "") {
            console.addMessage("* " + consoleText);
            consoleText = "";
        }
            

        //info.write( "Location: (" + to_string(player.getLocation().x) + ',' + to_string(player.getLocation().y) + ')' + "  \nFacing: " + player.getDirectionString());
        info.write(player.playerInfo());

        currScreen = (player.getLocation().x == dungeon.getEnd().x) && (player.getLocation().y == dungeon.getEnd().y) ? ENDING_SCREEN :  MAIN_SCREEN;


        if (levelUpText != "") {
            levelingWindow.draw();
            levelingWindow.write(levelUpText);
        }

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
    if ((key == 13) && currScreen == STARTING_SCREEN) 
        currScreen = MAIN_SCREEN;

    if ((key == 13) && levelUpText != "")
        levelUpText = "";

    if (key == 'k') {
        levelUpText = player.levelUp();
        consoleText = "You level up!";
    }

    glutPostRedisplay();
}

void kbdS(int key, int x, int y) {
    if(currScreen == MAIN_SCREEN) {
        screen.surroundingProcessor();

        switch (key) {
            case GLUT_KEY_DOWN:
                player.retreat();
                consoleText = "You retreat!";
                break;
            case GLUT_KEY_LEFT:
                player.turnLeft();
                consoleText = "You turn to the left!";
                break;
            case GLUT_KEY_RIGHT:
                player.turnRight();
                consoleText = "You turn to the right!";
                break;
            case GLUT_KEY_UP:
                player.advance() ? consoleText = "You advance!" : consoleText = "Ouch! You can't walk into a wall!";
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
