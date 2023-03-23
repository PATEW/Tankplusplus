#include "Enemy.h"


Enemy::Enemy(float x, float y, Color color, int radius) {
    this->enemyPosition.x = x;
    this->enemyPosition.y = y;
    setColor(color);
    this->radius = radius;
}


// g&s
void Enemy::setColor(Color input_color) {
    this->color = input_color;
}

Color Enemy::getColor() {
    return color;
}

float Enemy::getX() {
    return enemyPosition.x;
}

float Enemy::getY() {
    return enemyPosition.y;
}

int Enemy::getRadius() {
    return radius;
}
