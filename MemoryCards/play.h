#ifndef DEF_PARTIE
#define DEF_PARTIE

#include "card.h"
#include <string>
#include <map>
#include <iostream>
#include <fstream>

class Play
{

	private:
    int mode;
    int currentSubbox;
    std::map <Card, int> box;
    std::string name;

	public:
    Play(std::string name, Card cardsList[],int numberOfCards, int mode);
    Play(std::string name);
    Card* drawCard(); //Sélectionne une carte dans la boite courante et la charge.
    void replaceCard(Card card); //Replace une carte dans la bonne subbox.
};

#endif
