#include "cardbutton.h"

CardButton::CardButton(QWidget *parent) : QPushButton(parent)
{
    QObject::connect(this, &CardButton::clicked, this, &CardButton::swapCard);
}

void CardButton::setCard(Card *pc)
{
    pCard = pc;
    std::cout<<"Card : "<<pCard->getVisibleFace()<<std::endl;
    this->QPushButton::setText(QString::fromStdString(pCard->getVisibleFace()));
}

void CardButton::swapCard()
{
    qDebug("Coucou");
    pCard->swap();
    this->QPushButton::setText(QString::fromStdString(pCard->getVisibleFace()));
}
