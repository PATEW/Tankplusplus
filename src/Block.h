#ifndef TANKPLUSPLUS_BLOCK_H
#define TANKPLUSPLUS_BLOCK_H


#include "raylib.h"

class Block : public Rectangle {
private:
    Color color;
public:
    Block(float x, float y, float width, float height, Color color);

    void setWidth(float input_width);
    float getWidth();
    void setHeight(float input_height);
    float getHeight();
    void setColor(Color input_color);
    Color getColor();
    float getX();
    float getY();
};


#endif //TANKPLUSPLUS_BLOCK_H
