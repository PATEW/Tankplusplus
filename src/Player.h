#ifndef TANKPLUSPLUS_PLAYER_H
#define TANKPLUSPLUS_PLAYER_H


#include "raylib.h"
#include "Pellet.h"
#include "Block.h"
#include "Enemy.h"
#include <vector>

class Player {
private:
    Vector2 playerPosition;
    std::vector<Pellet> pelletVec;
    Color playerColor;
    Color cursorColor;
public:
    void checkMovement();
    std::vector<Pellet> checkPellet(Vector2 input_cursorPosition, Vector2 input_screenDimensions, std::vector<Block> blocksVec, std::vector<Enemy>*& enemiesVec);

    // g&s
    Vector2 getPosition();
    void setPosition(Vector2 newPosition);
    std::vector<Pellet> getPelletVector();
    void setColors(Color input_player_color, Color input_cursor_color);
    Color getPlayerColor();
    Color getCursorColor();

};


#endif //TANKPLUSPLUS_PLAYER_H
