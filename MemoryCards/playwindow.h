#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QMainWindow>
#include "card.h"
#include "play.h"

namespace Ui {
class PlayWindow;
}

class PlayWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayWindow(QWidget *parent = nullptr, Play *pPlay = nullptr);
    ~PlayWindow();

private:
    Ui::PlayWindow *ui;

    Card *pCurrentCard;
    Play *pCurrentPlay;

signals:
    void returnToMainWindow();

public slots:
    //Affiche la carte.
    void displayCard(Card *pc);
    void toMainWindow();
};

#endif // PLAYWINDOW_H
