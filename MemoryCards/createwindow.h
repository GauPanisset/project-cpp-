#ifndef CREATEWINDOW_H
#define CREATEWINDOW_H

#include <QMainWindow>
#include "card.h"
#include "play.h"

namespace Ui {
class CreateWindow;
}

class CreateWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit CreateWindow(QWidget *parent = nullptr);
    ~CreateWindow();

private:
    Ui::CreateWindow *ui;

signals:
    void returnToMainWindow();

public slots:
    void toMainWindow();
};

#endif // CREATEWINDOW_H
