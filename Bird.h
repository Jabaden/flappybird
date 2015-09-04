#include <SFML/Graphics.hpp>
class Bird{
private:
	sf::Sprite* sprite;
	sf::IntRect* textureRect;
	sf::Texture* texture;
	double yVel = -.02;
	sf::Clock* birdClock;
public:
	Bird();
	sf::Sprite* getSprite();
	void moveBird();
	void mClick();
};