#include "play.h"

using namespace std;

Play::Play(string n, Card c[], int noc, int m)
{
    name = n;
    mode = m;
    currentSubbox = 1;
    for (int i = 0; i < noc; i++)
    {
        //Toutes les cartes se trouvent dans la première boite au début.
        box[c[i]] = 1;
    }
}

Play::Play(string n)
{
    //Charger la partie de nom n.
    name = n;
}

Card* Play::drawCard()
{
    //Définition des règles de tirage des cartes.
    switch (mode)
        {
            //Règles du mode "Révisions durables"
            case 0:
                break;
            //Règles du mode "Apprentissage temps limité"
            case 1:

                break;

            default:
                cout << "Error: mode unknown" << endl;
                break;
        }
    return nullptr;
}

void Play::replaceCard(Card card)
{
    box[card] = 0;
    //Définition des règles d'évolution des cartes.
    switch (mode)
    {
        //Règles du mode "Révisions durables"
        case 0:

            break;
        //Règles du mode "Apprentissage temps limité"
        case 1:

            break;

        default:
            cout << "Error: mode unknown" << endl;
            break;
    }
}
