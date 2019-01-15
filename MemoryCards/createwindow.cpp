#include "createwindow.h"
#include "ui_createwindow.h"

CreateWindow::CreateWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CreateWindow)
{
    ui->setupUi(this);
    ui->labelText->hide();

    QObject::connect(ui->menuButton, &QPushButton::clicked, this, &CreateWindow::toMainWindow);
    QObject::connect(ui->okButton, &QPushButton::clicked, this, &CreateWindow::createCard);
    ui->okButton->setShortcut(Qt::Key_Return);
}

CreateWindow::~CreateWindow()
{
    delete ui;
}

void CreateWindow::toMainWindow()
{
    emit returnToMainWindow();
}

void CreateWindow::createCard()
{
    std::string recto = ui->rectoEdit->text().toStdString();
    std::string verso = ui->versoEdit->text().toStdString();
    Card cardAdded = Card(recto,verso);
    cardAdded.saveCard();
    ui->rectoEdit->clear();
    ui->versoEdit->clear();
    ui->labelText->show();
    QTimer *timer = new QTimer();
    timer->connect(timer, SIGNAL(timeout()), ui->labelText, SLOT(hide()));
    timer->start(1000);
}
