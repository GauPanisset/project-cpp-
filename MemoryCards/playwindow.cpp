#include "playwindow.h"
#include "ui_playwindow.h"

PlayWindow::PlayWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->menuButton, &QPushButton::clicked, this, &PlayWindow::toMainWindow);

    QObject::connect(ui->yesButton, &QPushButton::clicked, this, &PlayWindow::yesAnswer);
    QObject::connect(ui->maybeButton, &QPushButton::clicked, this, &PlayWindow::maybeAnswer);
    QObject::connect(ui->noButton, &QPushButton::clicked, this, &PlayWindow::noAnswer);

    QObject::connect(ui->cardButton, &QPushButton::clicked, this, &PlayWindow::switchEnabled);
}

PlayWindow::~PlayWindow()
{
    delete ui;
}

void PlayWindow::toMainWindow()
{
    pCurrentPlay->savePlay();
    emit returnToMainWindow();
}

void PlayWindow::startPlay(Play *pPlay)
{
    pCurrentPlay = pPlay;
    newTurn();
}

void PlayWindow::newTurn()
{
    Card *pc = pCurrentPlay->drawCard();
    if (pc != nullptr) {
        ui->cardButton->setCard(pc);
    }
    else
    {
        pCurrentPlay->savePlay();
        emit returnToMainWindow();
    }
}

void PlayWindow::activateButton(bool activated)
{
    ui->maybeButton->setVisible(activated);
}

void PlayWindow::switchEnabled()
{
    ui->cardButton->setEnabled(!ui->cardButton->isEnabled());
    ui->yesButton->setEnabled(!ui->yesButton->isEnabled());
    ui->maybeButton->setEnabled(!ui->maybeButton->isEnabled());
    ui->noButton->setEnabled(!ui->noButton->isEnabled());
}

void PlayWindow::yesAnswer()
{
    pCurrentPlay->replaceCard(0);
    switchEnabled();
    newTurn();
}

void PlayWindow::maybeAnswer() {
    pCurrentPlay->replaceCard(1);
    switchEnabled();
    newTurn();
}

void PlayWindow::noAnswer() {
    pCurrentPlay->replaceCard(2);
    switchEnabled();
    newTurn();
}
