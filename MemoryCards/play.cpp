#include "play.h"

using namespace std;

Play::Play(string n, Card *c[], int noc, int m)
{
    name = n;
    mode = m;
    currentSubbox = 1;

    for (int i = 0; i < noc; i++)
    {
        //Toutes les cartes se trouvent dans la première boite au début.
        box[c[i]] = 1;
    }

    pCurrentCard = drawCard();
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

void Play::replaceCard(int pressedButton)
{
    //Définition des règles d'évolution des cartes.
    switch (mode)
    {
    //Règles du mode "Révisions durables"
    case 0:
        switch (pressedButton)
        {
            //Bonne réponse
        case 0:
            if (currentSubbox < 7)
            {
                box[pCurrentCard] += 1;
            }
            break;
            //Mauvaise réponse
        case 2:
            if (currentSubbox > 1)
            {
                box[pCurrentCard] -= 1;
            }
            break;
        default:
            cout<<"Error: no rules"<<endl;
        }
        break;
    //Règles du mode "Apprentissage temps limité"
    case 1:
        switch (pressedButton)
        {
            //Bonne réponse
        case 0:
            switch (currentSubbox)
            {
            case 1:
                box[pCurrentCard] = 3;
                break;
            case 2:
                box[pCurrentCard] = 5;
                break;
            case 3:
                box[pCurrentCard] = 5;
                break;
            case 4:
                box[pCurrentCard] = 5;
                break;
            case 5:
                box[pCurrentCard] = 7;
                break;
            case 6:
                box[pCurrentCard] = 7;
                break;
            default:
                cout<<"Error: no rules"<<endl;
            }
            break;

            //Réponse avec un doute
        case 1:
            switch (currentSubbox)
            {
            case 1:
                box[pCurrentCard] = 2;
                break;
            case 2:
                box[pCurrentCard] = 4;
                break;
            case 3:
                box[pCurrentCard] = 5;
                break;
            case 4:
                box[pCurrentCard] = 5;
                break;
            case 5:
                box[pCurrentCard] = 6;
                break;
            case 6:
                box[pCurrentCard] = 1;
                break;
            default:
                cout<<"Error: no rules"<<endl;
            }
            break;

        //Mauvaise réponse
        case 2:
            switch (currentSubbox)
            {
            case 1:
                box[pCurrentCard] = 1;
                break;
            case 2:
                box[pCurrentCard] = 3;
                break;
            case 3:
                box[pCurrentCard] = 4;
                break;
            case 4:
                box[pCurrentCard] = 5;
                break;
            case 5:
                box[pCurrentCard] = 5;
                break;
            case 6:
                box[pCurrentCard] = 1;
                break;
            default:
                cout<<"Error: no rules"<<endl;
            }
            break;
        default:
            cout<<"Error: no rules"<<endl;
        }
        break;


    default:
        cout << "Error: mode unknown" << endl;
    }
}
