/*
**   Project: Space War
**   File: BaseEntity.cpp
*/

#include "BaseEntity.hpp"

namespace Sw
{
    BaseEntity::BaseEntity(sf::Texture* texture) :
        m_texture(texture)
    {

    }

    ///////////////////////////////////////////////////////////

    void BaseEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {

    }
}