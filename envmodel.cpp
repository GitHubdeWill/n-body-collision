#include "envmodel.h"


//The default width of the game
int EnvModel::WIDTH = 1024;

//The default height
int EnvModel::HEIGHT = 768;

EnvModel::EnvModel()
{
    generateRandomEnv();

    connect(this, SIGNAL(updateAll()), map, SLOT(updateMap()));

    for (Entity *e : geoObjects) {
        connect(this, SIGNAL(updateAll()), e, SLOT(update()));
    }
}

EnvModel::~EnvModel()
{
    for (int i = 0; i < geoObjects.size(); i++)
    {
        geoObjects.at(i)->deleteLater();
    }

    for (int i = 0; i < initObjects.size(); i++)
    {
        initObjects.at(i)->deleteLater();
    }
    map->deleteLater();
}

void EnvModel::generateRandomEnv()
{
    // Initialize Lines for Map
    QList<QLine*> ws = QList<QLine*>();
    // Order Matters
    ws.append(new QLine(0,0,0,HEIGHT));
    ws.append(new QLine(WIDTH,0,0,0));
    ws.append(new QLine(0,HEIGHT,WIDTH,HEIGHT));
    ws.append(new QLine(WIDTH,HEIGHT,WIDTH,0));
    map = new Map(ws, QRect(0,0,WIDTH,HEIGHT));

    //Initialize Objects
    for (int i = 0; i < 100; i++)
    {
        Ball *e = new Ball(rand() % 500+10, rand() % 500+10, 1, rand() % 10 -5, rand() % 10 -5, 10);
        geoObjects.append(e);
    }
}

bool EnvModel::isColliding(Entity *e1, Entity *e2)
{
    return e1->isCollidingWith(e2);
}

bool EnvModel::doCollision(Entity *e1, Entity *e2)
{
    return e1->doCollidingWith(e2);
}

bool EnvModel::update()
{
    emit updateAll();  // Update position of objects by 1 frame
    emit processAll();  // Calculate status after interations

    // Collision related function
    for (Entity *e : geoObjects)  // Loop for Walls
    {
        Ball* b = dynamic_cast<Ball*>(e);
        if (b)
        {
            QList<QLine*> lines = map->hitWall(b);
            for (QLine *l : lines)
            {
                map->doHitWall(b, l);
            }
        }
    }

    for (int i = 0; i < geoObjects.size()-1; i++)
    {
        for (int j = i+1; j < geoObjects.size(); j++)
        {
            if (geoObjects[i]->isCollidingWith(geoObjects[j]))
            {
                geoObjects[i]->getLabel()->setStyleSheet("QLabel { background-color : blue; color : blue; }");
                geoObjects[j]->getLabel()->setStyleSheet("QLabel { background-color : blue; color : blue; }");
                collidingPairs.push(std::make_pair(geoObjects[i], geoObjects[j]));
            }
        }
    }

    for (std::pair<Entity*, Entity*> p : collidingPairs) {
        p.first->doCollidingWith(p.second);
    }
}

bool EnvModel::reset()
{
    // Free the current list of Objects
    for (int i = 0; i < geoObjects.size(); i++)
    {
        free(geoObjects.at(i));
    }
    // Copy init objects to current objects
    geoObjects = initObjects;
    emit updateAll();
}

Map *EnvModel::getMap() const
{
    return map;
}

void EnvModel::setMap(Map *value)
{
    map = value;
}

QList<Entity *> EnvModel::getGeoObjects() const
{
    return geoObjects;
}

void EnvModel::setGeoObjects(const QList<Entity *> &value)
{
    geoObjects = value;
}

QList<Entity *> EnvModel::getInitObjects() const
{
    return initObjects;
}

void EnvModel::setInitObjects(const QList<Entity *> &value)
{
    initObjects = value;
}

QStack<std::pair<Entity *, Entity *> > EnvModel::getCollidingPairs() const
{
    return collidingPairs;
}

void EnvModel::setCollidingPairs(const QStack<std::pair<Entity *, Entity *> > &value)
{
    collidingPairs = value;
}
