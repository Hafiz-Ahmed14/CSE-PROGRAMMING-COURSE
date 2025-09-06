// This code is for only mackbook users
#include "raylib.h"
#include <iostream>
#include <cmath>

using namespace std;

const int screenWidth = 800;
const int screenHeight = 800;

void DrawLineBresenham(int x1, int y1, int x2, int y2, Color color)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true)
    {
        DrawPixel(x1, y1, color);

        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

int main()
{
    InitWindow(screenWidth, screenHeight, "Bresenham Line Algorithm");

    // Line start and end points
    int startX = 100, startY = 100;
    int endX = 700, endY = 700;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        // Draw line using Bresenham's algorithm
        DrawLineBresenham(startX, startY, endX, endY, YELLOW);

        // Display info
        DrawText("Line using Bresenham's Algorithm", 50, 10, 20, WHITE);
        DrawText(TextFormat("From (%d,%d) to (%d,%d)", startX, startY, endX, endY), 50, 40, 20, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
