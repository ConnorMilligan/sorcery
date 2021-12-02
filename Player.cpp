#include "Player.h"


Player::Player() : Actor() {
    this->score = 0;
    this->location = {0,0};
    this->direction = NORTH;
    this->dungeon = Dungeon();
    this->inventory = {};
}

Player::Player(point location, Dungeon dungeon) : Actor() {
    this->score = 0;
    this->location = location;
    this->dungeon = dungeon;
    this->inventory = {};
}
Player::Player(point location, Dungeon dungeon, std::string name) : Actor() {
    this->score = 0;
    this->location = location;
    this->dungeon = dungeon;
    this->setName(name);
    this->inventory = {};
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

void Player::changeScore(int dc) {
    this->score += dc;
}

std::vector<std::string> Player::getInventoryString() {
    std::vector<std::string> itemString;
    for (Item item : this->inventory) {
        itemString.push_back(item.getName());
    }
    return itemString;
}

std::string Player::addItem(Item item) {
    if (this->inventory.size()+1 < MAX_ITEMS ) {
        this->inventory.push_back(item);
        return item.getName() + " was added to your inventory!";
    }
    
    return "You didn't have enough space to pick up the item!";
}

//There is almost certainly a better way of doing this
std::string Player::removeItem(int index) {
    std::vector<Item> newInventory;
    std::string itemName;

    for (int i = 0; i < this->inventory.size(); i++) {
        if (i != index) {
            newInventory.push_back(inventory[i]);
        }
        else {
            itemName = inventory[i].getName();
        }
    }

    this->inventory = newInventory;
    return itemName;
}

std::string Player::use(int index) {
    Item item = this->inventory[index];
    if (typeid(item).name() != "Potion") {
        this->changeHealth(15);
        this->removeItem(index);
        return "You quaff the " + item.getName() + ", healing you for 15 health!";
    }
    return "You interact with the " + item.getName() + "!";
}

int Player::nextLvlXp() {
    return (XP_FACTOR * this->getLevel()) + 1;
}

std::string Player::addXp(int xp) {
    this->xp += xp;
    return "You gained " + std::to_string(xp) + " xp!";
}

int Player::getXp() {
    return (this->nextLvlXp() - this->xp > 0) ? (this->nextLvlXp() - this->xp) : 0;
}

std::string Player::levelUp() {
    this->xp = this->xp;
    return Actor::levelUp();
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
    + "\n\n - Location -\nCords: (" + std::to_string(this->getLocation().x) + ',' + std::to_string(this->getLocation().y) + ')' + "  \nFacing: " + this->getDirectionString() + "\n(m) for Map";
}

std::string Player::playerInfoDetailed() {
    return "xp (" + std::to_string(this->xp) + ", " + std::to_string(this->nextLvlXp()) + ")\n"
            "xp to next level: " + std::to_string(this->nextLvlXp() - this->xp);
}