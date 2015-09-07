#include "Gameover.h"
#include <iostream>
using namespace std;

Gameover::Gameover(int type){
	sprite = new sf::Sprite();
	texture = new sf::Texture();
	texture->loadFromFile("fbirdsprites.png");
	sprite->setTexture(*texture);
	if (type == 1){
		textureRect = new sf::IntRect(0, 259, 117, 58);
		sprite->scale(2.f, 2.f);
		sprite->setPosition(240, 300);
	}
	else{
		textureRect = new sf::IntRect(110, 477, 25, 22);
		sprite->scale(2.f, 2.f);
		sprite->setPosition(268, 343);
	}
	sprite->setTextureRect(*textureRect);
}

sf::Sprite* Gameover::getSprite(){
	return sprite;
}

void Gameover::determineMedal(int finalScore){
	cout << finalScore << endl;
	//cout << "in determineMedal" << endl;
	if (finalScore >= 25){ //gold
		textureRect->left = 119;
		textureRect->top = 281;
	}
	else if (finalScore >= 10){ //silver
		textureRect->left = 109;
		textureRect->top = 453;
	}
	else{ //bronze
		//cout << "in bronze" << endl;
		textureRect->left = 110;
		textureRect->top = 477;
	}
	sprite->setTexture(*texture);
	this->sprite->setTextureRect(*textureRect);
}