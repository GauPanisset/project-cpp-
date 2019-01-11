#include "createwindow.h"
#include "ui_createwindow.h"

CreateWindow::CreateWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CreateWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->menuButton, &QPushButton::clicked, this, &CreateWindow::toMainWindow);
}

CreateWindow::~CreateWindow()
{
    delete ui;
}

void CreateWindow::toMainWindow()
{
    emit returnToMainWindow();
}
