#include "map.h"

bool Map::updateMap()
{
    // TODO: Update the whole map.
    return false;
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
            float x1 = l->x1();
            float x2 = l->x2();
            float y1 = l->y1();
            float y2 = l->y2();
            float x = ball->getX();
            float y = ball->getY();
            float A = x - x1;
            float B = y - y1;
            float C = x2 - x1;
            float D = y2 - y1;

            float dist = abs(A * D - C * B) / sqrt(C * C + D * D);
            if (dist <= ball->getRadius())
            {
                if (dist < ball->getRadius())
                {

                    QVector2D wall = QVector2D(l->p2().x()-l->p1().x(), l->p2().y()-l->p1().y());
                    QVector2D normal = QVector2D(-1*wall.y(), wall.x());
                    normal.normalize();
                    ball->setX(ball->getX() - normal.x());
                    ball->setY(ball->getY() - normal.y());
                }
                ret.append(l);
            }
        }
    }
    return ret;
}

bool Map::doHitWall(Entity *obj, QLine* w)
{
    Ball* ball = dynamic_cast<Ball*>(obj);
    if (ball != nullptr)
    {
        // Calculate and update obj status
        QVector2D origin = *(ball->getVelocity());
        QVector2D wall = QVector2D(w->p2().x()-w->p1().x(), w->p2().y()-w->p1().y());
        QVector2D normal = QVector2D(-1*wall.y(), wall.x());
        normal.normalize();

        QVector2D *reflect = new QVector2D(origin - 2 * QVector2D::dotProduct(origin, normal) * normal);

        ball->setVelocity(reflect);
        return true;
    }
    return false;
}
