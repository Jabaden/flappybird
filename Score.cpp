#include "Score.h"
using namespace std;

Score::Score(){
	/*score = new sVector();
	//(auto itor = pdl->begin(); itor != pdl->end(); itor++)
	sf::Sprite* tempSprite = new sf::Sprite();
	texture = new sf::Texture();
	texture->loadFromFile("fbirdsprites.png");
	tempSprite->setTexture(*texture);
	textureRect = new sf::IntRect(496, 60, 11, 17);
	tempSprite->setTextureRect(*textureRect);
	tempSprite->setPosition(200, 200);
	
	score->push_back(*tempSprite);
	*/
	flappyFont = new sf::Font();
	flappyFont->loadFromFile("fbirdfont.TTF");
	score = new sf::Text();
	score->setFont(*flappyFont);
	score->setString("0");
	score->setCharacterSize(50);
	score->setPosition(350,100);
	score->setColor(sf::Color::White);
}

void Score::setScoreText(string newScore){
	score->setString(newScore);
}

void Score::drawScore(sf::RenderWindow* wnd){
	/*for (auto itor = score->begin(); itor != score->end(); itor++){
		wnd->draw(*itor);
	}
	*/
}

void Score::alignToScoreBoard(bool isTop){
	this->score->scale(.5f, .5f);
	if (isTop){
		this->score->setPosition(438, 330);
	}
	else{
		this->score->setPosition(438, 370);
	}
}

sf::Text* Score::getScore(){
	return score;
}
