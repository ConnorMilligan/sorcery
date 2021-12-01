#include "Player.h"


Player::Player() : Actor() {
    this->score = 0;
    this->location = {0,0};
    this->direction = NORTH;
    this->dungeon = Dungeon();
}

Player::Player(point location, Dungeon dungeon) : Actor() {
    this->score = 0;
    this->location = location;
    this->dungeon = dungeon;
}
Player::Player(point location, Dungeon dungeon, std::string name) : Actor() {
    this->score = 0;
    this->location = location;
    this->dungeon = dungeon;
    this->setName(name);

}

bool Player::move(int x, int y) {
    if (!(this->dungeon.getTile(this->location.x+x, this->location.y+y))) {
        this->location.x += x;
        this->location.y += y;
        return true;
    }
    return false;
    
}

point Player::getLocation() {
    return this->location;
}

Dungeon Player::getDungeon() {
    return this->dungeon;
}

Direction Player::getDirection() {
    return this->direction;
}
int Player::getScore() {
    return this->score;
}

std::string Player::getDirectionString() {
    switch (this->direction) {
        case NORTH:
            return "NORTH";
        case EAST:
            return "EAST";
        case SOUTH:
            return "SOUTH";
        case WEST:
            return "WEST";

        default:
            return "";
    }
}

void Player::turnRight() {
    switch (this->direction) {
        case NORTH:
            this->direction = EAST;
            break;
        case EAST:
            this->direction = SOUTH;
            break;
        case SOUTH:
            this->direction = WEST;
            break;
        case WEST:
            this->direction = NORTH;
            break;
        
        default:
            break;
    }
}

void Player::turnLeft() {
    switch (this->direction) {
        case NORTH:
            this->direction = WEST;
            break;
        case EAST:
            this->direction = NORTH;
            break;
        case SOUTH:
            this->direction = EAST;
            break;
        case WEST:
            this->direction = SOUTH;
            break;
        
        default:
            break;
    }
}

bool Player::advance() {
    switch (this->direction) {
        case NORTH:
            return this->move(0, -1);
            break;
        case EAST:
            return this->move(1, 0);
            break;
        case SOUTH:
            return this->move(0, 1);
            break;
        case WEST:
            return this->move(-1, 0);
            break;
        
        default:
        return false;
            break;
    }
}

void Player::retreat() {
    switch (this->direction) {
        case NORTH:
            this->move(0, 1);
            break;
        case EAST:
            this->move(-1, 0);
            break;
        case SOUTH:
            this->move(0, -1);
            break;
        case WEST:
            this->move(1, 0);
            break;
        
        default:
            break;
    }
}

std::string Player::playerInfo() {
    return "Name: " + this->getName() + "\nLevel: " + std::to_string(this->getLevel()) + "\nScore: " + std::to_string(this->getScore()) + "\nHealth: " + std::to_string(this->getHealth().current) + '/' + std::to_string(this->getHealth().max) +
    "\n\n - Stats - \nAttack: " + std::to_string(this->getStats().attack) + "\nDefense: " + std::to_string(this->getStats().defense) + "\nSpeed: " + std::to_string(this->getStats().speed) + "\nLuck: " + std::to_string(this->getStats().luck)
    + "\n\n - Location -\nCords: (" + std::to_string(this->getLocation().x) + ',' + std::to_string(this->getLocation().y) + ')' + "  \nFacing: " + this->getDirectionString();
}