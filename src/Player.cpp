#include "Player.h"
#include "Pellet.h"
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void Player::checkMovement() {
    // Keys
    if (IsKeyDown(KEY_D)) playerPosition.x += 2.0f;
    if (IsKeyDown(KEY_A)) playerPosition.x -= 2.0f;
    if (IsKeyDown(KEY_W)) playerPosition.y -= 2.0f;
    if (IsKeyDown(KEY_S)) playerPosition.y += 2.0f;
}


std::vector<Pellet> Player::checkPellet(Vector2 input_cursorPosition, Vector2 input_screenDimensions, std::vector<Block> blocksVec) {

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Pellet pellet;

        Vector2 clickPosition = {(input_cursorPosition.x - playerPosition.x), ((input_cursorPosition.y - playerPosition.y))};
        pellet.fire(atan2f(clickPosition.y, clickPosition.x), this->playerPosition);

        pelletVec.push_back(pellet);
    }

    for (int i = 0; i < pelletVec.size(); i++) {
        pelletVec[i].move();

        // out of bounds
        if (pelletVec[i].getPosition().x > input_screenDimensions.x || pelletVec[i].getPosition().x < 0 || pelletVec[i].getPosition().y > input_screenDimensions.y ||
                    pelletVec[i].getPosition().y < 0) {
            pelletVec.erase(pelletVec.begin() + i);
        }

        // collision with blocks
        for (Block block : blocksVec) {
            if (CheckCollisionCircleRec(pelletVec[i].getPosition(), pelletVec[i].getRadius(), block)) {
                if (CheckCollisionPointRec({pelletVec[i].getPosition().x + pelletVec[i].getRadius(), pelletVec[i].getPosition().y}, block)) {
                    pelletVec[i].setVelocity_x(pelletVec[i].getVelocity().x * -1);
                }
                if (CheckCollisionPointRec({pelletVec[i].getPosition().x - pelletVec[i].getRadius(), pelletVec[i].getPosition().y}, block)) {
                    pelletVec[i].setVelocity_x(pelletVec[i].getVelocity().x * -1);
                }
                if (CheckCollisionPointRec({pelletVec[i].getPosition().x, pelletVec[i].getPosition().y + pelletVec[i].getRadius()}, block)) {
                    pelletVec[i].setVelocity_y(pelletVec[i].getVelocity().y * -1);
                }
                if (CheckCollisionPointRec({pelletVec[i].getPosition().x, pelletVec[i].getPosition().y - pelletVec[i].getRadius()}, block)) {
                    pelletVec[i].setVelocity_y(pelletVec[i].getVelocity().y * -1);
                }
            }
        }

    }
    return pelletVec;
}



// Get & Set ============================================

Vector2 Player::getPosition() {
    return playerPosition;
}

void Player::setPosition(Vector2 newPosition) {
    this->playerPosition = newPosition;
}

std::vector<Pellet> Player::getPelletVector() {
    return pelletVec;
}

void Player::setColors(Color input_player_color, Color input_cursor_color) {
    this->playerColor = input_player_color;
    this->cursorColor = input_cursor_color;
}

Color Player::getPlayerColor() {
    return playerColor;
}

Color Player::getCursorColor() {
    return cursorColor;
}
