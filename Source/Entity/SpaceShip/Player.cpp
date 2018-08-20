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

        this->setOrigin(this->getGlobalBounds().width / 2, 35.f);
        this->m_gun.setOrigin(this->m_gun.getGlobalBounds().width / 2, 30.f);

        this->m_speedMove = 0.5f;
        this->m_path_angle = 0.0f;
        this->m_path_temp = sf::Vector2f(0.5f, 0.f);

        this->setPosition(Screen_Play_Width_Max / 2, Screen_Play_Height_Max / 2);
        this->setRotation(90.f);
    }

    /////////////////////////////////////////////////////////////

    void Player::control()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            this->rotate(-10.f);

            this->m_path_angle = -1.f;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            this->rotate(10.f);

            this->m_path_angle = 1.f;
        }
        else this->m_path_angle *= this->m_inertia;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            this->m_path_temp.x += float(Engine::Math::sin((int)this->getRotation()) * this->m_speedMove);

            this->m_path_temp.y -= float(Engine::Math::cos((int)this->getRotation()) * this->m_speedMove);
        }
        else this->m_path_temp *= this->m_inertia;
    }

    /////////////////////////////////////////////////////////////

    void Player::setValueafterControl()
    {
        this->m_currentSpeed = std::sqrt(this->m_path_temp.x * this->m_path_temp.x + this->m_path_temp.y * this->m_path_temp.y);

        if (this->m_currentSpeed > this->m_maxSpeed)
            this->m_path_temp *= float(this->m_maxSpeed / this->m_currentSpeed);

        this->setPosition(this->getPosition() + this->m_path_temp);
        this->setRotation(this->getRotation() + this->m_path_angle);

        if (this->getPosition().x < Screen_Play_Width_Min + 20.f)
            this->setPosition(Screen_Play_Width_Min + 20.f, this->getPosition().y);
        else if (this->getPosition().x > Screen_Play_Width_Max - 20.f)
            this->setPosition(Screen_Play_Width_Max - 20.f, this->getPosition().y);

        if (this->getPosition().y < Screen_Play_Height_Min + 20.f)
            this->setPosition(this->getPosition().x, Screen_Play_Height_Min + 20.f);
        else if (this->getPosition().y > Screen_Play_Height_Max - 20.f)
            this->setPosition(this->getPosition().x, Screen_Play_Height_Max - 20.f);

        this->m_gun.setPosition(this->getPosition());
    }

    /////////////////////////////////////////////////////////////

    void Player::update()
    {
        //   Control Player
        this->control();


        //   Set Value after Control Player
        this->setValueafterControl();
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

        if ((int)angle != 90 && (int)angle != -90)
        {
            if (this->m_gun.getPosition().y <= position.y)
                angle += 180;
        }

        this->m_gun.setRotation(angle);
    }
}