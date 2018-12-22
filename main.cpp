#include "card.h"
//#include "play.h"
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
			ifstream my_file("Settings.txt");
			string game_mode;
			getline(my_file, game_mode);
			int number_boxes;
			my_file >> number_boxes;
			Play play(number_boxes, game_mode);
		}
		
				if (choice == 2)
		{
			ofstream my_file("Settings.txt");
			int game_mode;
			cout<<endl<<"Mode de Jeu"<<endl;
			cout<<"1. Durable"<<endl;
			cout<<"2. Immediat"<<endl;
			cin>>game_mode;
			if (game_mode == 1)
			{
				my_file<<"Durable"<<endl;
			}
			else
			{
				my_file<<"Immediat"<<endl;
			}
			
			int number_boxes;
			cout<<endl<<"Nombre de cases"<<endl;
			cout<<"2."<<endl;
			cout<<"3."<<endl;
			cin>>number_boxes;
			my_file<<number_boxes<<endl;

		}
		
		if (choice ==3)
		{
			ofstream my_file("Cards.txt", ios::app);
			string recto;
			string verso;
			cout<<"Tapez le recto de votre carte puis Entree"<<endl;
			std::cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
			getline(cin, recto);
			my_file<<recto<<endl;
			cout<<"Tapez le verso de votre carte puis Entree"<<endl;
			getline(cin, verso);
			my_file<<verso<<endl;
			my_file<<"1"<<endl;
		}

		if (choice == 4)
		{
			break;
		}
	}
	return 0;
}
