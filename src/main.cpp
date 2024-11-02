#include "raylib-cpp.hpp"
#include "colors.hpp"
#include "scene.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "npc.hpp"

using std::string;


void HandleCamera(raylib::Camera2D& camera, const raylib::Vector2 CharacterPos)
{
    const float smoothFactor = 0.02f;
    camera.target = Vector2Lerp(camera.target, CharacterPos, smoothFactor);
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
    DrawText(TextFormat("X: %f", camera.target.x), fpsPos.first, fpsPos.second + 100, 20, BLACK);
    DrawText(TextFormat("Y: %f", camera.target.y), fpsPos.first, fpsPos.second + 130, 20, BLACK);
}

int main() 
{
    // Awake
    const std::pair<int, int> ScreenSize = std::pair<int, int>(800, 800);
    const raylib::Vector2 fScreenSize = raylib::Vector2((float)ScreenSize.first, (float)ScreenSize.second);
    const int TargetFPS = 60;
    const float MovementSpeed = 100.0f;
    const raylib::Image IconImage = raylib::Image("C:/Projects/Fish_King/assets/Fish/fish1.png");  
    
    raylib::Vector2 characterPos = raylib::Vector2();
    raylib::Camera2D camera = raylib::Camera2D({fScreenSize.x / 2, fScreenSize.y / 2}, {0.0f, 0.0f});
    raylib::Window window(ScreenSize.first, ScreenSize.second, "Fish King");

    Scene scene = Scene();

    std::shared_ptr<Player> player = std::make_shared<Player>("assets/Fish/fish1.png", raylib::Vector2(0.0f, 0.0f), MovementSpeed);
    scene.AddGameObject(player);

    for(int i = 0; i < 5; ++i)
    {
        std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>("assets/Fish/fish2.png", raylib::Vector2(-300.0f + i * 100.0f, -100.0f + i * 50.0f));
        scene.AddGameObject(enemy);
    }

    std::shared_ptr<NPC> npc = std::make_shared<NPC>("assets/Fish/fish1.png", raylib::Vector2(-50.0f, 250.0f));
    scene.AddGameObject(npc);

    // Start
    WindowSettings(window, TargetFPS, IconImage);
    
    // Update
    while(!window.ShouldClose())
    {
        scene.Update();

        // Drawing
        window.BeginDrawing();
        {
            window.ClearBackground(Colors::transitionColorPalette(Colors::OCEAN_PALETTE, camera.target.y));
            camera.BeginMode();
            {
                // HandleCamera / UpdateCamera
                HandleCamera(camera, player->GetPosition());
                scene.Render();
            }
            camera.EndMode();

            // HandleText / HandleUI
            HandleText(window, camera, TargetFPS);
        }   
        window.EndDrawing();
    }

    return 0;
}