#include "player.hpp"

Player::Player(const std::string& texturePath, raylib::Vector2 initialPosition, const float speed)
    : GameObject(texturePath, initialPosition) 
{
    m_moveable = Moveable(speed);
}

void Player::Update() 
{    
    raylib::Vector2 velocity = raylib::Vector2();
    float speed = m_moveable.getSpeed();
    velocity.x = (IsKeyDown(KEY_RIGHT)) ?
                    speed : (IsKeyDown(KEY_LEFT)) ?
                    -speed : 0;
    velocity.y = (IsKeyDown(KEY_DOWN)) ?
                    speed : (IsKeyDown(KEY_UP)) ?
                    -speed : 0;                    
    if(velocity.x != 0 && velocity.y != 0)
    {
        const float diagonalMultiply = sqrtf(powf(speed, 2.0f) / 2) / speed;
        velocity *= diagonalMultiply;
    }
    this->SetVelocity(velocity);

    GameObject::Update();
}
