
#include <SFML/Graphics.hpp>
using namespace std;
class Score{
private:
	//using sVector = vector<sf::Sprite>;
	/*sVector *score;
	sf::Texture* texture;
	sf::IntRect* textureRect;
	*/
	sf::Font* flappyFont;
	sf::Text* score;
public:
	Score();
	void drawScore(sf::RenderWindow* wnd);
	sf::Text* getScore();
	void setScoreText(string newScore);
	void alignToScoreBoard(bool isTop);
};
