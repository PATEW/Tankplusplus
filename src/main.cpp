#include "../include/raylib.h"


int main(void)
{
    const int screenWidth = 1600;
    const int screenHeight = 900;


    InitWindow(screenWidth, screenHeight, "Tank Game");

    Vector2 playerPosition = {(float)screenWidth / 2, (float)screenHeight / 2 };
    Vector2 cursorPosition = {-100.0f, -100.0f };


    Color playerColor = MOSSGREEN;
    Color cursorColor = GHOSTLYLIME;

    HideCursor();                       // Hide cursor (replaced by in-game cursor)
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second


    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update ===
        //----------------------------------------------------------------------------------
        // Keys
        if (IsKeyDown(KEY_D)) playerPosition.x += 2.0f;
        if (IsKeyDown(KEY_A)) playerPosition.x -= 2.0f;
        if (IsKeyDown(KEY_W)) playerPosition.y -= 2.0f;
        if (IsKeyDown(KEY_S)) playerPosition.y += 2.0f;
        // Mouse
        cursorPosition = GetMousePosition();
        //----------------------------------------------------------------------------------


        // Draw ===
        //----------------------------------------------------------------------------------
        BeginDrawing();

        // Background
        ClearBackground({ 223, 185, 122, 255 });

        // Objects
        DrawText("Tank Game", 190, 50, 50, BLACK);
        DrawCircleV(playerPosition, 50, playerColor);
        DrawCircleV(cursorPosition, 40, cursorColor);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}