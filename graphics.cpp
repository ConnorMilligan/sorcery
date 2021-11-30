#include "graphics.h"
#include "dungeonLayouts.h"
#include "spriteSheet.h"

#include "Viewer.h"
#include "Console.h"
#include "CombatViewer.h"
#include "Menu.h"

#include <iostream>
#include <time.h>
#include <vector>
#define MAX_NAME_LEN 10

using namespace std;

GLdouble width = 640, height = 480;
int wd;

// Default player name before change
string playerName = "Actor";
vector<string> combatOptions = {"Attack", "Defend", "Run"};


Dungeon dungeon(fungeon2, {8,6});
Player player({1, 8} , dungeon, playerName);
Monster monster(1);

//The various windows that will display on the screen
Viewer screen({BLACK}, {10, 10}, 440, 280, &player);
Window info({BLACK}, {460, 10}, 170, 460);
Console console({BLACK}, {10, 300}, 440, 170);
CombatViewer combat({BLACK}, {10, 10}, 440, 280, &player);
Menu combatMenu({BLACK}, {460, 300}, 170, 170, combatOptions);

Window levelingWindow({BLACK}, {int(width)/2-150, int(height)/2-115}, 300, 230);

//Determine the current screen to be displayed
enum Screens { STARTING_SCREEN, SETUP_SCREEN, MAIN_SCREEN, ENDING_SCREEN, COMBAT_SCREEN };
Screens currScreen;


string consoleText, levelUpText;

Sprite gameLogo;


void init() {
    currScreen = STARTING_SCREEN;
    screen.surroundingProcessor();
    combat.setMonster(&monster);
    srand(time(0));
    gameLogo = Sprite(menuLogo, {50,100});
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

    } else if(currScreen == SETUP_SCREEN) {

        string label = "What is your name?";
        string next = "Press \'Enter\' to begin.";

        messageWriter(width/2 - (4 * label.length()), height/2, label);

        messageWriter(width/2 - (4 * playerName.length()+1), height/2 + 50, playerName+"_");

        messageWriter(width/2 - (4 * next.length()), height/2 + 200, next);


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

    } else if(currScreen == COMBAT_SCREEN) {

        if(combat.isActive()) {

        info.draw();
        console.draw();
        combat.draw();

        if (consoleText != "") {
            console.addMessage("* " + consoleText);
            consoleText = "";
        }
            
        info.write(player.playerInfo());

        //Draw the combat menu over the infobox
        combatMenu.draw();

        if (levelUpText != "") {
            levelingWindow.draw();
            levelingWindow.write(levelUpText);
        }

        } else {
            if(player.getHealth().current > 0 && monster.getHealth().current <= 0) levelUpText = "LEVEL UP";
            currScreen = player.getHealth().current > 0 ? MAIN_SCREEN : ENDING_SCREEN;
        }

    } else if(currScreen == ENDING_SCREEN) {

        string label = player.getHealth().current > 0 ? "You Win!" : "Game Over :(";
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
    if((key == 13) && currScreen == SETUP_SCREEN) {
        player.setName(playerName);
        currScreen = MAIN_SCREEN;
    }
    if((currScreen == SETUP_SCREEN) && key != 13) {
        if(playerName.length() <= MAX_NAME_LEN && key != 8) {
            playerName += key;
        }
        if(key == 8 && !playerName.empty()) {
            playerName = playerName.substr(0,playerName.length()-1);
        }
    }
    if ((key == 13) && currScreen == STARTING_SCREEN)
        currScreen = SETUP_SCREEN;
        //currScreen = MAIN_SCREEN; // Uncomment to bypass setup screen

    if ((key == 13) && levelUpText != "")
        levelUpText = "";

    if (key == 'k') {
        levelUpText = player.levelUp();
        consoleText = "You level up!";
    }
    if (key == 'j') {
        currScreen = COMBAT_SCREEN;
        consoleText = "You encountered " + monster.getName() + "!";
    }
    if ((key == 13) && currScreen == COMBAT_SCREEN) {

        //consoleText = combat.attack();
        consoleText = combat.playerTurn(combatMenu.getChoice());

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
    else if(currScreen == COMBAT_SCREEN) {
        switch (key) {
            case GLUT_KEY_DOWN:
                combatMenu.choiceDown();
                break;
            case GLUT_KEY_UP:
                combatMenu.choiceUp();
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
