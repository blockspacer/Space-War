/*
**   Project: Space War
**   File: Screen.hpp
*/

#ifndef _SpaceWar_Screen_HPP_
#define _SpaceWar_Screen_HPP_

#include <SFML/System.hpp>
#include "../../Config.hpp"

namespace Engine
{
    class Screen
    {
#ifdef DEBUG_GAME

    protected:
        sf::Clock                   m_timer_show_quadtree;

        bool                        m_show_quadtree;

#endif

    public:
        virtual ~Screen() = default;

        //   Used to handle event in game
        virtual void handleEvent() = 0;


        //   Used to update game
        virtual void update() = 0;


        //   Used to draw game
        virtual void draw() = 0;


        //   Pause the Screen
        virtual void pause() {}


        //   Resume Screen if Screen paused
        virtual void resume() {}
    };

    typedef Screen* ScreenPtr;
}

#endif  //   _SpaceWar_Screen_HPP_