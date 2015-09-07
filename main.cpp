#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Bird.h"
#include "Menu.h"
#include "Score.h"
#include "Gameover.h"
//#include "Pipe.h"

//testing git
using namespace std;

int Pipe::arrayCounter; //static variable for pipes
int Background::spriteCounter = 1;

int main()
{
	sf::RenderWindow window(sf::VideoMode(700, 900), "Flappy Bird!");
	string randomString = ""; //string used to make the program "random" but not really =D
	for (int i = 0607; i < 10620; i+= 1001){ //arbitrary numbers. Changing these would change the layout of the level.
		srand(i);
		int tempRandom = rand();
		string tempString = to_string(tempRandom);
		randomString += tempString;
	}
	
	int baseBackgroundType = 1;
	

	//-----------Background sprites-----------------
	Background* background = new Background(baseBackgroundType);
	Background* groundSprite = new Background();
	Background* groundSpriteTwo = new Background();
	//-----------------------------------------------

	//---------------Menu Sprites--------------------
	Menu* tutorial = new Menu(1);
	Score* title = new Score();
	title->setScoreText("FLAPPY BIRD");
	title->getScore()->setPosition(120, 200);
	title->getScore()->setCharacterSize(75);
	//-----------------------------------------------
	//---------------Score stuff---------------------
	Score* score = new Score();
	Score* tinyScore = new Score();
	Score* highScore = new Score();
	tinyScore->alignToScoreBoard(true);
	highScore->alignToScoreBoard(false);
	Gameover* scoreboard = new Gameover(1);
	Gameover* medal = new Gameover(2);
	//
	//---------------game sprites--------------------

	Bird* flappy = new Bird();
	Pipe* firstPipes = new Pipe(1100, -150 - 0, 1100, 675 - 0); //difference is about ~825
	Pipe* secondPipes = new Pipe(1600, -150 - 50, 1600, 675 - 50);
	
	//-----------------------------------------------
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				if (flappy->isAlive && flappy->isAtMenu){
					flappy->isAtMenu = false;
				}
				else if (flappy->isAlive && !(flappy->isAtMenu)){
					flappy->hasStarted = true;
					flappy->mClick();
				}
				else{
					flappy->resetGame(firstPipes, secondPipes);
				}
			}
		}
		if (flappy->hasStarted){
			flappy->moveBird(groundSprite, groundSpriteTwo);
		}
		if (firstPipes->getArrayCounter() > randomString.length()){
			firstPipes->resetAC();
		}
		if (flappy->isAlive){
			if (flappy->hasStarted){
				flappy->flap();
				flappy->checkIfScored(firstPipes, secondPipes);
				firstPipes->movePipes(randomString[firstPipes->getArrayCounter()]);
				secondPipes->movePipes(randomString[secondPipes->getArrayCounter()]);
			}
			else{
				flappy->hover();
			}
			groundSprite->moveFloor();
			groundSpriteTwo->moveFloor();
		}
		if (flappy->hasCollided(firstPipes, secondPipes, groundSprite, groundSpriteTwo)){
			//cout << "what is going on" << endl;
			if (flappy->isAlive){
				medal->determineMedal(flappy->getScore());
				flappy->updateHighScore();
				tinyScore->setScoreText(to_string(flappy->getScore()));
				highScore->setScoreText(to_string(flappy->getTopScore()));
			}
			flappy->isAlive = false;
		}
		//----------------more background stuff-----

		//------------------------------------------
		window.clear();
		window.draw(*(background->getSprite()));
		if (!(flappy->hasStarted) && !(flappy->isAtMenu)){
			window.draw(*(tutorial->getSprite()));
		}
		window.draw(*(groundSprite->getSprite()));
		window.draw(*(groundSpriteTwo->getSprite()));
		firstPipes->drawPipes(&window);
		secondPipes->drawPipes(&window);
		if (flappy->isAtMenu){
			window.draw(*(title->getScore()));
		}
		if (flappy->hasStarted && flappy->isAlive && !(flappy->isAtMenu)){
			score->setScoreText(to_string(flappy->getScore()));
			window.draw(*(score->getScore()));
		}
		if (flappy->isAlive == false){ //display scoreboard and medal
			window.draw(*(scoreboard->getSprite()));
			window.draw(*(medal->getSprite()));
			window.draw(*(highScore->getScore()));
			window.draw(*(tinyScore->getScore()));
		}
		window.draw(*(flappy->getSprite()));
		//score->drawScore(&window);

		window.display();
	}
	return 0;
}