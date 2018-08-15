/*
**   Project: Space War
**   File: Hitbox.cpp
*/

#include "Hitbox.hpp"

namespace Engine
{
    Hitbox::Hitbox() :
        m_size(0.f, 0.f),
        m_rect(sf::PrimitiveType::LineStrip, 5)
    {
        this->m_rect[0].color = sf::Color::Yellow;
        this->m_rect[1].color = sf::Color::Yellow;
        this->m_rect[2].color = sf::Color::Yellow;
        this->m_rect[3].color = sf::Color::Yellow;
        this->m_rect[4].color = sf::Color::Yellow;
    }

    //////////////////////////////////////////////////////////

    Hitbox::Hitbox(sf::Vector2f size) :
        m_size(size),
        m_rect(sf::PrimitiveType::LineStrip, 5)
    {
        this->m_rect[0].position = sf::Vector2f(0.f, 0.f);
        this->m_rect[1].position = sf::Vector2f(this->m_size.x, 0.f);
        this->m_rect[2].position = sf::Vector2f(this->m_size.x, this->m_size.y);
        this->m_rect[3].position = sf::Vector2f(0.f, this->m_size.y);
        this->m_rect[4].position = sf::Vector2f(0.f, 0.f);


        this->m_rect[0].color = sf::Color::Yellow;
        this->m_rect[1].color = sf::Color::Yellow;
        this->m_rect[2].color = sf::Color::Yellow;
        this->m_rect[3].color = sf::Color::Yellow;
        this->m_rect[4].color = sf::Color::Yellow;


        this->setOrigin(this->m_size.x / 2, this->m_size.y / 2);
    }

    //////////////////////////////////////////////////////////

    void Hitbox::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= this->getTransform();

        target.draw(m_rect, states);
    }

    //////////////////////////////////////////////////////////

    sf::Vector2f Hitbox::getSize() const
    {
        return this->m_size;
    }

    //////////////////////////////////////////////////////////

    sf::FloatRect Hitbox::getGlobalBounds() const
    {
        float width = static_cast<float>(std::abs(this->m_size.x));
        float height = static_cast<float>(std::abs(this->m_size.y));

        return this->getTransform().transformRect(sf::FloatRect(0.f, 0.f, width, height));
    }

    //////////////////////////////////////////////////////////

    bool Hitbox::checkCollision(const Hitbox& hitbox)
    {
        return true;
    }

    //////////////////////////////////////////////////////////

    void Hitbox::setSize(sf::Vector2f size)
    {
        this->m_size = size;

        float left = this->m_rect[0].position.x;

        float top = this->m_rect[0].position.y;

        this->m_rect[0].position = sf::Vector2f(left, top);
        this->m_rect[1].position = sf::Vector2f(left + this->m_size.x, top);
        this->m_rect[2].position = sf::Vector2f(left + this->m_size.x, top + this->m_size.y);
        this->m_rect[3].position = sf::Vector2f(left, top + this->m_size.y);
        this->m_rect[4].position = sf::Vector2f(left, top);


        this->setOrigin(this->m_size.x / 2, this->m_size.y / 2);
    }
}