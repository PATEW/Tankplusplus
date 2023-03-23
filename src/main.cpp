#include <cmath>
#include "../include/raylib.h"
#include "Player.h"
//#include "Block.h"
#include "BlockGenerator.h"
#include "EnemyGenerator.h"
#include "iostream"



int main(void)
{
    //Initialization ===
    Vector2 screenDimensions = {1600, 900};
    InitWindow(screenDimensions.x, screenDimensions.y, "Tankplusplus");

    Texture2D texture = LoadTexture("../resources/images/raylib_logo.png");

    Vector2 cursorPosition = {-100.0f, -100.0f };
    HideCursor();                       // Hide cursor (replaced by in-game cursor)
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    //Players ===
    Player player1;
    player1.setPosition({(float)screenDimensions.x / 2, (float)screenDimensions.y / 2 });
    player1.setColors(GREEN, RAYWHITE);


    //Level ===
    int selectedLevel = 1;


    //Block Generator
    BlockGenerator blockGenerator;
    std::vector<Block> blocksVec = blockGenerator.createLevel(selectedLevel, screenDimensions);

    //Enemy Generator
    std::vector<Enemy>* enemiesVecPtr = EnemyGenerator::createEnemies(selectedLevel, screenDimensions);

    Vector2 testBlock_position = {(float)screenDimensions.x / 2, (float)screenDimensions.y / 3};
    //Rectangle frameRec = { 0.0f, 0.0f, (float)testBlock.width, (float)testBlock.height };

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update ===
        //----------------------------------------------------------------------------------
        // Important values
        cursorPosition = GetMousePosition();
        //----------------------------------------------------------------------------------
        // Handle Players
        player1.checkMovement();
        //----------------------------------------------------------------------------------
        // Handle Pellets
        std::vector<Pellet> p1PelVec = player1.checkPellet(cursorPosition, screenDimensions, blocksVec, enemiesVecPtr);


        // Draw ===
        //----------------------------------------------------------------------------------
        BeginDrawing();

        // Background
        ClearBackground({ 223, 185, 122, 255 });

        // Blocks       
        for (int i = 0; i < static_cast<int>(blocksVec.size()); i++) {
            DrawRectangleV({blocksVec[i].getX(), blocksVec[i].getY()}, {blocksVec[i].getWidth(), blocksVec[i].getHeight()}, blocksVec[i].getColor());
        }

        // Enemies
        for (int i = 0; i < static_cast<int>(enemiesVecPtr->size()); i++) {
            DrawCircleV({enemiesVecPtr->at(i).getX(), enemiesVecPtr->at(i).getY()}, 50, enemiesVecPtr->at(i).getColor());
        }

        // Objects
        //DrawText("Tankplusplus", 190, 50, 50, BLACK);
        DrawCircleV(player1.getPosition(), 50, player1.getPlayerColor());
        DrawCircleV(cursorPosition, 40, player1.getCursorColor());


        for (int i = 0; i < static_cast<int>(p1PelVec.size()); i++) {
            DrawCircleV(p1PelVec[i].getPosition(), p1PelVec[i].getRadius(), WHITE);
        }

        DrawLine(player1.getPosition().x, player1.getPosition().y, cursorPosition.x, cursorPosition.y, player1.getCursorColor());

        //Image test
        DrawTexture(texture, screenDimensions.x - texture.width, screenDimensions.y - texture.height, WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(texture);
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}