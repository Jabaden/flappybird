#include "Menu.h"

Menu::Menu(int type){
	sprite = new sf::Sprite();
	texture = new sf::Texture();
	texture->loadFromFile("fbirdsprites.png");
	sprite->setTexture(*texture);
	if (type == 1){ // "tutorial"
		textureRect = new sf::IntRect(291, 80, 59, 61);
		sprite->scale(2.f, 2.f);
	}
	sprite->setTextureRect(*textureRect);
	sprite->setPosition(275, 200);
	//textureRect = new sf::IntRect(0, 258, 115, 57); this is the score screen
}

sf::Sprite* Menu::getSprite(){
	return sprite;
}
