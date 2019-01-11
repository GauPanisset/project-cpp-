#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "playwindow.h"

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

private:
    Ui::MainWindow *ui;
    PlayWindow *pPlayWindow;
};

#endif // MAINWINDOW_H
