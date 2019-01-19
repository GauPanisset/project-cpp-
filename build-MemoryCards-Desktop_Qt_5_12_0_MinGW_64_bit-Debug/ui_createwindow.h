/********************************************************************************
** Form generated from reading UI file 'createwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEWINDOW_H
#define UI_CREATEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateWindow
{
public:
    QWidget *centralWidget;
    QPushButton *menuButton;
    QLineEdit *rectoEdit;
    QLineEdit *versoEdit;
    QPushButton *okButton;
    QLabel *labelText;
    QLineEdit *collectionEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CreateWindow)
    {
        if (CreateWindow->objectName().isEmpty())
            CreateWindow->setObjectName(QString::fromUtf8("CreateWindow"));
        CreateWindow->resize(400, 300);
        centralWidget = new QWidget(CreateWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        menuButton = new QPushButton(centralWidget);
        menuButton->setObjectName(QString::fromUtf8("menuButton"));
        menuButton->setGeometry(QRect(360, 0, 31, 32));
        rectoEdit = new QLineEdit(centralWidget);
        rectoEdit->setObjectName(QString::fromUtf8("rectoEdit"));
        rectoEdit->setGeometry(QRect(30, 60, 311, 20));
        versoEdit = new QLineEdit(centralWidget);
        versoEdit->setObjectName(QString::fromUtf8("versoEdit"));
        versoEdit->setGeometry(QRect(30, 100, 311, 20));
        okButton = new QPushButton(centralWidget);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(300, 160, 75, 23));
        labelText = new QLabel(centralWidget);
        labelText->setObjectName(QString::fromUtf8("labelText"));
        labelText->setEnabled(false);
        labelText->setGeometry(QRect(80, 10, 231, 41));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        labelText->setFont(font);
        collectionEdit = new QLineEdit(centralWidget);
        collectionEdit->setObjectName(QString::fromUtf8("collectionEdit"));
        collectionEdit->setGeometry(QRect(30, 210, 311, 21));
        CreateWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CreateWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 22));
        CreateWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CreateWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        CreateWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CreateWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CreateWindow->setStatusBar(statusBar);

        retranslateUi(CreateWindow);

        QMetaObject::connectSlotsByName(CreateWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CreateWindow)
    {
        CreateWindow->setWindowTitle(QApplication::translate("CreateWindow", "CreateWindow", nullptr));
        menuButton->setText(QApplication::translate("CreateWindow", "=", nullptr));
        okButton->setText(QApplication::translate("CreateWindow", "PushButton", nullptr));
        labelText->setText(QApplication::translate("CreateWindow", "Votre carte a bien ete enregistree", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateWindow: public Ui_CreateWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEWINDOW_H
