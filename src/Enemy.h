#ifndef TANKPLUSPLUS_ENEMY_H
#define TANKPLUSPLUS_ENEMY_H


#include "raylib.h"
#include "Pellet.h"
#include <vector>

class Enemy {
private:
    Vector2 enemyPosition;
    std::vector<Pellet> pelletVec;
    Color color;
    int radius;
public:
    Enemy(float x, float y, Color color, int radius);

    void setColor(Color input_color);
    Color getColor();
    float getX();
    float getY();
    int getRadius();
};


#endif //TANKPLUSPLUS_ENEMY_H
