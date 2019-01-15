/********************************************************************************
** Form generated from reading UI file 'playwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYWINDOW_H
#define UI_PLAYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "cardbutton.h"

QT_BEGIN_NAMESPACE

class Ui_PlayWindow
{
public:
    QWidget *centralWidget;
    CardButton *cardButton;
    QPushButton *menuButton;
    QPushButton *yesButton;
    QPushButton *maybeButton;
    QPushButton *noButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PlayWindow)
    {
        if (PlayWindow->objectName().isEmpty())
            PlayWindow->setObjectName(QString::fromUtf8("PlayWindow"));
        PlayWindow->resize(400, 300);
        centralWidget = new QWidget(PlayWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        cardButton = new CardButton(centralWidget);
        cardButton->setObjectName(QString::fromUtf8("cardButton"));
        cardButton->setGeometry(QRect(73, 20, 261, 161));
        menuButton = new QPushButton(centralWidget);
        menuButton->setObjectName(QString::fromUtf8("menuButton"));
        menuButton->setGeometry(QRect(0, 0, 31, 32));
        yesButton = new QPushButton(centralWidget);
        yesButton->setObjectName(QString::fromUtf8("yesButton"));
        yesButton->setGeometry(QRect(10, 200, 114, 32));
        maybeButton = new QPushButton(centralWidget);
        maybeButton->setObjectName(QString::fromUtf8("maybeButton"));
        maybeButton->setGeometry(QRect(140, 200, 114, 32));
        noButton = new QPushButton(centralWidget);
        noButton->setObjectName(QString::fromUtf8("noButton"));
        noButton->setGeometry(QRect(270, 200, 114, 32));
        PlayWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PlayWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 22));
        PlayWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PlayWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        PlayWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PlayWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        PlayWindow->setStatusBar(statusBar);

        retranslateUi(PlayWindow);

        QMetaObject::connectSlotsByName(PlayWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PlayWindow)
    {
        PlayWindow->setWindowTitle(QApplication::translate("PlayWindow", "PlayWindow", nullptr));
        cardButton->setText(QApplication::translate("PlayWindow", "PushButton", nullptr));
        menuButton->setText(QApplication::translate("PlayWindow", "=", nullptr));
        yesButton->setText(QApplication::translate("PlayWindow", "Oui", nullptr));
        maybeButton->setText(QApplication::translate("PlayWindow", "Bof", nullptr));
        noButton->setText(QApplication::translate("PlayWindow", "Non", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayWindow: public Ui_PlayWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYWINDOW_H
