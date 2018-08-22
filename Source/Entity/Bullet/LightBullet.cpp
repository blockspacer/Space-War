/*
**   Project: Space War
**   File: LightBullet.cpp
*/

#include "LightBullet.hpp"

namespace Sw
{
    LightBullet::LightBullet() :
        Bullet()
    {
    }

    //////////////////////////////////////////

    LightBullet::LightBullet(sf::Texture& texture, sf::Vector2f position, float angle) :
        Bullet(position, angle, 15)
    {
        this->setTexture(texture);

        this->setOrigin(float(this->getTexture()->getSize().x / 2), float(this->getTexture()->getSize().y / 2));

        this->m_speedMove = 15.f;
    }

    //////////////////////////////////////////

    void LightBullet::update()
    {
        this->move();

        if (this->getPosition().x <= Screen_Play_Width_Min || this->getPosition().x >= Screen_Play_Width_Max ||
            this->getPosition().y <= Screen_Play_Height_Min || this->getPosition().y >= Screen_Play_Height_Max)
            this->m_isDie = true;
    }
}