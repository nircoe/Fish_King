#pragma once

#include "game_object.hpp"
#include "moveable.hpp"

class Player : public GameObject {
public:
    Player(const std::string& texturePath, raylib::Vector2 initialPosition, const float speed);

    ~Player() = default;

    void Update() override; // Specific method for Player

private:
    Moveable m_moveable; // Composition
};
