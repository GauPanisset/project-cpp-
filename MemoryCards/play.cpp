#include "play.h"

#define MYPATH "/MemoryCards/save/plays.xml"

using namespace std;

bool mystrptime(string s, Date* d)
{
    if (s.length() == 10)
    {
        d->tm_mday = stoi(s.substr(0, 2));
        d->tm_mon = stoi(s.substr(3, 2));
        d->tm_year = stoi(s.substr(6, 4));
        return true;
    }
    return false;
}


Play::Play(string n, Card *c[], int noc, int m)
{
    name = n;
    mode = m;
    currentSubboxNumber = 1;
    for (int i = 0; i < noc; i++)
    {
        //Toutes les cartes se trouvent dans la première boite au début.
        box[c[i]] = 1;
        cardNotSeen.insert(c[i]);
    }
}

Play::Play(string n)
{
    //Charger la partie de nom n.
    QDir relativePath;
    QString absolutePath = relativePath.absolutePath();
    QString savePath(MYPATH);
    absolutePath += savePath;

    TiXmlDocument doc(absolutePath.toStdString().c_str());
    if (doc.LoadFile())
    {
        cout<<"File "<<absolutePath.toStdString()<<" is open"<<endl;
        TiXmlElement *root = doc.RootElement();     //<SavedPlays>
        TiXmlElement *playEl = root->FirstChildElement();

        while(playEl && n!=playEl->Attribute("name"))
        {
            playEl = playEl->NextSiblingElement();
        }

        if (playEl)
        {
            bool dayType[7];
            mode = atoi(playEl->Attribute("mode"));
            const char* stringDate = playEl->Attribute("date");
            Date playDate;
            if (mystrptime(stringDate, &playDate))
            {

                int d = playDate.tm_mday,
                    m = playDate.tm_mon + 1,
                    y = playDate.tm_year + 1900;

                time_t now = time(nullptr);
                Date *local = localtime(&now);

                int dNow = local->tm_mday,
                    mNow = local->tm_mon + 1,
                    yNow = local->tm_year + 1900;

                //Tous les jours
                dayType[0] = true;
                //Tous les deux jours
                dayType[1] = (dNow - d)%2 == 0;
                //Tous les lundis
                dayType[2] = local->tm_wday == 1;
                //Chaque premier du mois
                dayType[3] = dNow == 1 && (dNow - d) == 0;
                //Tous les 3 mois
                dayType[4] = (mNow - m)%3 == 0 && (dNow - d) == 0;
                //Tous les 6 mois
                dayType[5] = (mNow - m)%6 == 0 && (dNow - d) == 0;
                //Tous les ans
                dayType[6] = (yNow - y) > 0 && (mNow - m) == 0 && (dNow - d) == 0;
            }
            else
            {
                cout<<"Error: date can't be loaded"<<endl;
            }
            currentSubboxNumber = mode == 0 ? 1 : atoi(playEl->Attribute("step"));

            name = n;

            TiXmlElement *boxEl = playEl->FirstChildElement("box");
            while (boxEl)
            {
                int boxNumber = atoi(boxEl->Attribute("number"));
                TiXmlElement *cardEl = playEl->FirstChildElement("card");
                while (cardEl)
                {
                    Card *pcard = new Card(cardEl->Attribute("collection"), atoi(cardEl->Attribute("id")));
                    if (atoi(cardEl->Attribute("visible")))
                    {
                        pcard->swap();
                    }
                    box[pcard] = boxNumber;
                    if (mode == 1 || dayType[boxNumber])
                    {
                        cardNotSeen.insert(pcard);
                    }

                    cardEl = cardEl->NextSiblingElement();
                }
                boxEl = boxEl->NextSiblingElement();
            }
        }
        else
        {
            cout<<"Error : Play not found"<<endl;
        }
    }
    else
    {
        cout << "Error: "<< absolutePath.toStdString() <<" can't be loaded (" << doc.ErrorDesc() << ")" << endl;
    }
}

Card* Play::drawCard()
{
    //Définition des règles de tirage des cartes.
    switch (mode)
    {
    //Règles du mode "Révisions durables"
    case 0:
    {

        if (!cardNotSeen.empty())
        {
            CardSet::iterator it = cardNotSeen.begin();
            cardNotSeen.erase(it);
            return *it;
        }
        return nullptr;
    }
    //Règles du mode "Apprentissage temps limité"
    case 1:
    {
        Box::iterator it = box.begin();
        while (it != box.end())
        {
            if (it->second == currentSubboxNumber)
            {
                return it->first;
            }
            it++;
        }
        currentSubboxNumber = currentSubboxNumber < 6 ? currentSubboxNumber + 1:1;
        return nullptr;
    }
    default:
        cout << "Error: mode unknown" << endl;
        return nullptr;
    }

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
            if (currentSubboxNumber < 7)
            {
                box[pCurrentCard] += 1;
            }
            break;
            //Mauvaise réponse
        case 2:
            if (currentSubboxNumber > 1)
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
            switch (currentSubboxNumber)
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
            switch (currentSubboxNumber)
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
            switch (currentSubboxNumber)
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
