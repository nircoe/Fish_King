#pragma once

#include "game_object.hpp"
#include "moveable.hpp"

class Enemy : public GameObject {
public:
    Enemy(const std::string& texturePath, raylib::Vector2 initialPosition);
    
    ~Enemy() = default;

    void Update() override;
    void Attack(); // Specific method for Enemy

private:
    Moveable m_moveable; // Composition
};
