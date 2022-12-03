#include "Block.h"


Block::Block(float x, float y, float width, float height, Color color) {
    this->x = x;
    this->y = y;
    setWidth(width);
    setHeight(height);
    setColor(color);
}


// g&s
void Block::setWidth(float input_width) {
    this->width = input_width;
}

float Block::getWidth() {
    return width;
}

void Block::setHeight(float input_height) {
    this->height = input_height;
}

float Block::getHeight() {
    return height;
}

void Block::setColor(Color input_color) {
    this->color = input_color;
}

Color Block::getColor() {
    return color;
}

float Block::getX() {
    return x;
}

float Block::getY() {
    return y;
}
