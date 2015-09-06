#include "Background.h"

Background::Background(int type){
	sprite = new sf::Sprite();
	texture = new sf::Texture();
	texture->loadFromFile("fbirdsprites.png");
	sprite->setTexture(*texture);
	if (type == 0){ //floor
		textureRect = new sf::IntRect(292, 0, 167, 55);
		if (spriteCounter == 1){
			this->sprite->setPosition(0, 775);
		}
		else{
			this->sprite->setPosition(700, 775);
		}
		spriteCounter++;
		this->sprite->scale(4.25f, 2.8f);
	}
	else if (type == 1){ // background
		textureRect = new sf::IntRect(146, 0, 143, 255);
		this->sprite->scale(5.0f, 3.55f);
	}

	sprite->setTextureRect(*textureRect);
}

sf::Sprite* Background::getSprite(){
	return this->sprite;
}

void Background::moveFloor(){
	this->sprite->move(-0.02, 0);

	if (this->sprite->getPosition().x <= -700){
	this->sprite->setPosition(700, 775);
	}
}