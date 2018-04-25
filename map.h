#ifndef MAP_H
#define MAP_H

#include <QObject>
#include <QRect>
#include <QList>
#include <QLine>

#include "entity.h"
#include "ball.h"

// Store bounds and walls in the map
class Map : public QObject {
    Q_OBJECT

    QRect boundary;  // The boundary of the map
    QList<QLine*> walls; // All walls represents by lines, not mutable

public:
    Map(QList<QLine*> lines, QRect bound);
    ~Map();

    QList<QLine*> hitWall(Entity* obj);  // Return all lines that collides
    // Given colliding walls, modify obj state return succeed status
    bool doHitWall(Entity* obj, QLine* w);

    QRect getBoundary() const;
    void setBoundary(const QRect &value);

    QList<QLine *> getWalls() const;
    void setWalls(const QList<QLine *> &value);

signals:

public slots:
    bool updateMap();
};

#endif // MAP_H
