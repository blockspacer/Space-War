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
    class BaseEntity : public sf::Drawable, public sf::Transformable
    {
    private:
        sf::Vertex                     m_vertex[4];
        sf::IntRect                    m_textureRect;
        const sf::Texture*             m_texture;


    private:
        //   Inheritance Function
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    public:
        BaseEntity(sf::Texture* texture);
        ~BaseEntity() = default;


        //   Delete functions
        void setScale(float factorX, float factorY) = delete;
        void setScale(const sf::Vector2f& factors) = delete;
        void scale(float factorX, float factorY) = delete;
        void scale(const sf::Vector2f& factor) = delete;
    };
}

#endif  //   _SpaceWar_BaseEntity_HPP_