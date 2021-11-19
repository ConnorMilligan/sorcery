#include "CombatViewer.h"

CombatViewer::CombatViewer(color fill, point center, unsigned int width, unsigned int height) : Window(fill, center, width, height) {
}

CombatViewer::CombatViewer(color fill, point center, unsigned int width, unsigned int height, Player *player) : Window(fill, center, width, height) {
    this->player = player;
}

void CombatViewer::setMonster(Monster *monster) {
    this->monster = monster;
}

std::string CombatViewer::attack() {
    this->monster->changeHealth(-this->player->getStats().attack);
    return "You dealt " + std::to_string(this->player->getStats().attack) + " damage to the " + this->monster->getName() + "!\n" + this->monsterTurn();
}

std::string CombatViewer::monsterTurn() {
    this->player->changeHealth(-this->monster->getStats().attack);
    return "* The " + this->monster->getName() + " dealt " + std::to_string(this->player->getStats().attack) + " to you!";
}

void CombatViewer::draw() const {
    Window::draw();
    this->monster->setCoordinates(this->getCenter());
    monster->draw();
}