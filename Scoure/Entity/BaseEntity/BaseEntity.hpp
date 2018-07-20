/*
**   Project: Space War
**   File: BaseEntity.hpp
*/

#ifndef _SpaceWar_BaseEntity_HPP_
#define _SpaceWar_BaseEntity_HPP_

#include <SFML/Graphics.hpp>
#include "../../Engine/Graphics/Animation.hpp"

namespace Sw
{
    class BaseEntity : public sf::Sprite
    {
    private:
        int            m_currentHP;
        int            m_maxHP;

        float          m_speedMove;

    private:


    public:
        BaseEntity();
        BaseEntity(const sf::Texture& texture, const sf::IntRect& rectangle);


        //   Delete functions
        void setScale(float factorX, float factorY) = delete;
        void setScale(const sf::Vector2f& factors) = delete;
        void scale(float factorX, float factorY) = delete;
        void scale(const sf::Vector2f& factor) = delete;
    };
}

#endif  //   _SpaceWar_BaseEntity_HPP_