#include "Item.h"

Item::Item() {
    this->name = "";
}

Item::Item(std::string name) {
    this->name = name;
}

std::string Item::getName() {
    return this->name;
}