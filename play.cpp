#include "play.h"
#include "card.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Play::Play(int game_boxes, string game_mod)
{
	boxes = game_boxes;
	mod = game_mod;
}

int Play::whichBox()
{
	int box;
	ifstream my_file6("NumberOfCards.txt");
	string nOfC;
	getline(my_file6, nOfC);
	int numberOfCards = stoi(nOfC);
	my_file6.close();
	if (mod=="Durable")
	{
		ifstream my_file7("Cards.txt");
		box = boxes;
		for (int i=0; i<3*numberOfCards-1; i++)
		{	
			string lignes;
			getline(my_file7,lignes);
			if (i%3 == 2)
			{
				int ligne = stoi(lignes);
				if (ligne<box)
				{
					box = ligne;
				}			
			}
		}
		my_file7.close();
	}
	return box;
}

/*void Play::drawCard()
{
	Card playableCard;

}

void Play::run()
{

}*/
