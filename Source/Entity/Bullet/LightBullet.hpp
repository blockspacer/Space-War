/*
**   Project: Space War
**   File: LightBullet.hpp
*/

#ifndef _SpaceWar_LightBullet_HPP_
#define _SpaceWar_LightBullet_HPP_

#include <SFML/Graphics.hpp>
#include "Bullet.hpp"
#include "../../Config.hpp"

namespace Sw
{
    class LightBullet : public Bullet
    {
    private:



    public:
        LightBullet();
        LightBullet(sf::Texture& texture, sf::Vector2f position, float angle);


        void update() override;
    };
}

#endif //   _SpaceWar_LightBullet_HPP_