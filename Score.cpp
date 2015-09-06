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
	score->setString("0123456789");
	score->setCharacterSize(30);
	score->setPosition(300,300);
	score->setColor(sf::Color::White);
}

void Score::drawScore(sf::RenderWindow* wnd){
	/*for (auto itor = score->begin(); itor != score->end(); itor++){
		wnd->draw(*itor);
	}
	*/
}

sf::Text* Score::getScore(){
	return score;
}