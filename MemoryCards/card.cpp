#include "card.h"

using namespace std;

Card::Card(string rectoCard, string versoCard)
{
	recto = rectoCard;
	verso = versoCard;
    rectoVisible = true;
}

Card::Card(int i)
{

    TiXmlDocument doc("cards.xml");
    if (doc.LoadFile())
    {
        TiXmlElement *root = doc.RootElement();
        TiXmlElement *cardEl = root->FirstChildElement();

        int otherId = 0;
        cardEl->QueryIntAttribute("id", &otherId);
        while(cardEl && otherId != i)
        {
            cardEl->QueryIntAttribute("id", &otherId);
            cardEl = root->NextSiblingElement();
        }

        id = i;
        TiXmlElement *rectoEl = cardEl->FirstChildElement("recto");
        TiXmlElement *versoEl = cardEl->FirstChildElement("verso");

        recto = rectoEl->GetText();
        verso = versoEl->GetText();
        rectoVisible = true;
    }
    else
    {
        cout << "Error: cards.xml can't be loaded" << endl;
    }
}

void Card::swap()
{
	rectoVisible = !rectoVisible;
}

string Card::getVisibleFace() const
{
    return rectoVisible ? recto : verso;
}

bool operator<(const Card &c1, const Card &c2)
{
    return c1.getVisibleFace() < c2.getVisibleFace();
}

//Retourne le dernier id ou 0 si il n'existe pas.
int getLastId()
{
    TiXmlDocument doc("cards.xml");
    if (doc.LoadFile())
    {
        TiXmlElement *root = doc.RootElement();
        TiXmlElement *lastCard = root->LastChild("card")->ToElement();
        int id;
        if (lastCard->QueryIntAttribute("id", &id))
        {
            return id;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}


void Card::saveCard()
{
    TiXmlDocument doc("cards.xml");
    if (doc.LoadFile())
    {
        TiXmlElement *root = doc.RootElement();
        TiXmlElement *card = new TiXmlElement("card");
        TiXmlElement *rectoEl = new TiXmlElement("recto");
        TiXmlElement *versoEl = new TiXmlElement("verso");
        card->SetAttribute("id", id);
        rectoEl->LinkEndChild(new TiXmlText(recto.c_str()));
        versoEl->LinkEndChild(new TiXmlText(verso.c_str()));
        card->LinkEndChild(rectoEl);
        card->LinkEndChild(versoEl);
        root->LinkEndChild(card);
    }
}

