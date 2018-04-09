#include "ball.h"

float Ball::getRadius() const
{
    return radius;
}

void Ball::setRadius(float value)
{
    radius = value;
}

Ball::Ball(float posX, float posY, float w, float vecX, float vecY, float r)
    : Entity(posX, posY, w, vecX, vecY)
{
    radius = r;
}

bool Ball::isCollidingWith(Entity *other)
{
    Ball* ball = dynamic_cast<Ball*>(other);
    if (ball != nullptr)
    {
        float distancex = pow((ball->getX() - getX()), 2);
        float distancey = pow((ball->getY() - getY()), 2);

        float dis = sqrt(distancex - distancey);
        if (dis <= ball->getRadius() + getRadius()) return true;
    }
    return false;
}

bool Ball::doCollidingWith(Entity *other)
{
    Ball* ball = dynamic_cast<Ball*>(other);
    if (ball != nullptr)
    {

    }
    return false;
}
