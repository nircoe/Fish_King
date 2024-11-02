#include "scene.hpp"

Scene::Scene() {}

void Scene::AddGameObject(std::shared_ptr<GameObject> gameObject)
{
    m_gameObjects.emplace(gameObject->getId(), std::ref(gameObject));
}

void Scene::RemoveGameObject(std::shared_ptr<GameObject> gameObject) 
{
    m_gameObjects.erase(gameObject->getId());
}

void Scene::Update() 
{
    for (auto& gameObjectPair : m_gameObjects) 
    {
        if(auto& gameObject = gameObjectPair.second) 
        {
            gameObject->Update();
        }
    }
}

void Scene::Render() 
{
    for (auto& gameObjectPair : m_gameObjects) 
    {
        if(auto& gameObject = gameObjectPair.second) 
        {
            gameObject->Render();
        }
    }
}
