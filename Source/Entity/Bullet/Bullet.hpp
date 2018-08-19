/*
**   Project: Space War
**   File: Bullet.hpp
*/

#ifndef _SpaceWar_Bullet_HPP_
#define _SpaceWar_Bullet_HPP_

#include <SFML/Graphics.hpp>
#include "../BaseEntity/BaseEntity.hpp"
#include "../../Config.hpp"

namespace Sw
{
    class Bullet : public BaseEntity
    {
    protected:
        int                         m_damage;

    protected:
        void move();

    public:
        Bullet();
        Bullet(sf::Vector2f position, float angle, int damage);

    };
}

#endif  //   _SpaceWar_Bullet_HPP_