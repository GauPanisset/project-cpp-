#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QMainWindow>
#include "card.h"
#include "play.h"
#include "cardbutton.h"

namespace Ui {
class PlayWindow;
}

class PlayWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayWindow(QWidget *parent = nullptr);
    ~PlayWindow();

    void setCurrentPlay(Play *pplay);

private:
    Ui::PlayWindow *ui;
    CardButton *pCardButton;

    //Card *pCurrentCard;
    Play *pCurrentPlay;

signals:
    void returnToMainWindow();

public slots:
    //void setCurrentCard(Card *pc);
    void toMainWindow();
    //Slots permettant de replacer la carte après une action du joueur.
    void yesAnswer();
    void maybeAnswer();
    void noAnswer();
};

#endif // PLAYWINDOW_H
