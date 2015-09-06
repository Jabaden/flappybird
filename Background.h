#include <SFML/Graphics.hpp>
class Background{
private:
	sf::Sprite* sprite;
	sf::Texture* texture;
	sf::IntRect* textureRect;
public:
	Background(int type = 0);
	static int spriteCounter;
	sf::Sprite* getSprite();
	void moveFloor();
};