#include "SpriteSheet.h"

#include "sprites/menuLogo.h"

//Monster head sprites
#include "sprites/mHead_hawk.h"

//Monster body sprites
#include "sprites/mBody_weightLifter.h"

SpriteSheet::SpriteSheet() {
	this->gameLogo = Sprite({
		menuLogoName,
		menuLogoWidth,
		menuLogoHeight,
		menuLogoSprite
	}, {50,100});

	//Adding in the monster heads
	this->monsterHeads.push_back({
		mHead_hawkName,
		mHead_hawkWidth,
		mHead_hawkHeight,
		mHead_hawkSprite
	});

	//Adding in the monsterBodies
	this->monsterBodies.push_back({
		mBody_weightLifterName,
		mBody_weightLifterWidth,
		mBody_weightLifterHeight,
		mBody_weightLifterSprite
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