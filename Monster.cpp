#include "Monster.h"

#include <vector>
#include <cmath>
#include <time.h>


//std::vector<std::string> randNames = {"The Fool","The Magician","The High Priestess","The Empress","The Emperor","The Hierophant","The Lovers","The Chariot","Strength ‡","The Hermit","Wheel of Fortune","Justice ‡","The Hanged Man","Death","Temperance","The Devil","The Tower","The Star","The Moon","The Sun","Judgement", "The World",};


void Monster::determineMonster() {
    SpriteSheet loadSprites;

    srand(time(0));
    spriteSheet head = loadSprites.getMonsterHeads()[rand() % loadSprites.getMonsterHeads().size()];
    spriteSheet body = loadSprites.getMonsterBodies()[rand() % loadSprites.getMonsterBodies().size()];

    this->sprites.head = Sprite(head);
    this->sprites.body = Sprite(body);

    this->setName(body.name + " " + head.name);
}

Monster::Monster() : Actor() {
    determineMonster();
    this->coordinates = {0,0};
    this->sprites.head.setCoords({coordinates.x, coordinates.y});
    this->sprites.body.setCoords({coordinates.x, coordinates.y+16});

    //int rn = rand() % randNames.size();
    //this->setName(randNames[rn]);

}

Monster::Monster(int level) : Actor(level) {
    determineMonster();
    this->coordinates = {0,0};
    this->sprites.head.setCoords(coordinates);
    this->sprites.body.setCoords({coordinates.x, coordinates.y+32});
}

void Monster::setCoordinates(point coords) {
    this->sprites.head.setCoords(coords);
    this->sprites.body.setCoords({coords.x, coords.y+32});
}

monstSprites Monster::getSprites() {
    return this->sprites;
}

void Monster::draw() {
    sprites.body.draw();
    sprites.head.draw();
}