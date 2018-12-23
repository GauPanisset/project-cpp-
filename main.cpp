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
		
		if (choice == 1)
		{
			ifstream my_file1("Settings.txt");
			string game_mode;
			getline(my_file1, game_mode);
			int number_boxes;
			my_file1>>number_boxes;
			my_file1.close();
			Play play(number_boxes, game_mode);
			int box = play.whichBox();
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
			std::cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
			getline(cin, recto);
			my_file3<<recto<<endl;
			cout<<"Tapez le verso de votre carte puis Entree"<<endl;
			getline(cin, verso);
			my_file3<<verso<<endl;
			my_file3<<"1"<<endl;
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
