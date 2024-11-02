#include "npc.hpp"

NPC::NPC(const std::string& texturePath, raylib::Vector2 initialPosition)
    : GameObject(texturePath, initialPosition), m_interactable() {}

void NPC::Update()
{
    // NPC Update logic

    GameObject::Update();
}

void NPC::Interact()
{
    // Implement NPC interaction logic using m_interactable
}
