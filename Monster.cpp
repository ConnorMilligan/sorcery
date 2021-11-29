#include "Monster.h"

#include <vector>
#include <cmath>
#include <time.h>

std::vector<std::string> randNames = {"The Fool","The Magician","The High Priestess","The Empress","The Emperor","The Hierophant","The Lovers","The Chariot","Strength ‡","The Hermit","Wheel of Fortune","Justice ‡","The Hanged Man","Death","Temperance","The Devil","The Tower","The Star","The Moon","The Sun","Judgement", "The World",};


Monster::Monster() : Actor() {

    srand(time(0));
    this->sprite = Sprite();
    this->coordinates = {0,0};

    int rn = rand() % randNames.size();
    this->setName(randNames[rn]);

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

void Monster::setCoordinates(point coords) {
    this->sprite.setCoords(coords);
}

Sprite Monster::getSprite() {
    return this->sprite;
}

void Monster::draw() {
    sprite.draw();
}