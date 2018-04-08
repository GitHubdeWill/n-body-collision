#include "entity.h"

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

QPointF Entity::getPosition() const
{
    return position;
}

void Entity::setPosition(const QPointF &value)
{
    position = value;
}

bool Entity::update()
{

}

Entity::Entity()
{

}
