#include "Pipe.h"
#include <iostream>
//spreadsheet is 512x512
#define GAMEWIDTH 700
#define GAMEHEIGHT 900
Pipe::Pipe(int topX, int topY, int botX, int botY){
	topSprite = new sf::Sprite();
	botSprite = new sf::Sprite();
	texture = new sf::Texture();
	texture->loadFromFile("fbirdsprites.png");
	topRect = new sf::IntRect(57, 323, 25, 158);
	botRect = new sf::IntRect(84, 324, 25, 158);
	topSprite->setTexture(*texture);
	botSprite->setTexture(*texture);
	topSprite->setTextureRect(*topRect);
	botSprite->setTextureRect(*botRect);
	topSprite->setPosition(topX, topY); //600, -150
	botSprite->setPosition(botX, botY); //600, 550
	topSprite->scale(pXScale, pYScale);
	botSprite->scale(pXScale, pYScale);
}

int Pipe::getArrayCounter(){
	return this->arrayCounter;
}

void Pipe::incrementAC(){
	arrayCounter++;
}

void Pipe::resetAC(){
	arrayCounter = 0;
}

void Pipe::drawPipes(sf::RenderWindow* wnd){
	wnd->draw(*topSprite);
	wnd->draw(*botSprite);
}

void Pipe::movePipes(char sNumber){
	int buffer = 250;
	topSprite->move(-0.02, 0);
	botSprite->move(-0.02, 0);
	if (this->botSprite->getPosition().x <= -(this->botSprite->getGlobalBounds().width)){
		this->botSprite->setPosition(GAMEWIDTH + buffer, this->botSprite->getPosition().y);
		this->topSprite->setPosition(GAMEWIDTH + buffer, this->topSprite->getPosition().y);
		this->setPipePosition(sNumber);
	}
}

void Pipe::setPipePosition(char sNumber){
	if (sNumber == '0'){
		this->topSprite->setPosition(this->topSprite->getPosition().x, -150 - 450);
		this->botSprite->setPosition(this->botSprite->getPosition().x, 675 - 450);
	}
	else if (sNumber == '1'){
		this->topSprite->setPosition(this->topSprite->getPosition().x, -150 - 400);
		this->botSprite->setPosition(this->botSprite->getPosition().x, 675 - 400);
	}
	else if (sNumber == '2'){
		this->topSprite->setPosition(this->topSprite->getPosition().x, -150 - 350);
		this->botSprite->setPosition(this->botSprite->getPosition().x, 675 - 350);
	}
	else if (sNumber == '3'){
		this->topSprite->setPosition(this->topSprite->getPosition().x, -150 - 300);
		this->botSprite->setPosition(this->botSprite->getPosition().x, 675 - 300);
	}
	else if (sNumber == '4'){
		this->topSprite->setPosition(this->topSprite->getPosition().x, -150 - 250);
		this->botSprite->setPosition(this->botSprite->getPosition().x, 675 - 250);
	}
	else if (sNumber == '5'){
		this->topSprite->setPosition(this->topSprite->getPosition().x, -150 - 200);
		this->botSprite->setPosition(this->botSprite->getPosition().x, 675 - 200);
	}
	else if (sNumber == '6'){
		this->topSprite->setPosition(this->topSprite->getPosition().x, -150 - 150);
		this->botSprite->setPosition(this->botSprite->getPosition().x, 675 - 150);
	}
	else if (sNumber == '7'){
		this->topSprite->setPosition(this->topSprite->getPosition().x, -150 - 100);
		this->botSprite->setPosition(this->botSprite->getPosition().x, 675 - 100);
	}
	else if (sNumber == '8'){
		this->topSprite->setPosition(this->topSprite->getPosition().x, -150 - 50);
		this->botSprite->setPosition(this->botSprite->getPosition().x, 675 - 50);
	}
	else{
		this->topSprite->setPosition(this->topSprite->getPosition().x, -150);
		this->botSprite->setPosition(this->botSprite->getPosition().x, 675);
	}
	this->incrementAC();
}
//600, -150 - 400, 600, 675 - 400;# 1
//600, -150 - 450, 600, 675 - 450 # 0
//600, -150 - 350, 600, 675 - 350 # 2
//600, -150 - 300, 600, 675 - 300 # 3
//1100, -150 - 250, 1100, 675 - 250 # 4
// 600, -150 - 200, 600, 675 - 200 # 5
//1100, -150 - 150, 1100, 675 - 150 # 6
//600, -150 - 100, 600, 675 - 100 # 7
//1100, -150 - 50, 1100, 675 - 50 # 8
//600, -150 - 0, 600, 675 - 0 # 9