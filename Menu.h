/*
* Inherits from the Window,
* A navigable menu in a quad.
*/

#ifndef GRAPHICS_MENU_H
#define GRAPHICS_MENU_H

#include "Window.h"

class Menu : public Window {
private:
    //May add it so that the menu holds pointers to the function for each choice
    std::vector<std::string> choices;
    int selection;
public:
    Menu(color fill, point center, unsigned int width, unsigned int height);
    Menu(color fill, point center, unsigned int width, unsigned int height, std::vector<std::string> choices);

    void choiceUp();
    void choiceDown();
    std::string getChoice();

    void setChoices(std::vector<std::string> choices);

    void draw();
};


#endif