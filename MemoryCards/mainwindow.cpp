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
            comboBox->addItem(levelOneEl->Attribute("name"));
            levelOneEl = levelOneEl->NextSiblingElement();
            itemAdded = true;
        }
        return itemAdded;
    }
    else
    {
        std::cout<<"Error : "<<filePath.toStdString()<<" ("<<doc.ErrorDesc()<<")"<<std::endl;
        return false;
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
        std::cout<<"Error : no game found"<<std::endl;
    }
    if (!setCombobox(QString(MYCARDS), ui->collectionComboBox))
    {
        std::cout<<"Error : no collection found"<<std::endl;
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

        Card *cardList[3] = {nullptr, nullptr, nullptr};
        for (int i = 0; i < 3; i++)
        {
            cardList[i] = new Card("Test", i+1);
        }
        std::string gameMode;
        //if (ui->tabSettings->currentIndex() == 0)
        //{
            Play *pPlay = new Play("testGame", cardList, 3, 0);
       // }
        //else {

       // }
        pPlayWindow->startPlay(pPlay);

        pPlayWindow->show();

    }
    else {
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
        pCreateWindow->hide();
        this->show();
    }
}


