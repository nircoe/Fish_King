#include "game_object.hpp"

unsigned int GameObject::s_idCounter = 0; // Initialize the static ID counter

GameObject::GameObject(const std::string& texturePath, raylib::Vector2 initialPosition)
    : m_id(++s_idCounter), m_position(initialPosition), m_isActive(true) 
{
    m_velocity = raylib::Vector2();
    m_texture = LoadTexture(texturePath.c_str());
}

GameObject::~GameObject() {
    UnloadTexture(m_texture);
}

void GameObject::Update()
{
    if (m_isActive) {
        m_position.x += m_velocity.x;
        m_position.y += m_velocity.y;
    }
}

void GameObject::Render() {
    if (m_isActive) 
    {
        float angle = atan2(m_velocity.y, m_velocity.x) * (180.0f / PI);
        DrawTextureEx(m_texture, m_position, angle, 0.5f, WHITE);
        // DrawTexture(m_texture, m_position.x, m_position.y, WHITE);
    }
}

void GameObject::SetVelocity(raylib::Vector2 newVelocity) {
    m_velocity = newVelocity;
}

void GameObject::SetActive(bool active) {
    m_isActive = active;
}

unsigned int GameObject::getId() const
{
    return m_id;
}

raylib::Vector2 GameObject::GetPosition() const
{
    return m_position;
}

raylib::Vector2 GameObject::GetVelocity() const {
    return m_velocity;
}

bool GameObject::IsActive() const {
    return m_isActive;
}
