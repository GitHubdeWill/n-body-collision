#include "entity.h"

Entity::Entity(float posX, float posY, float w, float vecX, float vecY)
{
    x = posX;
    y = posY;
    weight = w;
    velocity = QVector2D(vecX, vecY);
}

QLabel *Entity::getLabel() const
{
    return label;
}

void Entity::setLabel(QLabel *value)
{
    label = value;
}

QVector2D Entity::getVelocity() const
{
    return velocity;
}

void Entity::setVelocity(const QVector2D &value)
{
    velocity = value;
}

float Entity::getWeight() const
{
    return weight;
}

void Entity::setWeight(float value)
{
    weight = value;
}

float Entity::getX() const
{
    return x;
}

void Entity::setX(float value)
{
    x = value;
}

float Entity::getY() const
{
    return y;
}

void Entity::setY(float value)
{
    y = value;
}

bool Entity::update()
{
    qDebug() << "update" << x << y;
    // Move 1 velocity unit from current position
    x += velocity.x();
    y += velocity.y();
    label->setGeometry(x, y, 10, 10);
}

