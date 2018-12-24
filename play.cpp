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
			string lines;
			getline(my_file7,lines);
			if (i%3 == 2)
			{
				int line = stoi(lines);
				if (line<box)
				{
					box = line;
				}			
			}
		}
		my_file7.close();
	}
	return box;
}

Card Play::drawCard()
{
	int box = Play::whichBox();
	ifstream my_file8("Cards.txt");
	string line1;
	string line2;
	string boxTempStr;
	int boxTemp = 0;
	while (boxTemp != box)
	{
		getline(my_file8, line1);
		getline(my_file8, line2);
		getline(my_file8, boxTempStr);
		boxTemp = stoi(boxTempStr);
	}
	Card playableCard(line1, line2);
	return playableCard;
}
/*
void Play::run()
{

}*/
