#ifndef DEF_CARD
#define DEF_CARD

#include <string>

class Card
{
	private:
	std::string recto;
	std::string verso;
	std::string visibleFace; // Pour savoir quel cote est visible
	
	public:
	Card(std::string rectoCard, std::string versoCard);
	void displayCard();
	void swapCard();

};

#endif
