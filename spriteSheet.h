#ifndef GRAPHICS_SPRITESHEET_H
#define GRAPHICS_SPRITESHEET_H

#include "sprites/menuLogo.h"

struct spriteSheet {
	int width;
	int height;
	char const *sprite;
};

spriteSheet testSprite = {
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

spriteSheet menuLogo = {
	menuLogoWidth,
	menuLogoHeight,
	menuLogoSprite
};

#endif