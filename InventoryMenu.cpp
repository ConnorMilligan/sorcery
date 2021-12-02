#include "InventoryMenu.h"

InventoryMenu::InventoryMenu(color fill, point center, unsigned int width, unsigned int height) : Menu(fill, center, width, height) {

}

InventoryMenu::InventoryMenu(color fill, point center, unsigned int width, unsigned int height, std::vector<Item> *itemChoices) : Menu(fill, center, width, height) {
    this->itemChoices = itemChoices;
}