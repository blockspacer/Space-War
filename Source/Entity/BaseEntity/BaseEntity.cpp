/*
**   Project: Space War
**   File: BaseEntity.cpp
*/

#include "BaseEntity.hpp"

namespace Sw
{
    
    BaseEntity::BaseEntity() :
        m_currentHP(0),
        m_maxHP(0),
        m_speedMove(0.f)
    {
    }

    /////////////////////////////////////////////////////////

    BaseEntity::BaseEntity(const sf::Texture& texture, const sf::IntRect& rectangle) :
        Sprite(texture, rectangle)
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
}