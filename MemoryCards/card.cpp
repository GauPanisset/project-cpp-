#include "card.h"
#include "play.h"
#include <iostream>


using namespace std;

Card::Card(string rectoCard, string versoCard)
{
	recto = rectoCard;
	verso = versoCard;
	rectoVisible = true;
    
}

void Card::swap()
{
	rectoVisible = !rectoVisible;
}

string Card::getVisibleFace() const
{
    return rectoVisible ? recto : verso;
}

bool operator<(const Card &c1, const Card &c2)
{
    return c1.getVisibleFace() < c2.getVisibleFace();
}
