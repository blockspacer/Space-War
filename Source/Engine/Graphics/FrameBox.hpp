/*
**   Project: Space War
**   File: FrameBox.hpp
*/

#ifndef _SpaceWar_FrameBox_HPP_
#define _SpaceWar_FrameBox_HPP_

#include <SFML/Graphics.hpp>
#include "../../Config.hpp"

namespace Engine
{
    class FrameBox : public sf::Drawable, public sf::Transformable
    {
    private:
        sf::VertexArray                m_rect;

        sf::Vector2f                   m_size;

    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    public:
        FrameBox(sf::Vector2f size = sf::Vector2f(0.f, 0.f));

        sf::Vector2f getSize() const;

        void setSize(sf::Vector2f size);
    };
}

#endif  //   _SpaceWar_FrameBox_HPP_