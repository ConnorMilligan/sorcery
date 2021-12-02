/*
* Item
*/
#ifndef GRAPHICS_ITEM_H
#define GRAPHICS_ITEM_H

#include <string>

class Item {
private:
    std::string name;
public:
    Item();
    Item(std::string name);

    std::string getName();
};

#endif