#ifndef ENTITY_H
#define ENTITY_H

#include <QObject>
#include <QPointF>
#include <QVector2D>
#include <QLabel>

class Entity : public QObject  // Represent a physical object of the map
{
    Q_OBJECT

    QPointF position;
    float weight;
    QVector2D velocity;

    QLabel* label;  // The label representation of the entity

public:
    Entity();

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

    QPointF getPosition() const;
    void setPosition(const QPointF &value);

signals:

public slots:
    bool update();
};

#endif // ENTITY_H
