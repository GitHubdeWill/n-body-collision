#ifndef MAP_H
#define MAP_H

#include <QObject>
#include <QRect>
#include <QList>
#include <QLine>

#include <entity.h>

class Map : public QObject  // Store bounds and walls in the map
{
    Q_OBJECT

    QRect boundary;  // The boundary of the map
    QList<QLine> walls; // All walls represents by lines, not mutable

public:
    explicit Map(QObject *parent = nullptr);

    bool hitWall(Entity* obj);
    bool doHitWall(Entity* obj);

    QRect getBoundary() const;
    void setBoundary(const QRect &value);

    QList<QLine> getWalls() const;
    void setWalls(const QList<QLine> &value);

signals:

public slots:
    bool update();
};

#endif // MAP_H
