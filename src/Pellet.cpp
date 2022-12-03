#include "Pellet.h"
#include <cmath>


void Pellet::fire(float input_theta, Vector2 input_playerPosition) {
    this->pelletPosition = input_playerPosition;
    this->theta = input_theta;

    pelletVelocity.x = cos(theta) * pelletSpeed;
    pelletVelocity.y = sin(theta) * pelletSpeed;

}

void Pellet::move() {
    delta = GetFrameTime();

    pelletPosition.x += pelletVelocity.x * delta;
    pelletPosition.y += pelletVelocity.y * delta;
}

Vector2 Pellet::getPosition() {
    return pelletPosition;
}

float Pellet::getRadius() {
    return pelletRadius;
}

Vector2 Pellet::getVelocity() {
    return pelletVelocity;
}

void Pellet::setVelocity_x(float input_velocity_x) {
    this->pelletVelocity.x = input_velocity_x;
}

void Pellet::setVelocity_y(float input_velocity_y) {
    this->pelletVelocity.y = input_velocity_y;
}
