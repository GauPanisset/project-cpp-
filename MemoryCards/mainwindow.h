#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "playwindow.h"
#include "createwindow.h"
#include <QMainWindow>
#include <QDir>
#include <QComboBox>
#include <string>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //Pour passer sur la fenêtre de jeu.
    void switchPlayWindow();
    //Pour passer sur la fenêtre de création.
    void switchCreateWindow();

private:
    Ui::MainWindow *ui;
    PlayWindow *pPlayWindow;
    CreateWindow *pCreateWindow;
};

#endif // MAINWINDOW_H
