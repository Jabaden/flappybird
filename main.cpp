#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Bird.h"
#include "Pipe.h"

//testing git
using namespace std;

int Pipe::arrayCounter; //static variable for pipes

int main()
{
	sf::RenderWindow window(sf::VideoMode(700, 900), "SFML works!");
	string randomString = ""; //string used to make the program "random" but not really =D
	for (int i = 0607; i < 10620; i+= 1001){
		srand(i);
		int tempRandom = rand();
		string tempString = to_string(tempRandom);
		randomString += tempString;
	}
	cout << randomString << endl;
	cout << randomString[0] << endl;
	cout << randomString[1] << endl;
	cout << randomString.length() << endl;
	char test = randomString[0];
	cout << "test is: " << test << endl;
	

	//-----------Background sprites-------

	sf::Sprite* backgroundSprite = new sf::Sprite();
	sf::Texture* backgroundTexture = new sf::Texture();
	backgroundTexture->loadFromFile("fbirdsprites.png");
	sf::IntRect* backgroundRect = new sf::IntRect(146, 0, 143, 255);
	backgroundSprite->setTexture(*backgroundTexture);
	backgroundSprite->setTextureRect(*backgroundRect);
	backgroundSprite->scale(5.0f, 3.55f);

	sf::Sprite* groundSprite = new sf::Sprite();
	sf::IntRect* groundRect = new sf::IntRect(292, 0, 167, 55); 
	groundSprite->setTexture(*backgroundTexture);
	groundSprite->setTextureRect(*groundRect);
	groundSprite->setPosition(0, 775);
	groundSprite->scale(4.25f, 2.8f);

	sf::Sprite* groundSpriteTwo = new sf::Sprite();
	groundSpriteTwo->setTexture(*backgroundTexture);
	groundSpriteTwo->setTextureRect(*groundRect);
	groundSpriteTwo->setPosition(700, 775);
	groundSpriteTwo->scale(4.25f, 2.8f);
	
	//---------------game sprites--------------------

	Bird* flappy = new Bird();
	Pipe* firstPipes = new Pipe(600, -150 - 0, 600, 675 - 0); //difference is about ~825
	Pipe* secondPipes = new Pipe(1100, -150 - 50, 1100, 675 - 50);
	//-----------------------------------------------
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				flappy->mClick();
			}
		}
		flappy->moveBird();
		if (firstPipes->getArrayCounter() > randomString.length()){
			firstPipes->resetAC();
		}
		firstPipes->movePipes(randomString[firstPipes->getArrayCounter()]);
		secondPipes->movePipes(randomString[secondPipes->getArrayCounter()]);
		groundSprite->move(-0.02, 0);
		groundSpriteTwo->move(-0.02, 0);
		if (groundSprite->getPosition().x <= -700){
			groundSprite->setPosition(700, 775);
		}
		if (groundSpriteTwo->getPosition().x <= -700){
			groundSpriteTwo->setPosition(700, 775);
		}
		window.clear();
		window.draw(*backgroundSprite);
		window.draw(*groundSprite);
		window.draw(*groundSpriteTwo);
		window.draw(*(flappy->getSprite()));
		firstPipes->drawPipes(&window);
		secondPipes->drawPipes(&window);
		window.display();
	}

	return 0;
}