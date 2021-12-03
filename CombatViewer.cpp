#include "CombatViewer.h"

CombatViewer::CombatViewer(color fill, point center, unsigned int width, unsigned int height) : Window(fill, center, width, height) {
}

CombatViewer::CombatViewer(color fill, point center, unsigned int width, unsigned int height, Player *player) : Window(fill, center, width, height) {
    this->player = player;
    this->active = false;
}

void CombatViewer::setMonster(Monster *newMonster) {
    this->monster = newMonster;
}

std::string CombatViewer::playerTurn(std::string action) {

    std::string result = "";

    if(action == "Attack") {

        float range = this->player->getStats().attack;

        // As luck increases, so do the odds of a # [0,10] falling between [0,luck];
        int modifier = (rand() % 10) <= this->player->getStats().luck ? 2 : 1;

        result = modifier > 1 ? "Critical hit! " : "";

        // Damage range is [attack/2, (3/2)*attack] * modifier
        int damage = (ceil(rand() % (int)ceil(range))+range/2)*modifier;

        this->monster->changeHealth(-damage);

        result += "You dealt " + std::to_string(damage) + " damage to the " + this->monster->getName() + "!\n" + this->monsterTurn();

    } else if(action == "Defend") {

        unsigned int defense = this->player->getStats().defense;
        this->player->changeHealth(this->monster->getStats().attack-defense);
        result = "You defend, taking 0 points of damage";

    } else {
        result = "You abscond, taking ";
        result += std::to_string(this->player->getLevel());
        result += this->player->getLevel() > 1 ? " points " : " point ";
        result += "of damage";

        this->player->changeHealth(this->player->getLevel());
        this->toggleState();
        return result;
    }

    // Ensure combat is active by both players having health
    active = this->player->getHealth().current > 0 && this->monster->getHealth().current > 0;

    return result;
}

std::string CombatViewer::monsterTurn() {
    int damage = this->monster->getStats().attack-(this->player->getStats().defense/2);
    if(damage < 0) damage = 0;
    this->player->changeHealth(-damage);
    return "* The " + this->monster->getName() + " dealt " + std::to_string(damage) + " to you!";
}

bool CombatViewer::isActive() {
    return active;
}

void CombatViewer::toggleState() {
    this->active = !active;
}

void CombatViewer::draw() const {
    Window::draw();
    this->monster->setCoordinates({this->getCenter().x-32, this->getCenter().y-80});
    monster->draw();
}