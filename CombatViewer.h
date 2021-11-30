/*
* Inherits from the Window,
* For showing monsters during combat
*/

#ifndef GRAPHICS_COMBATVIEWER_H
#define GRAPHICS_COMBATVIEWER_H

#include "Window.h"
#include "Player.h"
#include "Monster.h"

class CombatViewer : public Window {
private:
    Player* player;
    Monster* monster;
    bool active;
public:
    CombatViewer(color fill, point center, unsigned int width, unsigned int height);
    CombatViewer(color fill, point center, unsigned int width, unsigned int height, Player *player);

    void setMonster(Monster *monster);


    std::string attack();
    std::string playerTurn(std::string action);

    std::string monsterTurn();

    bool isActive();

    void draw() const;
};

#endif