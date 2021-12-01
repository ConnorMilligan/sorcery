#include "SpriteSheet.h"

#include "sprites/menuLogo.h"

//Monster head sprites
#include "sprites/mHead_hawk.h"
#include "sprites/mHead_cat.h"

//Monster body sprites
#include "sprites/mBody_weightLifter.h"
#include "sprites/mBody_octopus.h"

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

	this->monsterHeads.push_back({
		mHead_catName,
		mHead_catWidth,
		mHead_catHeight,
		mHead_catSprite
	});

	//Adding in the monsterBodies
	this->monsterBodies.push_back({
		mBody_weightLifterName,
		mBody_weightLifterWidth,
		mBody_weightLifterHeight,
		mBody_weightLifterSprite
	});

	this->monsterBodies.push_back({
		mBody_octopusName,
		mBody_octopusWidth,
		mBody_octopusHeight,
		mBody_octopusSprite
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