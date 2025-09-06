//This code is only for MacBook users

#include "raylib.h"
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    int screenHeight = 600;
    int screenWidth = 800;

    InitWindow(screenWidth, screenHeight, "Draw Line");

    int x1 = 100, y1 = 120;
    int x2 = 400, y2 = 500;

    int maxy = screenHeight - 1;

    int xdiff = (x2 - x1);
    int ydiff = (y2 - y1);
    float m = (float)ydiff / xdiff;

    float b = y1 - m * x1;

    // Main game loop
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        if (abs(m) <= 1)
        {

            for (float x = x1; x <= x2; x++)
            {
                float y = m * x + b;
                DrawPixel((int)x, maxy - (int)y, RED);
            }
        }
        else
        {
            for (float y = y1; y <= y2; y++)
            {
                float x = (y - b) / m;
                DrawPixel((int)x, maxy - (int)y, RED);
            }
        }

        DrawText(TextFormat("(%d,%d) to (%d,%d)", x1, y1, x2, y2), 10, 10, 20, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
