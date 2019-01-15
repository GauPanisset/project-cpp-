#include "cardbutton.h"

CardButton::CardButton(QWidget *parent) : QPushButton(parent)
{
    QObject::connect(this, &CardButton::clicked, this, &CardButton::swapCard);
}

void CardButton::setCard(Card *pc)
{
    pCard = pc;
}

void CardButton::swapCard()
{
    qDebug("Coucou");
    pCard->swap();
    this->setText(QString::fromStdString(pCard->getVisibleFace()));
}
