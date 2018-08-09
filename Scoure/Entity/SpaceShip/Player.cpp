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

        this->m_speedMove = 0.2f;

        this->setPosition(Screen_Play_Width_Max / 2, Screen_Play_Height_Max / 2);
        this->setRotation(90.f);
    }

    /////////////////////////////////////////////////////////////

    void Player::update()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            this->rotate(-3.f);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            this->rotate(3.f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            this->m_path_temp.x += float(Engine::Math::sin((int)this->getRotation()) * this->m_speedMove);

            this->m_path_temp.y -= float(Engine::Math::cos((int)this->getRotation()) * this->m_speedMove);
        }
        else this->m_path_temp *= this->m_inertia;


        this->setPosition(this->getPosition() + this->m_path_temp);

        if (this->getPosition().x < Screen_Play_Width_Min)
            this->setPosition(Screen_Play_Width_Min, this->getPosition().y);
        else if (this->getPosition().x > Screen_Play_Width_Max)
            this->setPosition(Screen_Play_Width_Max, this->getPosition().y);

        if (this->getPosition().y < Screen_Play_Height_Min)
            this->setPosition(this->getPosition().x, Screen_Play_Height_Min);
        else if (this->getPosition().y > Screen_Play_Height_Max)
            this->setPosition(this->getPosition().x, Screen_Play_Height_Max);

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