#include "CombatViewer.h"

CombatViewer::CombatViewer(color fill, point center, unsigned int width, unsigned int height) : Window(fill, center, width, height) {
}

CombatViewer::CombatViewer(color fill, point center, unsigned int width, unsigned int height, Player *player) : Window(fill, center, width, height) {
    this->player = player;
    this->active = true;
}

void CombatViewer::setMonster(Monster *newMonster) {
    this->monster = newMonster;
}

std::string CombatViewer::attack() {
    this->monster->changeHealth(-this->player->getStats().attack);
    return "You dealt " + std::to_string(this->player->getStats().attack) + " damage to the " + this->monster->getName() + "!\n" + this->monsterTurn();
}

std::string CombatViewer::playerTurn(std::string action) {

    std::string result = "";

    if(action == "Attack") {
        this->monster->changeHealth(this->player->getStats().attack);
        result = "You dealt " + std::to_string(this->player->getStats().attack) + " damage to the " + this->monster->getName() + "!\n" + this->monsterTurn();
    } else if(action == "Defend") {

        unsigned int defense = this->player->getStats().defense;
        this->player->changeHealth(this->monster->getStats().attack-defense);
        result = "You defend, taking 0 points of damage";

    } else {
        result = "You abscond, taking 1 point of damage";
        this->player->changeHealth(-1);
        active = false;
        return result;
    }

    // Ensure combat is active by both players having health
    active = this->player->getHealth().current > 0 && this->monster->getHealth().current > 0;

    return result;
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
bool CombatViewer::isActive() {
    return active;
}