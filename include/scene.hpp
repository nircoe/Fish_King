#pragma once

#include <unordered_map>
#include <memory>
#include "game_object.hpp"

class Scene 
{
public:
    Scene();

    ~Scene() = default;
    
    void Update();
    void Render();

    void AddGameObject(std::shared_ptr<GameObject> gameObject);
    void RemoveGameObject(std::shared_ptr<GameObject> gameObject);

private:
    std::unordered_map<unsigned int, std::shared_ptr<GameObject>> m_gameObjects;
};
