/*
**   Project: Space War
**   File: FrameBox.cpp
*/

#include "FrameBox.hpp"

namespace Engine
{
    FrameBox::FrameBox(sf::Vector2f size) :
        m_size(size),
        m_rect(sf::PrimitiveType::LineStrip, 5)
    {
        this->m_rect[0].position = sf::Vector2f(0.f, 0.f);
        this->m_rect[1].position = sf::Vector2f(this->m_size.x, 0.f);
        this->m_rect[2].position = sf::Vector2f(this->m_size.x, this->m_size.y);
        this->m_rect[3].position = sf::Vector2f(0.f, this->m_size.y);
        this->m_rect[4].position = sf::Vector2f(0.f, 0.f);


        this->m_rect[0].color = sf::Color::Red;
        this->m_rect[1].color = sf::Color::Red;
        this->m_rect[2].color = sf::Color::Red;
        this->m_rect[3].color = sf::Color::Red;
        this->m_rect[4].color = sf::Color::Red;
    }

    ///////////////////////////////////////////////

    void FrameBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= this->getTransform();

        target.draw(this->m_rect, states);
    }

    ///////////////////////////////////////////////

    sf::Vector2f FrameBox::getSize() const
    {
        return this->m_size;
    }

    ///////////////////////////////////////////////

    void FrameBox::setSize(sf::Vector2f size)
    {
        this->m_size = size;

        this->m_rect[0].position = this->getPosition();
        this->m_rect[1].position = this->getPosition() + sf::Vector2f(this->m_size.x, 0.f);
        this->m_rect[2].position = this->getPosition() + this->m_size;
        this->m_rect[3].position = this->getPosition() + sf::Vector2f(0.f, this->m_size.y);
        this->m_rect[4].position = this->getPosition();
    }
}