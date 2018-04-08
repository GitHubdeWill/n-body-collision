#ifndef ENVMODEL_H
#define ENVMODEL_H

#include <QObject>
#include <QList>
#include <QRect>
#include <utility>
#include <QStack>

#include "map.h"
#include "entity.h"

class EnvModel : public QObject
{
    Q_OBJECT

    Map* map;  // Map of the Environment
    QList<Entity*> geoObjects;  // Store all objects presented in the map
    QList<Entity*> initObjects;  // Store　init state for Reset

    QStack<std::pair<Entity*, Entity*>> collidingPairs;  //Stack of pairs that are colliding

public:
    EnvModel();
    ~EnvModel();

    bool isColliding(Entity* e1, Entity* e2);  // Check if 2 obj is colliding

    bool doCollision(Entity* e1, Entity* e2);  // Do Collision and update velocity


    Map *getMap() const;
    void setMap(Map *value);

    QList<Entity *> getGeoObjects() const;
    void setGeoObjects(const QList<Entity *> &value);

    QList<Entity *> getInitObjects() const;
    void setInitObjects(const QList<Entity *> &value);

    QStack<std::pair<Entity *, Entity *> > getCollidingPairs() const;
    void setCollidingPairs(const QStack<std::pair<Entity *, Entity *> > &value);

signals:
    void updateAll();  // Update the world by one frame
    void resetAll();

public slots:
};

#endif // ENVMODEL_H
