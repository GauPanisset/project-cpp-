#include "mainwindow.h"
#include "ui_mainwindow.h"

#define MYCARDS "/MemoryCards/save/cards.xml"
#define MYPLAYS "/MemoryCards/save/plays.xml"

bool setCombobox(QString filePath, QComboBox *comboBox)
{
    QDir relativePath = QDir::current();
    QString absolutePath = relativePath.absolutePath();
    absolutePath += filePath;

    TiXmlDocument doc(absolutePath.toStdString().c_str());
    if (doc.LoadFile())
    {
        bool itemAdded = false;
        TiXmlElement *root = doc.RootElement();
        TiXmlElement *levelOneEl = root->FirstChildElement();
        while (levelOneEl)
        {
            if (comboBox->findText(levelOneEl->Attribute("name"))<0)
            {
                comboBox->addItem(levelOneEl->Attribute("name"));
                itemAdded = true;
            }
            levelOneEl = levelOneEl->NextSiblingElement();
        }
        return itemAdded;
    }
    else
    {
        std::cout<<"Error : "<<filePath.toStdString()<<" ("<<doc.ErrorDesc()<<")"<<std::endl;
        return false;
    }
}

CardSet loadCards(QString collection){
    CardSet resSet;

    QDir relativePath = QDir::current();
    QString absolutePath = relativePath.absolutePath();
    QString savePath(MYCARDS);
    absolutePath += savePath;

    TiXmlDocument doc(absolutePath.toStdString().c_str());
    if (doc.LoadFile())
    {
        TiXmlElement *root = doc.RootElement();
        TiXmlElement *collectionEl = root->FirstChildElement();
        while (collectionEl && collectionEl->Attribute("name")!=collection)
        {
            collectionEl = collectionEl->NextSiblingElement();
        }
        if (collectionEl)
        {
            TiXmlElement *cardEl = collectionEl->FirstChildElement();
            while (cardEl)
            {
                int id;
                cardEl->Attribute("id", &id);
                resSet.insert(new Card(id));
                cardEl = cardEl->NextSiblingElement();
            }
            return resSet;
        }
        else
        {
            std::cout<<"Error : no collection found"<<std::endl;
            return resSet;
        }
    }
    else {
        std::cout<<"Error : "<<absolutePath.toStdString()<<" ("<<doc.ErrorDesc()<<")"<<std::endl;
        return resSet;
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pPlayWindow = new PlayWindow();
    pCreateWindow = new CreateWindow();

    //Ceci permet de contourner les problèmes de Path liée au build.
    QDir relativePath = QDir::current();
    while(relativePath.absolutePath().contains("/build-MemoryCards"))
    {
        relativePath.setCurrent("../");
        relativePath = QDir::current();
    }

    //Remplissage des comboBox.
    if (!setCombobox(QString(MYPLAYS), ui->nameComboBox))
    {
        std::cout<<"Error: no game found"<<std::endl;
    }
    if (!setCombobox(QString(MYCARDS), ui->collectionComboBox))
    {
        std::cout<<"Error: no collection found"<<std::endl;
    }

    QObject::connect(ui->playButton, &QPushButton::clicked, this, &MainWindow::switchPlayWindow);
    QObject::connect(pPlayWindow, &PlayWindow::returnToMainWindow, this, &MainWindow::switchPlayWindow);

    QObject::connect(ui->createButton, &QPushButton::clicked, this, &MainWindow::switchCreateWindow);
    QObject::connect(pCreateWindow, &CreateWindow::returnToMainWindow, this, &MainWindow::switchCreateWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::switchPlayWindow()
{
    if (this->isVisible())
    {
        this->hide();

        QString name;
        Play *pPlay;

        if (ui->tabSettings->currentIndex() == 0)
        {
            name = ui->nameEdit->text();
            int gameMode = ui->buttonImmediat->isChecked() ? 1 : 0;
            if (gameMode == 1)
            {
                pPlayWindow->activateButton(true);
            }
            else
            {
                pPlayWindow->activateButton(false);
            }
            QString collection = ui->collectionComboBox->currentText();
            pPlay = new Play(name.toStdString(), loadCards(collection), gameMode);
        }
        else
        {
            name = ui->nameComboBox->currentText();
            pPlay = new Play(name.toStdString());
            if (pPlay->getMode() == 1)
            {
                pPlayWindow->activateButton(true);
            }
            else
            {
                pPlayWindow->activateButton(false);
            }
        }
        pPlayWindow->show();
        if (pPlay->numberOfCards()>0)
        {
            pPlayWindow->startPlay(pPlay);
        }
        else
        {
            std::cout<<"Can't play with 0 cards"<<std::endl;
        }
    }
    else {
        setCombobox(QString(MYPLAYS), ui->nameComboBox);
        pPlayWindow->hide();
        this->show();
    }
}

void MainWindow::switchCreateWindow()
{
    if (this->isVisible())
    {
        this->hide();
        pCreateWindow->show();
    }
    else {
        setCombobox(QString(MYCARDS), ui->collectionComboBox);
        pCreateWindow->hide();
        this->show();
    }
}


