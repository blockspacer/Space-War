/*
**   Project: Space War
**   File: SpaceShip.cpp
*/

#include "SpaceShip.hpp"

namespace Sw
{
    SpaceShip::SpaceShip() :
        m_maxSpeed(15.f),
        m_timeReload(1.f),
        m_inertia(0.99f)
    {
    }

    //////////////////////////////////////////////////

    SpaceShip::SpaceShip(float maxSpeed, float timeReload, float inertia) :
        m_maxSpeed(maxSpeed),
        m_timeReload(timeReload),
        m_inertia(inertia)
    {
    }

    //////////////////////////////////////////////////

    SpaceShip::SpaceShip(const sf::Texture& texture, const sf::IntRect& rectangle) :
        BaseEntity(texture, rectangle)
    {
    }
}