#ifndef ENTITY_H
#define ENTITY_H

#include <QObject>
#include <QVector2D>
#include <QLabel>
#include <QRect>
#include <QDebug>

class Entity : public QObject  // Represent a physical object of the map
{
    Q_OBJECT

    float x;
    float y;
    float weight;
    QVector2D velocity;
    QRect bound;  // The bounding rect of object

    QLabel* label;  // The label representation of the entity

public:
    Entity(float posX, float posY, float w, float vecX, float vecY);

    // Check if this entity is colliding with another.
    virtual bool isCollidingWith(Entity* other) = 0;
    // Do collision on colliding object, return succeed status
    virtual bool doCollidingWith(Entity* other) = 0;

    QLabel *getLabel() const;
    void setLabel(QLabel *value);

    QVector2D getVelocity() const;
    void setVelocity(const QVector2D &value);

    float getWeight() const;
    void setWeight(float value);

    float getX() const;
    void setX(float value);

    float getY() const;
    void setY(float value);

signals:

public slots:
    bool update();
};

#endif // ENTITY_H
