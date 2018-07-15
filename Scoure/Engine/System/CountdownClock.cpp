/*
**   Project: Space War
**   File: CountdownClock.cpp
*/

#include "CountdownClock.hpp"

namespace Engine
{
    CountdownClock::CountdownClock(sf::Time time) :
        m_time(time),
        m_running(false)
    {
    }

    ////////////////////////////////////////////

    void CountdownClock::reset(sf::Time time)
    {
        this->m_time = time;

        this->m_running = false;

        this->m_clock.restart();
    }

    ////////////////////////////////////////////

    void CountdownClock::start()
    {
        if (!this->m_running)
        {
            this->m_running = true;

            this->m_clock.restart();
        }
    }

    ////////////////////////////////////////////

    void CountdownClock::stop()
    {
        if (this->m_running)
        {
            this->m_running = false;

            this->m_time -= this->m_clock.getElapsedTime();
        }

    }

    ////////////////////////////////////////////

    void CountdownClock::restart(sf::Time time)
    {
        this->reset(time);

        this->start();
    }

    bool CountdownClock::isRunning()
    {
        return this->m_running;
    }

    sf::Time CountdownClock::getTime()
    {
        if (this->m_running)
            return this->m_time - this->m_clock.getElapsedTime();

        return this->m_time;
    }
}