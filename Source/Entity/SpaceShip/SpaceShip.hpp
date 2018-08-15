/*
**   Project: Space War
**   File: SpaceShip.hpp
*/

#ifndef _SpaceWar_SpaceShip_HPP_
#define _SpaceWar_SpaceShip_HPP_

#include <SFML/Graphics.hpp>
#include "../BaseEntity/BaseEntity.hpp"
#include "../../Config.hpp"

namespace Sw
{
    class SpaceShip : public BaseEntity
    {
    protected:
        float                   m_maxSpeed;

        float                   m_currentSpeed;

        float                   m_timeReload;

        float                   m_inertia;

        sf::Vector2f            m_path_temp;

    public:
        SpaceShip();
        SpaceShip(float maxSpeed, float timeReload, float inertia);
        SpaceShip(const sf::Texture& texture) = delete;
        SpaceShip(const sf::Texture& texture, const sf::IntRect& rectangle);

    };
}

#endif  //   _SpaceWar_SpaceShip_HPP_