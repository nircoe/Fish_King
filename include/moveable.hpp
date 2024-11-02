#pragma once

#include "raylib-cpp.hpp"

class Moveable 
{
protected:

    float m_speed;

public:

    Moveable();

    Moveable(float speed);

    ~Moveable() = default;

    float getSpeed();

    // more methods, like dash, jump, etc.
};