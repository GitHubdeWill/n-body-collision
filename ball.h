#ifndef BALL_H
#define BALL_H

#include "math.h"

#include "entity.h"

class Ball : public virtual Entity {
    float radius;
    int stuck;

public:
    explicit Ball (float posX, float posY, float w, float vecX, float vecY, float r);

    bool isCollidingWith(Entity* other);
    bool doCollidingWith(Entity* other);

    float getRadius() const;
    void setRadius(float value);
    int getStuck() const;
    void setStuck(int value);
};

#endif // BALL_H
