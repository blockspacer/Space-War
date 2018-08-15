/*
**   Project: Space War
**   File: CountdownClock.hpp
*/

#ifndef _SpaceWar_CountdownClock_HPP_
#define _SpaceWar_CountdownClock_HPP_

#include <SFML/Graphics.hpp>
#include "../../Config.hpp"

namespace Engine
{
    class CountdownClock
    {
    private:
        sf::Time                    m_time;

        sf::Clock                   m_clock;

        bool                        m_running;

    private:
        void reset(sf::Time time);


    public:
        CountdownClock(sf::Time time);
        ~CountdownClock() = default;

        //   Start the CountdownClock
        void start();

        //   Stop the CountdownClock
        void stop();

        //   Restart the CountdownClock
        void restart(sf::Time time);

        //   Return the status of CountdownClock
        bool isRunning();

        //   Return the current Time
        sf::Time getTime();
    };
}

#endif  //   _SpaceWar_CountdownClock_HPP_