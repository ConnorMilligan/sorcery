#include "graphics.h"
#include "dungeonLayouts.h"
#include "SpriteSheet.h"

#include "Viewer.h"
#include "Console.h"
#include "CombatViewer.h"
#include "Menu.h"

#include "Potion.h"

#include <iostream>
#include <time.h>
#include <vector>
#define MAX_NAME_LEN 10

using namespace std;

GLdouble width = 640, height = 480;
int wd;

// Default player name before change
string playerName = "Actor";

Dungeon dungeon(fungeon2, {8,6});
Player player({1, 8} , dungeon, playerName);
Monster monster(1);

/***
 *     __      ___         _               
 *     \ \    / (_)_ _  __| |_____ __ _____
 *      \ \/\/ /| | ' \/ _` / _ \ V  V (_-<
 *       \_/\_/ |_|_||_\__,_\___/\_/\_//__/
 *                                         
 * The various windows that will display on the screen
 */
Viewer screen({BLACK}, {10, 10}, 440, 280, &player);
Window info({BLACK}, {460, 10}, 170, 460);
Console console({BLACK}, {10, 300}, 440, 170);
CombatViewer combat({BLACK}, {10, 10}, 440, 280, &player);

//The menus used in the game
Menu combatMenu({BLACK}, {460, 300}, 170, 170, {"Attack", "Defend", "Run"});
Menu inventoryMenu({BLACK}, {int(width)/2-150, 0}, 300, int(height));
Menu inventorySelector({BLACK}, {int(width)/2+160, 0}, 100, 100, {"Use", "Drop"});
Menu quitSelector({BLACK}, {int(width)/2 - 50, int(height)/2 - 50}, 100, 100, {"Yes", "No"});

//Some misc windows present in the game
Window levelingWindow({BLACK}, {int(width)/2-150, int(height)/2-115}, 300, 230);
Window miniMap({BLACK}, {int(width)/2-150, 0}, 300, int(height));
Window statsWindow({BLACK}, {int(width)/2-150, 0}, 300, int(height));


//Determine the current screen to be displayed
enum Screens { STARTING_SCREEN, SETUP_SCREEN, MAIN_SCREEN, ENDING_SCREEN, COMBAT_SCREEN, QUIT_SCREEN, MINIMAP, INVENTORY, INVENTORY_SELECT, STATS };
Screens currScreen, previousScreen, floatingWindow;

//The object containing all sprites
SpriteSheet sprites;

string consoleText, levelUpText;


Potion testPotion(HEALING);

void init() {
    currScreen = STARTING_SCREEN;
    previousScreen = STARTING_SCREEN;
    floatingWindow = MAIN_SCREEN;
    screen.surroundingProcessor();
    combat.setMonster(&monster);
    dungeon.setVisited(player.getLocation());
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

    /***
     *      ___ _            _     ___                      
     *     / __| |_ __ _ _ _| |_  / __| __ _ _ ___ ___ _ _  
     *     \__ \  _/ _` | '_|  _| \__ \/ _| '_/ -_) -_) ' \ 
     *     |___/\__\__,_|_|  \__| |___/\__|_| \___\___|_||_|
     *                                                      
     */
    if(currScreen == STARTING_SCREEN) {

        string label = "Press \'Enter\' to begin.";
        messageWriter(width/2 - (4 * label.length()), height/2 + 200, label);
        sprites.getGameLogo().draw();
    }

    /***
     *      ___      _               ___                      
     *     / __| ___| |_ _  _ _ __  / __| __ _ _ ___ ___ _ _  
     *     \__ \/ -_)  _| || | '_ \ \__ \/ _| '_/ -_) -_) ' \ 
     *     |___/\___|\__|\_,_| .__/ |___/\__|_| \___\___|_||_|
     *                       |_|                              
     */
    else if(currScreen == SETUP_SCREEN) {

        string label = "What is your name?";
        string next = "Press \'Enter\' to begin.";

        messageWriter(width/2 - (4 * label.length()), height/2, label);

        messageWriter(width/2 - (4 * playerName.length()+1), height/2 + 50, playerName+"_");

        messageWriter(width/2 - (4 * next.length()), height/2 + 200, next);
    } 
    
    /***
     *      __  __      _        ___                      
     *     |  \/  |__ _(_)_ _   / __| __ _ _ ___ ___ _ _  
     *     | |\/| / _` | | ' \  \__ \/ _| '_/ -_) -_) ' \ 
     *     |_|  |_\__,_|_|_||_| |___/\__|_| \___\___|_||_|
     *                                                    
     */
    else if(currScreen == MAIN_SCREEN) {

        screen.draw();
        info.draw();
        console.draw();
        screen.surroundingProcessor();

        //Will write to the console if there is something to write
        if (consoleText != "") {
            console.addMessage("* " + consoleText);
            consoleText = "";
        }

        //If the player levels up
        if (player.getXp() >= player.nextLvlXp()) {
            levelUpText = player.levelUp();
            consoleText = "You level up!";
        }

        //info.write( "Location: (" + to_string(player.getLocation().x) + ',' + to_string(player.getLocation().y) + ')' + "  \nFacing: " + player.getDirectionString());
        info.write(player.playerInfo());

        currScreen = (player.getLocation().x == dungeon.getEnd().x) && (player.getLocation().y == dungeon.getEnd().y) ? ENDING_SCREEN :  MAIN_SCREEN;

        //Will display the level up text if the string has been created
        if (levelUpText != "") {
            levelingWindow.draw();
            levelingWindow.write(levelUpText);
        }
        // You can only check your minimap in the main dungeon
        if(floatingWindow == MINIMAP) {
            miniMap.draw(); 
            miniMap.write(dungeon.getMapText(miniMap.getWidth(),player.getLocation()));
        }

        // Displays detailed player information
        if(floatingWindow == STATS) {
            statsWindow.draw(); 
            statsWindow.write(player.playerInfoDetailed());
        }

        //Draws inventory if flag is up
        if(floatingWindow == INVENTORY || floatingWindow == INVENTORY_SELECT) {
            inventoryMenu.setChoices(player.getInventoryString());
            inventoryMenu.draw();
            if (floatingWindow == INVENTORY_SELECT)
                inventorySelector.draw();
        }
    } 
    
    /***
     *       ___           _          _     ___                      
     *      / __|___ _ __ | |__  __ _| |_  / __| __ _ _ ___ ___ _ _  
     *     | (__/ _ \ '  \| '_ \/ _` |  _| \__ \/ _| '_/ -_) -_) ' \ 
     *      \___\___/_|_|_|_.__/\__,_|\__| |___/\__|_| \___\___|_||_|
     *                                                               
     */
    else if(currScreen == COMBAT_SCREEN) {

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

        if(!combat.isActive()) {
            if(monster.getHealth().current <= 0) {
                consoleText = "You felled the " + monster.getName() + "!";
                player.changeScore(2);
                levelUpText = player.levelUp();
            }
            currScreen = player.getHealth().current > 0 ? MAIN_SCREEN : ENDING_SCREEN;
        }
    } 
    
    /***
     *       ___       _ _     ___                      
     *      / _ \ _  _(_) |_  / __| __ _ _ ___ ___ _ _  
     *     | (_) | || | |  _| \__ \/ _| '_/ -_) -_) ' \ 
     *      \__\_\\_,_|_|\__| |___/\__|_| \___\___|_||_|
     *                                                  
     */
    else if(currScreen == QUIT_SCREEN) {
        string label = "Are you sure you want to quit SORCERY?";
        messageWriter(width/2 - (4 * label.length()), height/2 - 200, label);
        quitSelector.draw();

    } 
    
    /***
     *      ___         _   ___                      
     *     | __|_ _  __| | / __| __ _ _ ___ ___ _ _  
     *     | _|| ' \/ _` | \__ \/ _| '_/ -_) -_) ' \ 
     *     |___|_||_\__,_| |___/\__|_| \___\___|_||_|
     *                                               
     */
    else if(currScreen == ENDING_SCREEN) {

        string label = player.getHealth().current > 0 ? "You Win!" : "Game Over :(";
        label += " Score: " + to_string(player.getScore());
        messageWriter(width/2 - (4 * label.length()), height/2, label);

    }

    glFlush();  // Render now
}

void kbd(unsigned char key, int x, int y) {
    /*
    * ~Gobal~
    */
    // Will prompt the user if they wish to escape
    if (key == 27 && currScreen != ENDING_SCREEN && floatingWindow == MAIN_SCREEN) {
        previousScreen = currScreen;
        currScreen = QUIT_SCREEN;
    } else if (key == 27 && currScreen == ENDING_SCREEN) {
        glutDestroyWindow(wd);
        exit(0);
    }
    //Dismisses level up notification
    if ((key == 13) && levelUpText != "")
        levelUpText = "";

    /*
    * ~Testing inputs~
    */
    //k key levels up player (testing)
    if (key == 'k') {
        consoleText = player.addXp(1);;
    }

    //j key initiates combat (testing)
    if (key == 'j') {
        currScreen = COMBAT_SCREEN;
        consoleText = "You encountered the " + monster.getName() + "!";
    }

    //a adds a potion to the player (testing)
    if (key == 'a') {
        consoleText = player.addItem(testPotion);
    }

    /*
    * ~Setup Screen~
    */
    if (currScreen == SETUP_SCREEN) {

        //Will progress from the title screen to the setup screen when the player presses ENTER
        if((key == 13) && currScreen == SETUP_SCREEN) {
            player.setName(playerName);
            currScreen = MAIN_SCREEN;
        }

        //Checks for entered keys for entering the player name
        else if(key != 13 && currScreen == SETUP_SCREEN) {
            if(playerName.length() <= MAX_NAME_LEN && key != 8) {
                playerName += key;
            }
            if(key == 8 && !playerName.empty()) {
                playerName = playerName.substr(0,playerName.length()-1);
            }
        }
    }

    /*
    * ~Main Screen~
    */
    if (currScreen == MAIN_SCREEN) {
    
        //m key brings up a minimap
        if (key == 'm') {
            floatingWindow = MINIMAP;
        } else if (floatingWindow == MINIMAP){ // Put map away on any other keystroke
            floatingWindow = MAIN_SCREEN;
        }

        //i key brings up a inventory
        if (key == 'i') {
            floatingWindow = INVENTORY;
        } else if (key == 27 && floatingWindow == INVENTORY) { //removes with ESC
            floatingWindow = MAIN_SCREEN;
        }

        //p key brings up a detailed stats window
        if (key == 'p') {
            floatingWindow = STATS;
        } else if (key == 27 && floatingWindow == STATS) { //removes with ESC
            floatingWindow = MAIN_SCREEN;
        }
        
        //Open the submenu in the inventory
        if ((key == 13) && floatingWindow == INVENTORY) {
            floatingWindow = INVENTORY_SELECT;
        } else if ((key == 27) && floatingWindow == INVENTORY_SELECT) {
            floatingWindow = INVENTORY;
        } else if ((key == 13) && floatingWindow == INVENTORY_SELECT) { //Handles the choice of the player
            if (inventorySelector.getChoice() == "Use") {
                consoleText = player.use(inventoryMenu.getSelection());
            }
            else if (inventorySelector.getChoice() == "Drop") {
                consoleText = player.removeItem(inventoryMenu.getSelection()) + " has been discarded!";
            }
            floatingWindow = INVENTORY;
        }
    }

    /*
    * ~Combat Screen~
    */
    //initiates player turn based on selected option
    if ((key == 13) && currScreen == COMBAT_SCREEN) {
        consoleText = combat.playerTurn(combatMenu.getChoice());
    }

    /*
    * ~Starting Screen~
    */
    //When ENTER is pressed the game will progress to the setup screen
    if ((key == 13) && currScreen == STARTING_SCREEN)
        currScreen = SETUP_SCREEN;
        //currScreen = MAIN_SCREEN; // Uncomment to bypass setup screen

    /*
    * ~Quit Screen~
    */
    //If the player would like to quit the game or not
    if ((key == 13) && currScreen == QUIT_SCREEN) {
        if (quitSelector.getChoice() == "Yes") {
            glutDestroyWindow(wd);
            exit(0);
        } else if (quitSelector.getChoice() == "No") {
            currScreen = previousScreen;
        }
    }
        

    glutPostRedisplay();
}

void kbdS(int key, int x, int y) {
    /*
    * ~Main Screen~
    */
    if(currScreen == MAIN_SCREEN && floatingWindow != INVENTORY && floatingWindow != INVENTORY_SELECT) {
        screen.surroundingProcessor();

        //movement
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
                if (ENCOUNTER_RATE > rand() % 100) {
                    currScreen = COMBAT_SCREEN;
                    monster = Monster(player.getLevel());
                    consoleText = "You encountered the " + monster.getName() + "!";
                    combat.toggleState();
                }
                break;
        }
        if(!dungeon.isVisited(player.getLocation())) {
            dungeon.setVisited(player.getLocation());
            player.changeScore(1);
        }

    }

    /*
    * ~Combat Menu~
    */
    else if(currScreen == COMBAT_SCREEN && floatingWindow != INVENTORY) {
        switch (key) {
            case GLUT_KEY_DOWN:
                combatMenu.choiceDown();
                break;
            case GLUT_KEY_UP:
                combatMenu.choiceUp();
                break;
        }
    }

    /*
    * ~Inventory Menu~
    */
    else if(floatingWindow == INVENTORY) {
        switch (key) {
            case GLUT_KEY_DOWN:
                inventoryMenu.choiceDown();
                break;
            case GLUT_KEY_UP:
                inventoryMenu.choiceUp();
                break;
        }
    }

    /*
    * ~Inventory Selection Menu~
    */
    else if(floatingWindow == INVENTORY_SELECT) {
        switch (key) {
            case GLUT_KEY_DOWN:
                inventorySelector.choiceDown();
                break;
            case GLUT_KEY_UP:
                inventorySelector.choiceUp();
                break;
        }
    }

    /*
    * ~Quit Menu~
    */
    else if(currScreen == QUIT_SCREEN) {
        switch (key) {
            case GLUT_KEY_DOWN:
                quitSelector.choiceDown();
                break;
            case GLUT_KEY_UP:
                quitSelector.choiceUp();
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
