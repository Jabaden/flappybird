#include "Bird.h"
#include <iostream>
using namespace std;
Bird::Bird(){
	sprite = new sf::Sprite();
	texture = new sf::Texture();
	birdClock = new sf::Clock();
	textureRect = new sf::IntRect(0, 0, 92, 64);
	texture->loadFromFile("bird.png");
	sprite->setTexture(*texture);
	sprite->setTextureRect(*textureRect);
	sprite->setPosition(325,386);
	this->sprite->setScale(.70f, .70f);
	this->sprite->setOrigin(50, 50);
}
sf::Sprite* Bird::getSprite(){
	return sprite;
}

void Bird::hover(){
	//cout << hoverYVel << endl;
	if (this->isGoingDown){
		hoverYVel += .00001;
		if (hoverYVel > .02){
			//cout << "going down is now false" << endl;
			isGoingDown = false;
		}
	}
	else{
		//cout << "no" << endl;
		hoverYVel -= .00001;
		if (hoverYVel < -.02){
			isGoingDown = true;
		}
	}
	this->sprite->move(0, this->hoverYVel);
}

void Bird::moveBird(Background* floorOne, Background* floorTwo){
	yVel += .00002;

	if ((this->sprite->getGlobalBounds().intersects(floorOne->getSprite()->getGlobalBounds())) ||
		(this->sprite->getGlobalBounds().intersects(floorTwo->getSprite()->getGlobalBounds()))){
		return;
	}
	if (yVel >= .05){
		//cout << this->sprite->getRotation() << endl;
		if (this->sprite->getRotation()  > 300.f || this->sprite->getRotation() <= 90.f){
			//cout << "rotating" << endl;
			this->sprite->rotate(0.025f);
		}
	}
	if (yVel >= .08){
		yVel = .08;
	}

	//cout << yVel << endl;

	this->sprite->move(0, this->yVel);
}

void Bird::mClick(){
	this->sprite->setRotation(330.f);
	//this->sprite->rotate(-30.f);
	yVel -= .5;
	if (yVel <= -.06){
		yVel = -.06;
	}
}



void Bird::flap(){
	if (this->birdClock->getElapsedTime().asMilliseconds() > aniSpeed){
		this->birdClock->restart();
		this->textureRect->left = 0 + (92 * (this->aniFrame));
		this->sprite->setTextureRect(*(this->textureRect));
		(this->aniFrame)++;
		if (aniFrame == 3){
			aniFrame = 0;
		}
	}
}

bool Bird::hasCollided(Pipe* pipeOne, Pipe* pipeTwo, Background* floorOne, Background* floorTwo){
	if ((this->sprite->getGlobalBounds().intersects(pipeOne->getTopSprite()->getGlobalBounds())) ||
		(this->sprite->getGlobalBounds().intersects(pipeOne->getBotSprite()->getGlobalBounds())) ||
		(this->sprite->getGlobalBounds().intersects(pipeTwo->getTopSprite()->getGlobalBounds())) ||
		(this->sprite->getGlobalBounds().intersects(pipeTwo->getBotSprite()->getGlobalBounds())) ||
		(this->sprite->getGlobalBounds().intersects(floorOne->getSprite()->getGlobalBounds()))	 ||
		(this->sprite->getGlobalBounds().intersects(floorTwo->getSprite()->getGlobalBounds()))){
		return true;
	}
	else{
		return false;
	}
}

void Bird::resetGame(Pipe* pipeOne, Pipe* pipeTwo){
	//int topX, int topY, int botX, int botY
	/*Pipe* firstPipes = new Pipe(1100, -150 - 0, 1100, 675 - 0); //difference is about ~825
	Pipe* secondPipes = new Pipe(1600, -150 - 50, 1600, 675 - 50);*/

	this->sprite->setRotation(0.f);
	this->sprite->setPosition(325, 386);


	pipeOne->getTopSprite()->setPosition(1100, -150);
	pipeOne->getBotSprite()->setPosition(1100, 675);
	pipeOne->resetAC();

	pipeTwo->getTopSprite()->setPosition(1600, -200);
	pipeTwo->getBotSprite()->setPosition(1600, 625);

	this->hasStarted = false;
	this->isAlive = true;

	




}