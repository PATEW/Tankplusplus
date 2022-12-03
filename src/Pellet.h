#ifndef TANKPLUSPLUS_PELLET_H
#define TANKPLUSPLUS_PELLET_H


#include "raylib.h"

class Pellet {
private:
    Vector2 pelletPosition;
    Vector2 pelletVelocity;
    int pelletSpeed = 500;
    float pelletRadius = 20;
    float theta = 0;
    float delta = 0;
public:
    void fire(float input_theta, Vector2 input_playerPosition);
    void move();
    Vector2 getPosition();
    float getRadius();
    Vector2 getVelocity();
    void setVelocity_x(float input_velocity_x);
    void setVelocity_y(float input_velocity_y);
};


#endif //TANKPLUSPLUS_PELLET_H
