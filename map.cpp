#include "map.h"

QRect Map::getBoundary() const
{
    return boundary;
}

void Map::setBoundary(const QRect &value)
{
    boundary = value;
}

QList<QLine> Map::getWalls() const
{
    return walls;
}

void Map::setWalls(const QList<QLine> &value)
{
    walls = value;
}

bool Map::update()
{

}

Map::Map(QObject *parent) : QObject(parent)
{

}
