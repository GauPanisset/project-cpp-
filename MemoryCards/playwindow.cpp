#include "playwindow.h"
#include "ui_playwindow.h"

PlayWindow::PlayWindow(QWidget *parent, Play *pp) :
    QMainWindow(parent),
    ui(new Ui::PlayWindow)
{
    ui->setupUi(this);

    pCurrentPlay = pp;

    QObject::connect(ui->menuButton, &QPushButton::clicked, this, &PlayWindow::toMainWindow);
}

PlayWindow::~PlayWindow()
{
    delete ui;
}

void PlayWindow::toMainWindow()
{
    emit returnToMainWindow();
}

void PlayWindow::displayCard(Card *pc) {
    pCurrentCard = pc;
}
