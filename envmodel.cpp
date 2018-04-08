#include "envmodel.h"

EnvModel::EnvModel()
{

}

EnvModel::~EnvModel()
{

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
