#include "cardbutton.h"
#include "playwindow.h"

CardButton::CardButton(QWidget *parent) : QPushButton(parent)
{
    QObject::connect(this, &CardButton::clicked, this, &CardButton::swapCard);
}

void CardButton::setCard(Card *pc)
{
    pCard = pc;
    this->setText(QString::fromStdString(pCard->getVisibleFace()));
}

void CardButton::swapCard()
{
    pCard->swap();
    this->setText(QString::fromStdString(pCard->getVisibleFace()));
}
