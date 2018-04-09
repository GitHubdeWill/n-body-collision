#include "map.h"

bool Map::updateMap()
{
    // TODO: Update the whole map.
}

QRect Map::getBoundary() const
{
    return boundary;
}

void Map::setBoundary(const QRect &value)
{
    boundary = value;
}

QList<QLine *> Map::getWalls() const
{
    return walls;
}

void Map::setWalls(const QList<QLine *> &value)
{
    walls = value;
}

Map::Map(QList<QLine*> lines, QRect bound)
{
    walls = QList<QLine*>(lines);
    boundary = bound;
}

Map::~Map()
{
    for (QLine* l : walls)
    {
        free(l);
    }
}

QList<QLine*> Map::hitWall(Entity *obj)
{
    Ball* ball = dynamic_cast<Ball*>(obj);
    QList<QLine*> ret = QList<QLine*>();
    if (ball != nullptr)
    {
        for (QLine* l : walls)
        {
            // TODO: Check collide on all lines
        }
    }
    return ret;
}

bool Map::doHitWall(Entity *obj, QList<QLine*> w)
{
    Ball* ball = dynamic_cast<Ball*>(obj);
    if (ball != nullptr)
    {
        // TODO: Calculate and update obj status
    }
    return false;
}
