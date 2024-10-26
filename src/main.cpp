#include <iostream>
#include "raylib-cpp.hpp"

int main() 
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    const int targetFPS = 60;
    raylib::Color textColor = raylib::Color::Blue();
    raylib::Window window(screenWidth, screenHeight, "raylib window");
    window.SetTargetFPS(targetFPS);

    raylib::Camera camera(
        raylib::Vector3(10.0f, 10.0f, 10.0f),
        raylib::Vector3(),
        raylib::Vector3(0.0f, 1.0f, 0.0f),
        45.0f,
        CAMERA_PERSPECTIVE);
    
    Vector3 cubePosition;
    Vector2 cubeScreenPosition;
    
    // Main game loop
    while(!window.ShouldClose())
    {
        camera.Update(CAMERA_THIRD_PERSON);

        cubeScreenPosition = GetWorldToScreen(Vector3{cubePosition.x, cubePosition.y + 2.5f, cubePosition.z}, camera);

        // Draw
        window.BeginDrawing();
        {
            window.ClearBackground(RAYWHITE);
            
            camera.BeginMode();
            {
                DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
                DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);

                DrawGrid(10, 1.0f);
            }
            camera.EndMode();
            
            raylib::DrawText("Enemy: 100 / 100", 
                cubeScreenPosition.x - MeasureText("Enemy: 100/100", 20) / 2,
                cubeScreenPosition.y, 20, BLACK);
            raylib::DrawText("Text is always on top of the cube",
                (screenWidth - MeasureText("Text is always on top of the cube", 20)) / 2,
                25, 20, GRAY);
        }
        window.EndDrawing();
    }

    return 0;
}