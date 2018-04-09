#include "envmodel.h"

EnvModel::EnvModel()
{

}

EnvModel::~EnvModel()
{
    for (int i = 0; i < geoObjects.size(); i++)
    {
        free(geoObjects.at(i));
    }

    for (int i = 0; i < initObjects.size(); i++)
    {
        free(initObjects.at(i));
    }
    free(map);
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
