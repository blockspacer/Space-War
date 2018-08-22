/*
**   Project: Space War
**   File: Player.hpp
*/

#ifndef _SpaceWar_Player_HPP_
#define _SpaceWar_Player_HPP_

#include <SFML/Graphics.hpp>
#include "../../Engine/Engine.hpp"
#include "../../Config.hpp"
#include "SpaceShip.hpp"

namespace Sw
{
    class Player : public SpaceShip
    {
    private:
        sf::Sprite               m_gun;

        sf::Clock                m_clock;

    private:
        void control();

        void setValueafterControl();

    public:
        Player() = default;
        Player(const sf::Texture& texture, const sf::Texture& textureGun);

        void update();

        void drawGun(sf::RenderTarget& target);

        void setTextureGun(sf::Texture& texture);

        void setPositionMouse(sf::Vector2i position);

        bool isShoot();

        float getAngleGun();
    };
}

#endif  //   _SpaceWar_Player_HPP_