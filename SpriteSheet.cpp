#include "SpriteSheet.h"

#include "sprites/menuLogo.h"

//Monster head sprites
#include "sprites/mHead_hawk.h"
#include "sprites/mHead_cat.h"
#include "sprites/mHead_froggy.h"
#include "sprites/mHead_brain.h"
#include "sprites/mHead_cyclops.h"
#include "sprites/mHead_fish.h"
#include "sprites/mHead_house.h"
#include "sprites/mHead_man.h"
#include "sprites/mHead_squid.h"
#include "sprites/mHead_toucan.h"

//Monster body sprites
#include "sprites/mBody_weightLifter.h"
#include "sprites/mBody_octopus.h"
#include "sprites/mBody_clown.h"

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

	this->monsterHeads.push_back({
		mHead_froggyName,
		mHead_froggyWidth,
		mHead_froggyHeight,
		mHead_froggySprite
	});

	this->monsterHeads.push_back({
		mHead_brainName,
		mHead_brainWidth,
		mHead_brainHeight,
		mHead_brainSprite
	});

	this->monsterHeads.push_back({
		mHead_cyclopsName,
		mHead_cyclopsWidth,
		mHead_cyclopsHeight,
		mHead_cyclopsSprite
	});

	this->monsterHeads.push_back({
		mHead_fishName,
		mHead_fishWidth,
		mHead_fishHeight,
		mHead_fishSprite
	});

	this->monsterHeads.push_back({
		mHead_houseName,
		mHead_houseWidth,
		mHead_houseHeight,
		mHead_houseSprite
	});

	this->monsterHeads.push_back({
		mHead_manName,
		mHead_manWidth,
		mHead_manHeight,
		mHead_manSprite
	});

	this->monsterHeads.push_back({
		mHead_squidName,
		mHead_squidWidth,
		mHead_squidHeight,
		mHead_squidSprite
	});

	this->monsterHeads.push_back({
		mHead_toucanName,
		mHead_toucanWidth,
		mHead_toucanHeight,
		mHead_toucanSprite
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

	this->monsterBodies.push_back({
		mBody_clownName,
		mBody_clownWidth,
		mBody_clownHeight,
		mBody_clownSprite
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