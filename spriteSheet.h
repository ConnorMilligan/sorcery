/*
* This is where all the sprites are stored in the game
*/

#ifndef GRAPHICS_SPRITESHEET_H
#define GRAPHICS_SPRITESHEET_H

#include "Sprite.h"

#include "sprites/menuLogo.h"

//Monster body sprites
#include "sprites/mBody_man.h"

spriteSheet testSprite = {
	"test sprite",
	15,
	10,
	"`Q!!`Q!!`Q!!`Q!!`Q!!`Q!!`Q!!`Q!!`Q!!`Q!!!&E!!&E!!&E!!&E!!&E!`Q!!"
	"`Q!!`Q!!`Q!!`Q!!`Q!!`Q!!`Q!!`Q!!`Q!!!&E!!&E!!&E!!&E!!&E!`Q!!`Q!!"
	"!!$``Q!!`Q!!`Q!!`Q!!!!$``Q!!`Q!!!&E!!&E!!&E!!&E!!&E!`Q!!`Q!!`Q!!"
	"`Q!!`Q!!`Q!!`Q!!`Q!!`Q!!`Q!!!&E!!&E!!&E!!&E!!&E!`Q!!`Q!!`Q!!`Q!!"
	"`Q!!`Q!!`Q!!`Q!!`Q!!`Q!!!&E!!&E!!&E!!&E!!&E!`Q!!!!$``Q!!`Q!!`Q!!"
	"`Q!!`Q!!`Q!!!!$``Q!!!&E!!&E!!&E!!&E!!&E!`Q!!`Q!!!!$`!!$`!!$`!!$`"
	"!!$`!!$``Q!!`Q!!!&E!!&E!!&E!!&E!!&E!`Q!!`Q!!`Q!!!!$`!!$`!!$`!!$`"
	"`Q!!`Q!!`Q!!!&E!!&E!!&E!!&E!!&E!`Q!!`Q!!`Q!!`Q!!`Q!!`Q!!`Q!!`Q!!"
	"`Q!!`Q!!!&E!!&E!!&E!!&E!!&E!`Q!!`Q!!`Q!!`Q!!`Q!!`Q!!`Q!!`Q!!`Q!!"
	"`Q!!!&E!!&E!!&E!!&E!!&E!"
};


//The main logo of the game displayed in the menu
spriteSheet menuLogo = {
	menuLogoName,
	menuLogoWidth,
	menuLogoHeight,
	menuLogoSprite
};

spriteSheet mBody_man = {
	mBody_manName,
	mBody_manWidth,
	mBody_manHeight,
	mBody_manSprite
};

#endif