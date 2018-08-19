/*
**   Project: Space War
**   File: Bullet.cpp
*/

#include "Bullet.hpp"

namespace Sw
{
    Bullet::Bullet() :
        BaseEntity(),
        m_damage(0)
    {
    }

    ///////////////////////////////////////////////

    Bullet::Bullet(sf::Vector2f position, float angle, int damage) :
        m_damage(damage)
    {
        this->setPosition(position);

        this->setRotation(angle);
    }

    ///////////////////////////////////////////////

    void Bullet::move()
    {
        sf::Vector2f position = this->getPosition();

        position.x += float(Engine::Math::sin((int)this->getRotation()) * this->m_speedMove);

        position.y -= float(Engine::Math::cos((int)this->getRotation()) * this->m_speedMove);

        this->setPosition(position);
    }
}