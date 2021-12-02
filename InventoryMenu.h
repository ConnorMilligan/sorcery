/*
* Inherits from the Menu,
* A navigable menu for the players items.
*/

#ifndef GRAPHICS_INVENTORYMENU_H
#define GRAPHICS_INVENTORYMENU_H

#include "Menu.h"
#include "Item.h"

class InventoryMenu : public Menu {
private:
    std::vector<Item> *itemChoices;
public:
    InventoryMenu(color fill, point center, unsigned int width, unsigned int height);
    InventoryMenu(color fill, point center, unsigned int width, unsigned int height, std::vector<Item> *itemChoices);
};


#endif