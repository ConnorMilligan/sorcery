/*
* Inherits from the Window,
* A navigable menu in a quad.
*/

#ifndef GRAPHICS_MENU_H
#define GRAPHICS_MENU_H

#include "Window.h"

class Menu : public Window {
private:
    std::vector<std::string> choices;
    int selection;
public:
    Menu(color fill, point center, unsigned int width, unsigned int height);

};


#endif