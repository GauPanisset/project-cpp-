#ifndef DEF_CARD
#define DEF_CARD

#include <string>

class Card
{
	private:
	std::string recto;
	std::string verso;
    bool rectoVisible; // Pour savoir quel cote est visible

	public:
    Card(std::string rectoCard, std::string versoCard);     //Contient le code qui sauvegarde les cartes créées.
    void swap(); // Permet de retourner la carte
    std::string getVisibleFace() const; //Retourne le texte de la face visible.
};

bool operator<(const Card &c1, const Card &c2);

#endif
