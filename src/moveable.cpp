#include "moveable.hpp"

Moveable::Moveable() : Moveable(0.0f) {}

Moveable::Moveable(float speed) : m_speed(speed) {}

float Moveable::getSpeed()
{
    return this->m_speed * GetFrameTime();
}
