#include "enemy.hpp"

Enemy::Enemy(const std::string& texturePath, raylib::Vector2 initialPosition)
    : GameObject(texturePath, initialPosition), m_moveable() {}

void Enemy::Update()
{
    // Enemy Update logic

    GameObject::Update();
}

void Enemy::Attack()
{
    // Implement enemy attack logic using m_movable
}
