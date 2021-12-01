#include "SpriteSheet.h"

#include "sprites/menuLogo.h"

//Monster body sprites
#include "sprites/mBody_man.h"

SpriteSheet::SpriteSheet() {
	this->gameLogo = Sprite({
		menuLogoName,
		menuLogoWidth,
		menuLogoHeight,
		menuLogoSprite
	}, {50,100});

	this->monsterHeads.push_back({
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
	});

	this->monsterBodies.push_back({
		mBody_manName,
		mBody_manWidth,
		mBody_manHeight,
		mBody_manSprite
	});
}

std::vector<spriteSheet> SpriteSheet::getMonsterHeads() {
	return this->monsterHeads;
}

std::vector<spriteSheet> SpriteSheet::getMonsterBodies() {
	return this->monsterBodies;
}

Sprite SpriteSheet::getGameLogo() {
	return this->gameLogo;
}