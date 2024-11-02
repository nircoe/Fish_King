#pragma once

#include <string>
#include "raylib-cpp.hpp"

class GameObject {
public:
    GameObject(const std::string& texturePath, raylib::Vector2 initialPosition);
    virtual ~GameObject();

    virtual void Update() = 0;
    virtual void Render();

    // setters
    void SetVelocity(raylib::Vector2 newVelocity);
    void SetActive(bool active);

    // getters
    unsigned int getId() const;
    raylib::Vector2 GetPosition() const;
    raylib::Vector2 GetVelocity() const;
    bool IsActive() const;

private:
    static unsigned int s_idCounter; // static member for ID generation
    unsigned int m_id;
    raylib::Texture2D m_texture;
    raylib::Vector2 m_position;
    raylib::Vector2 m_velocity;
    bool m_isActive;
};
