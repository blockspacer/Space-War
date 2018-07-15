/*
**   Project: Space War
**   File: Animation.hpp
*/

#ifndef _SpaceWar_Animation_HPP_
#define _SpaceWar_Animation_HPP_

#include <SFML/Graphics.hpp>
#include <vector>
#include "../System/Clock.hpp"

namespace Engine
{
    class Animation
    {
    private:
        std::vector<sf::IntRect>       m_all_frame;

        Clock                          m_clock;

    public:


    };
}

#endif  //   _SpaceWar_Animation_HPP_