#include <SFML/Graphics.hpp>
class Pipe{
private:
	sf::Sprite* topSprite;
	sf::Sprite* botSprite;
	sf::Texture* texture;
	sf::IntRect* topRect;
	sf::IntRect* botRect;
	float pYScale = 4.0f;
	float pXScale = 4.5f;
	static int arrayCounter;
public:
	
	Pipe(int topX, int topY, int botX, int botY);
	void drawPipes(sf::RenderWindow* wnd);
	void movePipes(char sNumber);
	void setPipePosition(char sNumber);
	int getArrayCounter();
	void incrementAC();
	void resetAC();
	sf::Sprite* getTopSprite();
	sf::Sprite* getBotSprite();
	
};