#ifndef DEF_CARD
#define DEF_CARD

#include <string>
#include "tinyxml.h"
#include "tinystr.h"
#include <iostream>

class Card
{
	private:
    int id;
    std::string recto;
    std::string verso;
    bool rectoVisible; // Pour savoir quel cote est visible

	public:
    Card(std::string rectoCard, std::string versoCard);
    Card(int id); //Charge la carte d'indice id.
    void swap(); // Permet de retourner la carte
    std::string getVisibleFace() const; //Retourne le texte de la face visible.
    void saveCard(); //Sauvegarde une carde. Ecrit la carte dans le fichier "cards.xml".
};

bool operator<(const Card &c1, const Card &c2);

#endif
