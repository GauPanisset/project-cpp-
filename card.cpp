#include "card.h"
#include <iostream>

using namespace std;

Card::Card(string rectoCard, string versoCard)
{
	recto = rectoCard;
	verso = versoCard;
	visibleFace = "recto";
}

void Card::displayCard()
{
	if (visibleFace == "recto")
	{
		cout<<recto<<endl;
	}
	else
	{
		cout<<verso<<endl;
	}
}
