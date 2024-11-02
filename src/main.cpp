#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include "raylib-cpp.hpp"
#include "colors.hpp"

using std::string;

void HandleCharacterMovement(raylib::Vector2& characterPos, const float MovementSpeed)
{
    
    const float diagonalMultiply = sqrtf(powf(MovementSpeed, 2.0f) / 2) / MovementSpeed;
    const raylib::Vector2 lastPos = raylib::Vector2(characterPos);
    raylib::Vector2 additionV = raylib::Vector2();
    additionV.x = (IsKeyDown(KEY_RIGHT)) ? 
                    MovementSpeed : (IsKeyDown(KEY_LEFT)) ? 
                    -MovementSpeed : 0;
    additionV.y = (IsKeyDown(KEY_DOWN)) ? 
                    MovementSpeed : (IsKeyDown(KEY_UP)) ? 
                    -MovementSpeed : 0;
    if(additionV.x != 0 && additionV.y != 0)
        additionV *= diagonalMultiply;
    characterPos += additionV;
}

void HandleEvents(raylib::Vector2& characterPos, const float MovementSpeed)
{
    HandleCharacterMovement(characterPos, MovementSpeed);
    // maybe more event handling
}

void HandleCamera(raylib::Camera2D& camera, const raylib::Vector2 CharacterPos)
{
    const float smoothFactor = 0.02f;
    camera.target = Vector2Lerp(camera.target, CharacterPos, smoothFactor);
}

void HandleDrawing(raylib::Window& window, raylib::Camera2D& camera, const raylib::Vector2 characterPos)
{
    DrawCircleV(characterPos, 20.0f, raylib::Color::Orange());
    
    // raylib::Vector2 circle1 = camera.GetScreenToWorld({100, 100});
    // raylib::Vector2 circle2 = camera.GetScreenToWorld({300, 100});
    // raylib::Vector2 circle3 = camera.GetScreenToWorld({100, 300});
    // raylib::Vector2 circle4 = camera.GetScreenToWorld({500, 300});
    // raylib::Vector2 circle5 = camera.GetScreenToWorld({300, 500});
    // DrawCircleV(circle1, 5.0f, raylib::Color::Black());
    // DrawCircleV(circle2, 8.0f, raylib::Color::Black());
    // DrawCircleV(circle3, 3.0f, raylib::Color::Black());
    // DrawCircleV(circle4, 15.0f, raylib::Color::Black());
    // DrawCircleV(circle5, 12.0f, raylib::Color::Black());
    // more drawing
}

void WindowSettings(raylib::Window& window, const int TargetFPS, const raylib::Image& IconImage)
{
    window.SetTargetFPS(TargetFPS);
    window.SetIcon(IconImage);
}

void HandleText(raylib::Window& window, raylib::Camera2D& camera, const int TargetFPS)
{
    const char* targetFPSStr = TargetFPS > 0 ? TextFormat("Target FPS: %i", TargetFPS) : "Target FPS: MAX";
    std::pair<int, int> fpsPos = std::pair<int, int>(50, 50);
    DrawText(targetFPSStr, fpsPos.first, fpsPos.second, 20, BLACK);
    DrawText(TextFormat("Current FPS: %i", window.GetFPS()), fpsPos.first, fpsPos.second + 50, 20, BLACK);
}

int main() 
{
    // Awake
    const std::pair<int, int> ScreenSize = std::pair<int, int>(800, 800);
    const raylib::Vector2 fScreenSize = raylib::Vector2((float)ScreenSize.first, (float)ScreenSize.second);
    const int TargetFPS = 120;
    const float BackgroundTransitionDuration = 60.0f;
    const float MovementSpeed = 3.0f;
    const raylib::Image IconImage = raylib::Image("C:/Projects/Fish_King/assets/Fish/fish1.png");  

    float timeElapsed = 0.0f;
    int backgroundIndex = 0;
    bool backgroundTransitionGoingForward = true;
    double previousTime = GetTime();
    double currentTime = 0.0;
    double updateDrawTime = 0.0;
    float deltaTime = 0.0f;

    
    raylib::Vector2 characterPos = raylib::Vector2();
    raylib::Color textColor = raylib::Color::Black();
    raylib::Camera2D camera = raylib::Camera2D({fScreenSize.x / 2, fScreenSize.y / 2}, {0.0f, 0.0f});
    raylib::Window window(ScreenSize.first, ScreenSize.second, "Fish King");

    // Start
    WindowSettings(window, TargetFPS, IconImage);
    
    // Update
    while(!window.ShouldClose())
    {
        // std::cout << "Camera Target X: " << camera.target.x << " Y:" << camera.target.y << std::endl;
        // Event Handling
        HandleEvents(characterPos, MovementSpeed);

        // Drawing
        window.BeginDrawing();
        {
            window.ClearBackground(Colors::TransitionColorPalette(Colors::OCEAN_PALETTE, BackgroundTransitionDuration, timeElapsed, 
                                                                    backgroundIndex, backgroundTransitionGoingForward));
            camera.BeginMode();
            {
                // HandleCamera / UpdateCamera
                HandleCamera(camera, characterPos);


                HandleDrawing(window, camera, characterPos);
            }
            camera.EndMode();

            // HandleText / HandleUI
            HandleText(window, camera, TargetFPS);
        }   
        window.EndDrawing();
    }

    return 0;
}