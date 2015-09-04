#include "Bird.h"
#include <iostream>
using namespace std;
Bird::Bird(){
	sprite = new sf::Sprite();
	texture = new sf::Texture();
	birdClock = new sf::Clock();
	textureRect = new sf::IntRect(0, 0, 92, 64);
	texture->loadFromFile("bird.png");
	sprite->setTexture(*texture, true);
	sprite->setTextureRect(*textureRect);
	sprite->setPosition(350-46,450-64);
}
sf::Sprite* Bird::getSprite(){
	return sprite;
}

void Bird::moveBird(){
	yVel += .00001;
	if (yVel >= .08){
		yVel = .08;
	}

	//cout << yVel << endl;
	this->sprite->move(0, this->yVel);
}

void Bird::mClick(){
	yVel -= .4;
	if (yVel <= -.04){
		yVel = -.04;
	}
}