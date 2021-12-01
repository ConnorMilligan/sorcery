#include "Monster.h"

#include <vector>
#include <cmath>
#include <time.h>


//std::vector<std::string> randNames = {"The Fool","The Magician","The High Priestess","The Empress","The Emperor","The Hierophant","The Lovers","The Chariot","Strength ‡","The Hermit","Wheel of Fortune","Justice ‡","The Hanged Man","Death","Temperance","The Devil","The Tower","The Star","The Moon","The Sun","Judgement", "The World",};


void Monster::determineMonster() {
    SpriteSheet loadSprites;

    spriteSheet head = loadSprites.getMonsterHeads()[0];
    spriteSheet body = loadSprites.getMonsterBodies()[0];

    this->sprites.head = Sprite(head);
    this->sprites.body = Sprite(body);

    this->setName(body.name + " " + head.name);
}

Monster::Monster() : Actor() {

    srand(time(0));
    determineMonster();
    this->coordinates = {0,0};

    //int rn = rand() % randNames.size();
    //this->setName(randNames[rn]);

}

Monster::Monster(int level) : Actor(level) {
    determineMonster();
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