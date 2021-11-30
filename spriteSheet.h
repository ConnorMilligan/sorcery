/*
* This is where all the sprites are stored in the game
*/

#ifndef GRAPHICS_SPRITESHEET_H
#define GRAPHICS_SPRITESHEET_H

#include <string>

struct spriteSheet {
    std::string name;
	int width;
	int height;
	char const *sprite;
};

extern spriteSheet testSprite;


//The main logo of the game displayed in the menu
extern spriteSheet menuLogo;

extern spriteSheet mBody_man;

#endif