#include "CombatViewer.h"

CombatViewer::CombatViewer(color fill, point center, unsigned int width, unsigned int height) : Window(fill, center, width, height) {
}

CombatViewer::CombatViewer(color fill, point center, unsigned int width, unsigned int height, Player *player) : Window(fill, center, width, height) {
    this->player = player;
}

void CombatViewer::setMonster(Monster *monster) {
    this->monster = monster;
}

void CombatViewer::draw() const {
    Window::draw();
    this->monster->setCoordinates(this->getCenter());
    monster->draw();
}