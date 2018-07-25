/*
**   Project: Space War
**   File: Hitbox.hpp
*/

#ifndef _SpaceWar_Hitbox_HPP_
#define _SpaceWar_Hitbox_HPP_

#include <SFML/Graphics.hpp>
#include "../../Config.hpp"

namespace Engine
{
    class Hitbox : public sf::Drawable, public sf::Transformable
    {
    private:
        sf::Vector2f             m_size;

        sf::VertexArray          m_rect;

    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


    public:
        Hitbox();
        Hitbox(sf::Vector2f size);
        ~Hitbox() = default;

        //   Return size of this
        sf::Vector2f getSize() const;


        //   This function is used to set size
        void setSize(sf::Vector2f size);


        //   Return the bounds of this
        sf::FloatRect getGlobalBounds() const;


        //   This function is used to check collision between two Hitbox
        bool checkCollision(const Hitbox& hitbox);


        //   Delete functions
        void setScale(float factorX, float factorY) = delete;
        void setScale(const sf::Vector2f& factors) = delete;
        void scale(float factorX, float factorY) = delete;
        void scale(const sf::Vector2f& factor) = delete;
    };
}

#endif  //   _SpaceWar_Hitbox_HPP_