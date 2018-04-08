#ifndef BALL_H
#define BALL_H

#include <typeinfo>

#include "entity.h"

class Ball : public virtual Entity
{
public:
    Ball();

    bool isCollidingWith(Entity* other);
    bool doCollidingWith(Entity* other);
};

#endif // BALL_H
