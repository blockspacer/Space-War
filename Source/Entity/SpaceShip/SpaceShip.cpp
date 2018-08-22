/*
**   Project: Space War
**   File: SpaceShip.cpp
*/

#include "SpaceShip.hpp"

namespace Sw
{
    SpaceShip::SpaceShip() :
        m_maxSpeed(0.f),
        m_timeReload(1.0f),
        m_inertia(0.99f),
        m_maxHP(0),
        m_currentHP(0)
    {
    }

    //////////////////////////////////////////////////

    SpaceShip::SpaceShip(float maxSpeed, float timeReload, float inertia, int HP) :
        m_maxSpeed(maxSpeed),
        m_timeReload(timeReload),
        m_inertia(inertia),
        m_maxHP(HP),
        m_currentHP(HP),
        BaseEntity()
    {
    }

    //////////////////////////////////////////////////

    SpaceShip::SpaceShip(const sf::Texture& texture, const sf::IntRect& rectangle) :
        BaseEntity(texture, rectangle)
    {
    }
}