#include "Monster.h"

Monster::Monster() : Actor() {
    this->sprite = Sprite();
    this->coordinates = {0,0};
}

Monster::Monster(int level) : Actor(level) {
    this->sprite = Sprite();
    this->coordinates = {0,0};
}

Monster::Monster(Sprite sprite) {
    this->sprite = Sprite();
    this->coordinates = {0,0};
}

Monster::Monster(Sprite sprite, int level) : Actor(level) {
    this->sprite = sprite;
    this->coordinates = {0,0};
}

void Monster::setCoordinates(point coordinates) {
    this->coordinates = coordinates;
}

Sprite Monster::getSprite() {
    return this->sprite;
}

void Monster::draw() {
    sprite.draw();
}