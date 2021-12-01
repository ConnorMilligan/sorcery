/*
* Sprite loader and storage
*/

#ifndef GRAPHICS_SPRITESHEET_H
#define GRAPHICS_SPRITESHEET_H

#include <string>
#include <vector>
#include "Sprite.h"


class SpriteSheet {
private:
	std::vector<spriteSheet> monsterHeads;
	std::vector<spriteSheet> monsterBodies;
	Sprite gameLogo;
public:
	SpriteSheet();

	std::vector<spriteSheet> getMonsterHeads();
	std::vector<spriteSheet> getMonsterBodies();
	Sprite getGameLogo();
};


#endif