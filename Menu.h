#include <SFML/Graphics.hpp>
class Menu{
private:
	sf::Sprite* sprite;
	sf::Texture* texture;
	sf::IntRect* textureRect;
public:
	Menu(int type);
	sf::Sprite* getSprite();
};