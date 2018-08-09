/*
**   Project: Space War
**   File: SpaceShip.cpp
*/

#include "SpaceShip.hpp"

namespace Sw
{
    SpaceShip::SpaceShip() :
        m_timeReload(10.f),
        m_inertia(0.95f)
    {
    }

    //////////////////////////////////////////////////

    SpaceShip::SpaceShip(float timeReload, float inertia) :
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