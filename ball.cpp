#include "ball.h"

float Ball::getRadius() const {
    return radius;
}

void Ball::setRadius(float value) {
    radius = value;
}

int Ball::getStuck() const {
    return stuck;
}

void Ball::setStuck(int value) {
    stuck = value;
}

Ball::Ball(float posX, float posY, float w, float vecX, float vecY, float r)
    : Entity(posX, posY, w, vecX, vecY) {
    radius = r;
    stuck = 0;
}

bool Ball::isCollidingWith(Entity *other) {
    Ball* ball = dynamic_cast<Ball*>(other);
    if (ball != nullptr) {
        float distancex = pow((ball->getX() - getX()), 2);
        float distancey = pow((ball->getY() - getY()), 2);

        QVector2D disVec = QVector2D(ball->getX() - getX(), ball->getY() - getY());
        disVec.normalize();

        float dis = sqrt(distancex + distancey);
        if (dis <= ball->getRadius() + getRadius()) {
            float minDis = ball->getRadius() + this->getRadius();
            ball->setX(this->getX() + disVec.x() * minDis);
            ball->setY(this->getY() + disVec.y() * minDis);
            return true;
        }
    }
    return false;
}

bool Ball::doCollidingWith(Entity *other) {
    Ball* ball = dynamic_cast<Ball*>(other);
    if (ball != nullptr) {
        // TODO: Hit Ball
        QVector2D v1 = *(this->getVelocity());
        QVector2D v2 = *(other->getVelocity());
        QVector2D x1 = QVector2D(this->getX(), this->getY());
        QVector2D x2 = QVector2D(other->getX(), other->getY());
        float m1 = this->getWeight();
        float m2 = other->getWeight();

        QVector2D *v1p = new QVector2D(v1 - ((2 * m2 / (m1 + m2)) * QVector2D::dotProduct((v1 - v2), (x1 - x2))) / (x1 - x2).lengthSquared() * (x1 - x2));
        QVector2D *v2p = new QVector2D(v2 - ((2 * m1 / (m1 + m2)) * QVector2D::dotProduct((v2 - v1), (x2 - x1))) / (x2 - x1).lengthSquared() * (x2 - x1));

        this->setVelocity(v1p);
        other->setVelocity(v2p);
    }
    return false;
}
