/*
**   Project: Space War
**   File: Player.cpp
*/

#include "Player.hpp"

namespace Sw
{
    Player::Player(const sf::Texture& texture, const sf::Texture& textureGun)
    {
        this->setTexture(texture);
        this->m_gun.setTexture(textureGun);

        this->setOrigin(this->getGlobalBounds().width / 2, 60.f);
        this->m_gun.setOrigin(this->m_gun.getGlobalBounds().width / 2, this->m_gun.getGlobalBounds().height / 2 + 15);
    }

    /////////////////////////////////////////////////////////////

    void Player::update()
    {
        this->m_gun.setPosition(this->getPosition());
    }

    /////////////////////////////////////////////////////////////

    void Player::drawGun(sf::RenderTarget& target)
    {
        target.draw(this->m_gun);
    }

    /////////////////////////////////////////////////////////////

    void Player::setTextureGun(sf::Texture& texture)
    {
        this->m_gun.setTexture(texture);
    }

    /////////////////////////////////////////////////////////////

    void Player::setPositionMouse(sf::Vector2i position)
    {
        float width = position.x - this->m_gun.getPosition().x;
        float height = this->m_gun.getPosition().y - position.y;

        double tan = width / height;

        float angle = float(std::atan(tan) * RadToDeg);

        if ((int)angle != 90 && (int)angle != 270)
        {
            if (this->m_gun.getPosition().y <= position.y)
                angle += 180;
        }

        this->m_gun.setRotation(angle);
    }
}