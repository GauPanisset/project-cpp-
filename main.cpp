#include "card.h"
#include "play.h"
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

int main()
{
	while (1)
	{

		cout<<"*************************************"<<endl;
		cout<<"*************************************"<<endl;
		cout<<"**********                 **********"<<endl;
		cout<<"**********   Memory Card   **********"<<endl;
		cout<<"**********                 **********"<<endl;
		cout<<"*************************************"<<endl;
		cout<<"*************************************"<<endl;

		cout<<"Faites votre choix"<<endl;
		int choice;
		cout<<"1. Jouer"<<endl;
		cout<<"2. Parametres"<<endl;
		cout<<"3. Creer Cartes"<<endl;
		cout<<"4. Quitter"<<endl;
		cin>>choice;
		cin.ignore();
		ifstream my_file("NumberOfCards.txt");
        string nOfC;
        getline(my_file, nOfC);
        int numberOfCards = stoi(nOfC);
        my_file.close();

		if (choice == 1)
		{
		    int continuer;
		    cout<<"Voulez-vous commencer une nouvelle partie ou continuer celle en cours ?"<<endl;
		    cout<<"1. Nouvelle Partie"<<endl;
		    cout<<"2. Continuer"<<endl;
		    cin>>continuer;
		    cin.ignore();
		    if (continuer == 1)
            {
                ofstream my_file2("Settings.txt");
                int game_mode;
                cout<<endl<<"Mode de Jeu"<<endl;
                cout<<"1. Durable"<<endl;
                cout<<"2. Immediat"<<endl;
                cin>>game_mode;
                cin.ignore();

                if (game_mode == 1)
                {
                    my_file2<<"Durable"<<endl;
                }
                else
                {
                    my_file2<<"Immediat"<<endl;
                }

                int number_boxes;
                cout<<endl<<"Nombre de cases"<<endl;
                cout<<"2."<<endl;
                cout<<"3."<<endl;
                cin>>number_boxes;
                cin.ignore();
                my_file2<<number_boxes<<endl;
                my_file2.close();
                ifstream my_file3("Cards.txt");
                ofstream my_file4("Cards_Play.txt");
                ofstream my_file5("NumberOfCards_Play.txt");
                int number = 0;
                int cards;
                cout<<endl<<"Voulez-vous toutes les cartes ou en selectionner quelques unes ?"<<endl;
                cout<<"1. Toutes"<<endl;
                cout<<"2. Quelques unes"<<endl;
                cin>>cards;
                cin.ignore();
                string lines;
                if (cards == 1)
                {
                    for (int i = 0; i < 3*numberOfCards; i++)
                    {
                        getline(my_file3,lines);
                        my_file4<<lines<<endl;
                    }
                    my_file5<<numberOfCards;
                }

                if (cards == 2)
                {
                    int add;
                    for (int i = 0; i < 3*numberOfCards; i++)
                    {
                        getline(my_file3,lines);
                        if (i%3==0)
                        {
                            cout<<endl<<"Voulez-vous ";
                            cout<<lines<<endl;
                            cout<<"1. Oui"<<endl;
                            cout<<"2. Non"<<endl;
                            cin>>add;
                            cin.ignore();
                        }
                        if (add == 1)
                        {
                            my_file4<<lines<<endl;
                            number += 1;
                        }
                    }
                    my_file5<<number/3;
                }
                my_file3.close();
                my_file4.close();
                my_file5.close();
            }

			ifstream my_file1("Settings.txt");
			string game_mode;
			getline(my_file1, game_mode);
			int number_boxes;
			my_file1>>number_boxes;
			my_file1.close();

			Play play(number_boxes, game_mode);
			int playagain = 1;
			int box;
			do
            {
                box = play.whichBox();
                cout<<"box "<<box<<endl;
                Card playCard = play.drawCard();
                playCard.displayCard();
                playCard.swapCard();
                play.replaceACard(box,playCard);
                cout<<"Continuer a jouer ?"<<endl;
                cout<<"1. Oui"<<endl;
                cout<<"2. Non"<<endl;
                cin>>playagain;
                cin.ignore();
                cout<<"number boxes "<<number_boxes<<endl;
            }while(box <= number_boxes && playagain != 2);
            cout<<"test"<<endl;
            choice = 4;
		}


				if (choice == 2)
		{
			ofstream my_file2("Settings.txt");
			int game_mode;
			cout<<endl<<"Mode de Jeu"<<endl;
			cout<<"1. Durable"<<endl;
			cout<<"2. Immediat"<<endl;
			cin>>game_mode;
			if (game_mode == 1)
			{
				my_file2<<"Durable"<<endl;
			}
			else
			{
				my_file2<<"Immediat"<<endl;
			}

			int number_boxes;
			cout<<endl<<"Nombre de cases"<<endl;
			cout<<"2."<<endl;
			cout<<"3."<<endl;
			cin>>number_boxes;
			my_file2<<number_boxes<<endl;
			my_file2.close();
		}

		if (choice ==3)
		{
			ofstream my_file3("Cards.txt", ios::app);
			string recto;
			string verso;
			cout<<"Tapez le recto de votre carte puis Entree"<<endl;
			getline(cin, recto);
			my_file3<<endl<<recto<<endl;
			cout<<"Tapez le verso de votre carte puis Entree"<<endl;
			getline(cin, verso);
			my_file3<<verso<<endl;
			my_file3<<"1";
			my_file3.close();
			ifstream my_file4("NumberOfCards.txt");
			string nOfC;
			getline(my_file4, nOfC);
			int numberOfCards = stoi(nOfC);
			numberOfCards += 1;
			my_file4.close();
			ofstream my_file5("NumberOfCards.txt");
			my_file5<<numberOfCards;
			my_file5.close();
		}

		if (choice == 4)
		{
			break;
		}
	}
	return 0;
}
