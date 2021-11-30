#include "spriteSheet.h"

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