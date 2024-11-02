#pragma once

#include "game_object.hpp"
#include "interactable.hpp"

class NPC : public GameObject {
public:
    NPC(const std::string& texturePath, raylib::Vector2 initialPosition);

    ~NPC() = default;

    void Update() override;
    void Interact(); // Specific method for NPC

private:
    Interactable m_interactable; // Composition
};
