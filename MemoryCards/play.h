#ifndef DEF_PARTIE
#define DEF_PARTIE

#include "card.h"
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <QDir>
#include <time.h>
#include <ctime>

typedef std::map<Card*,int> Box;
typedef std::set<Card*> CardSet;
typedef struct tm Date;

class Play
{
	private:
    int mode;
    int currentSubboxNumber;
    CardSet cardNotSeen;
    Card *pCurrentCard;
    Box box;
    std::string name;

	public:
    Play(std::string name, CardSet cardsSet, int mode);
    Play(std::string name);
    Card* drawCard(); //Sélectionne une carte dans la boite courante et la charge.
    void replaceCard(int pressedButton); //Replace la carte courante dans la bonne subbox.
    size_t numberOfCards(); //Retourne le nombre de cartes dans la boite.
    void displayBox(); //Affiche l'état de la boite.
};

#endif
