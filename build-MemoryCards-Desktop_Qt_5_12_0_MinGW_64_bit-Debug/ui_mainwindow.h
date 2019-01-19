/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *createButton;
    QPushButton *playButton;
    QLabel *label;
    QTabWidget *tabSettings;
    QWidget *tabNew;
    QRadioButton *buttonImmediat;
    QRadioButton *buttonDurable;
    QLabel *label_2;
    QWidget *tabLoad;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        createButton = new QPushButton(centralWidget);
        createButton->setObjectName(QString::fromUtf8("createButton"));
        createButton->setGeometry(QRect(10, 100, 114, 32));
        playButton = new QPushButton(centralWidget);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        playButton->setGeometry(QRect(280, 100, 114, 32));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 30, 47, 13));
        tabSettings = new QTabWidget(centralWidget);
        tabSettings->setObjectName(QString::fromUtf8("tabSettings"));
        tabSettings->setGeometry(QRect(120, 20, 151, 221));
        tabNew = new QWidget();
        tabNew->setObjectName(QString::fromUtf8("tabNew"));
        buttonImmediat = new QRadioButton(tabNew);
        buttonImmediat->setObjectName(QString::fromUtf8("buttonImmediat"));
        buttonImmediat->setGeometry(QRect(10, 30, 82, 17));
        buttonDurable = new QRadioButton(tabNew);
        buttonDurable->setObjectName(QString::fromUtf8("buttonDurable"));
        buttonDurable->setGeometry(QRect(10, 50, 82, 17));
        label_2 = new QLabel(tabNew);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 10, 61, 16));
        tabSettings->addTab(tabNew, QString());
        tabLoad = new QWidget();
        tabLoad->setObjectName(QString::fromUtf8("tabLoad"));
        tabSettings->addTab(tabLoad, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabSettings->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        createButton->setText(QApplication::translate("MainWindow", "Create", nullptr));
        playButton->setText(QApplication::translate("MainWindow", "Play", nullptr));
        label->setText(QString());
        buttonImmediat->setText(QApplication::translate("MainWindow", "Immediat", nullptr));
        buttonDurable->setText(QApplication::translate("MainWindow", "Durable", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Mode de jeu", nullptr));
        tabSettings->setTabText(tabSettings->indexOf(tabNew), QApplication::translate("MainWindow", "New", nullptr));
        tabSettings->setTabText(tabSettings->indexOf(tabLoad), QApplication::translate("MainWindow", "Load", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
