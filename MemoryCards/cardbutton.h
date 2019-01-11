#ifndef CARDBUTTON_H
#define CARDBUTTON_H

#include <QPushButton>
#include "card.h"

class CardButton : public QPushButton
{

    Q_OBJECT
private:
    Card *pCard;

public:
    explicit CardButton(QWidget *parent = nullptr);

    void setCard(Card *pc);

};

#endif // CARDBUTTON_H
