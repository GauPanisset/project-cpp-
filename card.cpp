#include "card.h"
#include <iostream>
#include <cstdio>

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

void Card::swapCard()
{
	cout<<"Appuyer sur Entree pour retourner la carte et vérifiez votre réponse";
	while(getchar() != '\n'); //Attendre que l'utilisateur ai appuye sur Entree pour retourner la carte
	if (visibleFace == "recto")
	{
		visibleFace = "verso";
	}
	else
	{
		visibleFace = "recto";
	}
	Card::displayCard();

}
