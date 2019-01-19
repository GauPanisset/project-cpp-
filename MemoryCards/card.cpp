#include "card.h"

#define MYPATH "/MemoryCards/save/cards.xml"

using namespace std;

//Retourne le dernier id ou 0 si il n'existe pas.
int getLastId()
{
    QDir relativePath;
    QString absolutePath = relativePath.absolutePath();
    QString savePath(MYPATH);
    absolutePath += savePath;

    TiXmlDocument doc(absolutePath.toStdString().c_str());
    if (doc.LoadFile())
    {
        TiXmlElement *root = doc.RootElement();
        int id;
        if (root->QueryIntAttribute("lastId", &id) == TIXML_SUCCESS)
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
        cout << "Error : cards.xml can't be loaded"<<endl;
        return 0;
    }
}

Card::Card(string rectoCard, string versoCard, string c)
{
	recto = rectoCard;
	verso = versoCard;
    rectoVisible = true;
    id = getLastId() + 1;
    collection = c;
}

Card::Card(string c, int i)
{
    QDir relativePath;
    QString absolutePath = relativePath.absolutePath();
    QString savePath(MYPATH);
    absolutePath += savePath;

    TiXmlDocument doc(absolutePath.toStdString().c_str());
    if (doc.LoadFile())
    {
        cout<<"File "<<absolutePath.toStdString()<<" is open"<<endl;
        TiXmlElement *root = doc.RootElement();
        TiXmlElement *collectionEl = root->FirstChildElement();

        while(collectionEl && collectionEl->Attribute("name") != c)
        {
            collectionEl = collectionEl->NextSiblingElement();
        }
        if (collectionEl)
        {
            TiXmlElement *cardEl = collectionEl->FirstChildElement();
            int otherId = 0;
            cardEl->QueryIntAttribute("id", &otherId);
            while(cardEl && otherId != i)
            {
                cardEl->QueryIntAttribute("id", &otherId);
                cardEl = cardEl->NextSiblingElement();
            }

            if (cardEl)
            {
                id = i;
                TiXmlElement *rectoEl = cardEl->FirstChildElement("recto");
                TiXmlElement *versoEl = cardEl->FirstChildElement("verso");

                recto = rectoEl->GetText();
                verso = versoEl->GetText();
                rectoVisible = true;
            }
            else
            {
                cout<<"Error : Card not found"<<endl;
            }
        }
        else
        {
            cout<<"Error : Collection not found"<<endl;
        }
    }
    else
    {
        cout << "Error: "<< absolutePath.toStdString() <<" can't be loaded (" << doc.ErrorDesc() << ")" << endl;
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

bool Card::saveCard()
{
    QDir relativePath;
    QString absolutePath = relativePath.absolutePath();
    QString savePath(MYPATH);
    absolutePath += savePath;

    TiXmlDocument doc(absolutePath.toStdString().c_str());
    if (doc.LoadFile())
    {
        TiXmlElement *root = doc.RootElement();

        TiXmlElement *cardEl = new TiXmlElement("card");
        TiXmlElement *rectoEl = new TiXmlElement("recto");
        TiXmlElement *versoEl = new TiXmlElement("verso");
        cardEl->SetAttribute("id", id);
        rectoEl->LinkEndChild(new TiXmlText(recto.c_str()));
        versoEl->LinkEndChild(new TiXmlText(verso.c_str()));
        cardEl->LinkEndChild(rectoEl);
        cardEl->LinkEndChild(versoEl);

        TiXmlElement *collectionEl = root->FirstChildElement();
        while (collectionEl->Attribute("name") != collection)
        {
            collectionEl = collectionEl->NextSiblingElement();
            std::cout<<collectionEl->Attribute("name")<<std::endl;
        }
        if (collectionEl)
        {
            collectionEl->SetAttribute("count", atoi(collectionEl->Attribute("count")) + 1);
            collectionEl->LinkEndChild(cardEl);
            root->LinkEndChild(collectionEl);
        }
        else
        {
            TiXmlElement *collectionEl = new TiXmlElement("collection");
            collectionEl->SetAttribute("name", collection.c_str());
            collectionEl->SetAttribute("count", 1);
            collectionEl->LinkEndChild(cardEl);
            root->LinkEndChild(collectionEl);
        }

        doc.SaveFile(absolutePath.toStdString().c_str());
        return true;
    }
    else
    {
        return false;
    }
}

