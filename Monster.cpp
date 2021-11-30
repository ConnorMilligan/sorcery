#include "Monster.h"

#include <vector>
#include <cmath>
#include <time.h>

//std::vector<std::string> randNames = {"The Fool","The Magician","The High Priestess","The Empress","The Emperor","The Hierophant","The Lovers","The Chariot","Strength ‡","The Hermit","Wheel of Fortune","Justice ‡","The Hanged Man","Death","Temperance","The Devil","The Tower","The Star","The Moon","The Sun","Judgement", "The World",};


void Monster::determineMonster() {
    this->sprites.head = Sprite();
    this->sprites.body = Sprite();
}

Monster::Monster() : Actor() {

    srand(time(0));
    this->sprites.body = Sprite();
    this->coordinates = {0,0};

    //int rn = rand() % randNames.size();
    //this->setName(randNames[rn]);

}

Monster::Monster(int level) : Actor(level) {
    this->sprites.body = Sprite();
    this->coordinates = {0,0};
}

void Monster::setCoordinates(point coords) {
    this->sprites.body.setCoords(coords);
}

monstSprites Monster::getSprites() {
    return this->sprites;
}

void Monster::draw() {
    sprites.head.draw();
    sprites.body.draw();
}