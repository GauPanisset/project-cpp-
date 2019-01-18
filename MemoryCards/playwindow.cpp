#include "playwindow.h"
#include "ui_playwindow.h"

PlayWindow::PlayWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayWindow)
{
    ui->setupUi(this);

    pCardButton = new CardButton();

    QObject::connect(ui->menuButton, &QPushButton::clicked, this, &PlayWindow::toMainWindow);
    QObject::connect(ui->yesButton, &QPushButton::clicked, this, &PlayWindow::yesAnswer);
    QObject::connect(ui->maybeButton, &QPushButton::clicked, this, &PlayWindow::maybeAnswer);
    QObject::connect(ui->noButton, &QPushButton::clicked, this, &PlayWindow::noAnswer);
}

PlayWindow::~PlayWindow()
{
    delete ui;
}

void PlayWindow::toMainWindow()
{
    emit returnToMainWindow();
}

void PlayWindow::startPlay(Play *pplay)
{
    pCurrentPlay = pplay;

    Card *pc = pCurrentPlay->drawCard();
    if (pc != nullptr) {
        pCardButton->setCard(pc);
    }
    else
    {
       std::cout<<"Error: no cards"<<std::endl;
    }
}

void PlayWindow::yesAnswer() {pCurrentPlay->replaceCard(0);}

void PlayWindow::maybeAnswer() {pCurrentPlay->replaceCard(1);}

void PlayWindow::noAnswer() {pCurrentPlay->replaceCard(2);}
