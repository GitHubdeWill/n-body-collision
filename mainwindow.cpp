#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initGUI();

    fps = 60;

    QTimer *timer = new QTimer(this);
    timer->setInterval(1000 / fps);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerHit()));
    timer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initGUI()
{
    //Clear all of the current labels from the window
    QObjectList objects = children();
    for(QObject* object : objects) {
        QLabel* lbl = dynamic_cast<QLabel*>(object);
        if(lbl) { lbl->deleteLater(); }
    }

    auto entities = model.getGeoObjects();
    for(int i = 0; i < entities.size(); i++)
    {
        Ball* b = dynamic_cast<Ball*>(entities[i]);
        if (b) {
            qDebug() << "Making Label";
            makeLabel(entities[i]);
            continue;
        }
    }
}

void MainWindow::makeLabel(Entity *e)
{
    Ball* b = dynamic_cast<Ball*>(e);
    if (b) {
        QLabel* lbl = new QLabel(this);
        lbl->setGeometry(b->getX()-b->getRadius(),
                         b->getY()-b->getRadius(),
                         b->getRadius(),
                         b->getRadius());
        lbl->setStyleSheet("QLabel { background-color : red; color : blue; }");
        b->setLabel(lbl);
        lbl->show();
    }
}

void MainWindow::timerHit()
{
    model.update();
}
