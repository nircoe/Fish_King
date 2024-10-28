#include <cmath>
#include <algorithm>
#include "raylib-cpp.hpp"
#include "colors.hpp"

void HandleCharacterMovement(raylib::Vector2& characterPos)
{
    const float addition = 3.0f;
    const float diagonalMultiply = sqrtf(4.5f) / addition;
    raylib::Vector2 additionV = raylib::Vector2();
    additionV.x = (IsKeyDown(KEY_RIGHT)) ? 
                    addition : (IsKeyDown(KEY_LEFT)) ? 
                    -addition : 0;
    additionV.y = (IsKeyDown(KEY_DOWN)) ? 
                    addition : (IsKeyDown(KEY_UP)) ? 
                    -addition : 0;
    if(additionV.x != 0 && additionV.y != 0)
        additionV *= diagonalMultiply;
    characterPos += additionV;
}

void HandleEvents(raylib::Vector2& characterPos)
{
    HandleCharacterMovement(characterPos);
    // maybe more event handling
}

void HandleDrawing(raylib::Window& window, const raylib::Vector2 characterPos, float& timeElapsed, int& backgroundIndex, bool& backgroundTransitionGoingForward)
{
    const float transitionDuration = 60.0f;

    window.BeginDrawing();
    {
        window.ClearBackground(Colors::TransitionColorPalette(Colors::OCEAN_PALETTE, transitionDuration, timeElapsed, backgroundIndex, backgroundTransitionGoingForward));
        DrawCircleV(characterPos, 5.0f, raylib::Color::Orange());

        // more drawing
    }
    window.EndDrawing();
}


int main() 
{
    // Awake
    const int screenWidth = 800;
    const int screenHeight = 800;
    const int targetFPS = 60;

    float timeElapsed = 0.0f;
    int backgroundIndex = 0;
    bool backgroundTransitionGoingForward = true;
    
    raylib::Vector2 characterPos = raylib::Vector2(400.0f, 400.0f);
    raylib::Color textColor = raylib::Color::Blue();
    raylib::Window window(screenWidth, screenHeight, "Fish King");

    // Start
    window.SetTargetFPS(targetFPS);
    
    // Update
    while(!window.ShouldClose())
    {
        // Event Handling
        HandleEvents(characterPos);

        // Drawing
        HandleDrawing(window, characterPos, timeElapsed, backgroundIndex, backgroundTransitionGoingForward);
    }

    return 0;
}