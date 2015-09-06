#include <SFML/Graphics.hpp>
#include "Pipe.h"
#include "Background.h"
class Bird{
private:
	sf::Sprite* sprite;
	sf::IntRect* textureRect;
	sf::Texture* texture;
	double yVel = -.02; //was -.02
	double hoverYVel = 0;
	sf::Clock* birdClock;
	int aniFrame = 0;
	sf::Int32 aniSpeed = 200;
	void manageAngle();
	bool isGoingDown = true;

public:
	Bird();

	sf::Sprite* getSprite();
	void moveBird(Background* floorOne, Background* floorTwo);
	void hover();
	void mClick();
	bool hasCollided(Pipe* pipeOne, Pipe* pipeTwo, Background* floorOne, Background* floorTwo);
	void flap();
	void resetGame(Pipe* pipeOne, Pipe* pipeTwo);
	bool isAlive = true;
	bool hasStarted = false;
};