#include <SFML/Graphics.hpp>
class Gameover{
private:
	sf::Sprite* sprite;
	sf::Texture* texture;
	sf::IntRect* textureRect;
public:
	Gameover(int type);
	sf::Sprite* getSprite();
	void determineMedal(int finalScore);
};