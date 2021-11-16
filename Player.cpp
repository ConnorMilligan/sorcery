#include "Player.h"

Player::Player() : Actor() {
    this->location = {0,0};
    this->direction = NORTH;
    this->dungeon = Dungeon();
}

Player::Player(point location, Dungeon dungeon) : Actor() {
    this->location = location;
    this->dungeon = dungeon;
}

void Player::move(int x, int y) {
    if (!(this->dungeon.getTile(this->location.x+x, this->location.y+y))) {
        this->location.x += x;
        this->location.y += y;
    }
    
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

void Player::advance() {
    switch (this->direction) {
        case NORTH:
            this->move(0, -1);
            break;
        case EAST:
            this->move(1, 0);
            break;
        case SOUTH:
            this->move(0, 1);
            break;
        case WEST:
            this->move(-1, 0);
            break;
        
        default:
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
    return "Name: " + this->getName() + "\nLevel: " + std::to_string(this->getLevel()) + "\nHealth: " + std::to_string(this->getHealth().current) + '/' + std::to_string(this->getHealth().max) +
    "\n\n - Stats - \nAttack: " + std::to_string(this->getStats().attack) + "\nDefense: " + std::to_string(this->getStats().defense) + "\nSpeed: " + std::to_string(this->getStats().speed) + "\nLuck: " + std::to_string(this->getStats().luck)
    + "\n\n - Location -\nCords: (" + std::to_string(this->getLocation().x) + ',' + std::to_string(this->getLocation().y) + ')' + "  \nFacing: " + this->getDirectionString();
}