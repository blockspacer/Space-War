/*
**   Project: Space War
**   File: Clock.hpp
*/

#ifndef _SpaceWar_Clock_HPP_
#define _SpaceWar_Clock_HPP_

#include <SFML/System.hpp>
#include "../../Config.hpp"

namespace Engine
{
    class Clock
    {
    private:
        sf::Time                 m_time;

        sf::Clock                m_clock;

        bool                     m_running;

    private:
        void reset();

    public:
        Clock();
        ~Clock() = default;

        //   Start the Clock
        void start();

        //   Stop the Clock
        void stop();

        //   Restart the Clock
        void restart();

        //   Return the current Time
        sf::Time getTime();

        //   Return the status of Clock
        bool isRunning();
    };
}

#endif  //   _SpaceWar_Clock_HPP_