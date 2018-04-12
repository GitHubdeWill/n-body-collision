#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(EnvModel::WIDTH, EnvModel::HEIGHT);
    setWindowTitle("N-Body-Collision");

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
        lbl->setScaledContents(true);
        lbl->setGeometry(b->getX()-b->getRadius(),
                         b->getY()-b->getRadius(),
                         b->getRadius()*2,
                         b->getRadius()*2);
        lbl->setFixedHeight( b->getRadius()*2);
        lbl->setFixedWidth( b->getRadius()*2);
        lbl->setText("O");
        lbl->setStyleSheet("QLabel { border: 0px solid green; }");
        b->setLabel(lbl);
        lbl->show();
    }
}

void MainWindow::timerHit()
{
    model.update();
}
