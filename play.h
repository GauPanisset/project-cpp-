#ifndef DEF_PARTIE
#define DEF_PARTIE

#include <string>
#include "card.h"

class Play
{

	private:
	int boxes;
	std::string mod;

	public:
	Play(int game_boxes, std::string game_mod);
	Card drawCard(); //Tire une carte
	void replaceACard(int box, Card playableCard); //Replacer une carte dans la bonne case
	//void run();  //Lance la partie
	int whichBox(); //Renvoie dans quelle case jouer

};

#endif
