#include "cardbutton.h"

CardButton::CardButton(QWidget *parent) : QPushButton(parent)
{
}

void CardButton::setCard(Card *pc)
{
    pCard = pc;
}
