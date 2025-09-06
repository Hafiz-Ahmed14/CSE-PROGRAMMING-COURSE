// This code is only for Mackbook User

#include "raylib.h"
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    int screenHeight = 600;
    int screenWidth = 800;

    InitWindow(screenWidth, screenHeight, "DDA Line Drawing");

    int x1 = 100, y1 = 120;
    int x2 = 400, y2 = 500;

    int maxy = screenHeight - 1;

    // Main game loop
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        // DDA Algorithm implementation
        float dx = x2 - x1;
        float dy = y2 - y1;
        float steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

        float xIncrement = dx / steps;
        float yIncrement = dy / steps;

        float x = x1;
        float y = y1;

        for (int i = 0; i <= steps; i++)
        {
            DrawPixel((int)x, maxy - (int)y, RED);
            x += xIncrement;
            y += yIncrement;
        }

        DrawText(TextFormat("(%d,%d) to (%d,%d) - DDA Algorithm", x1, y1, x2, y2), 10, 10, 20, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
