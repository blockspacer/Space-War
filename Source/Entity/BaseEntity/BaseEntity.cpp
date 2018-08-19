/*
**   Project: Space War
**   File: BaseEntity.cpp
*/

#include "BaseEntity.hpp"

namespace Sw
{
    
    BaseEntity::BaseEntity() :
        m_speedMove(0.f),
        m_isDie(false)
    {
    }

    /////////////////////////////////////////////////////////

    BaseEntity::BaseEntity(float speedMove) :
        m_speedMove(speedMove)
    {
    }

    /////////////////////////////////////////////////////////

    BaseEntity::BaseEntity(const sf::Texture& texture, const sf::IntRect& rectangle) :
        Sprite(texture, rectangle),
        m_isDie(false)
    {
    }

    /////////////////////////////////////////////////////////

    void BaseEntity::update()
    {
        //   Not to do
    }

    /////////////////////////////////////////////////////////

    const Engine::Hitbox* BaseEntity::getHitbox() const
    {
        return &this->m_hitbox;
    }

    /////////////////////////////////////////////////////////

    bool BaseEntity::isDie() const
    {
        return this->m_isDie;
    }
}