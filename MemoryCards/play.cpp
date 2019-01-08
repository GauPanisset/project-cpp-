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
	ifstream my_file6("NumberOfCards_Play.txt");
	string nOfC;
	getline(my_file6, nOfC);
	int numberOfCards = stoi(nOfC);
	my_file6.close();
	if (mod=="Durable")
	{
		ifstream my_file7("Cards_Play.txt");
		box = boxes;
		for (int i=0; i<3*numberOfCards; i++)
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
	ifstream my_file8("Cards_Play.txt");
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
void Play::replaceACard(int box, Card playableCard)
{
    cout<<"Avez-vous trouve la bonne reponse ?"<<endl;
    cout<<"1. Oui"<<endl;
    cout<<"2. Non"<<endl;
    int answer;
    cin>>answer;
    cin.ignore();
    ifstream my_file9("Cards_Play.txt");
    ofstream my_file10("Cards_Play_Bis.txt");
    ifstream my_file("NumberOfCards_Play.txt");
	string nOfC;
	getline(my_file, nOfC);
	int numberOfCards = stoi(nOfC);
	my_file.close();
	string recto;
	string newline1;
    string newline2;
    string newline3;
    if (answer ==1)
    {
        for (int i=0; i<3*numberOfCards;i++)
        {
            string lines;
            getline(my_file9,lines);
            if (i%3 != 2)
            {
                my_file10<<lines<<endl;
                if (i%3 == 0)
                {
                    recto = lines;
                }
            }

            else
                {
                    if (recto != playableCard.getRecto())
                    {
                        my_file10<<lines<<endl;
                    }
                    else
                    {
                        int addcase = stoi(lines);
                        addcase += 1;
                        my_file10<<addcase<<endl;
                    }
                }
        }

    }
    else
    {
        for (int i=0; i<3*numberOfCards;i++)
        {
            string lines;
            getline(my_file9,lines);
            if (i%3 != 2)
            {
                if (i%3 == 0)
                {
                    recto = lines;
                }
                if (recto != playableCard.getRecto())
                {
                    my_file10<<lines<<endl;
                }
                else
                {
                    if (i%3 == 0)
                    {
                        newline1 = lines;
                    }
                    if (i%3 == 1)
                    {
                        newline2 = lines;
                    }
                }
            }

            else
                {
                    if (recto != playableCard.getRecto())
                    {
                        my_file10<<lines<<endl;
                    }
                    else
                    {
                        newline3 = lines;
                    }
                }
        }
    }
    my_file10<<newline1<<endl;
    my_file10<<newline2<<endl;
    my_file10<<newline3<<endl;
    my_file9.close();
    my_file10.close();
    ofstream my_file11("Cards_Play.txt");
    ifstream my_file12("Cards_Play_Bis.txt");
    for (int i=0;i<3*numberOfCards;i++)
    {
        string lines;
        getline(my_file12,lines);
        my_file11<<lines<<endl;
    }
}
