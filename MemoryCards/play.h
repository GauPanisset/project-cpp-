#ifndef DEF_PARTIE
#define DEF_PARTIE

#include "card.h"
#include <string>
#include <map>
#include <iostream>
#include <fstream>

typedef std::map<Card*,int> Box;

class Play
{

	private:
    int mode;
    int currentSubbox;
    Card *pCurrentCard;
    Box box;
    std::string name;

	public:
    Play(std::string name, Card *cardsList[], int numberOfCards, int mode);
    Play(std::string name);
    Card* drawCard(); //Sélectionne une carte dans la boite courante et la charge.
    void replaceCard(int pressedButton); //Replace la carte courante dans la bonne subbox.
};

#endif
