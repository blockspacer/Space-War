/*
**   Project: Space War
**   File: Clock.cpp
*/

#include "Clock.hpp"

namespace Engine
{
    Clock::Clock() :
        m_time(sf::Time::Zero),
        m_running(false)
    {
    }

    /////////////////////////////////////////

    void Clock::reset()
    {
        this->m_running = false;

        this->m_time = sf::Time::Zero;

        this->m_clock.restart();
    }

    /////////////////////////////////////////

    void Clock::start()
    {
        if (!this->m_running)
        {
            this->m_running = true;

            this->m_clock.restart();
        }
    }

    /////////////////////////////////////////

    void Clock::stop()
    {
        if (this->m_running)
        {
            this->m_running = false;

            this->m_time += this->m_clock.getElapsedTime();
        }
    }

    /////////////////////////////////////////

    void Clock::restart()
    {
        this->reset();

        this->start();
    }

    /////////////////////////////////////////

    sf::Time Clock::getTime()
    {
        if (this->m_running)
            return this->m_time + this->m_clock.getElapsedTime();;

        return this->m_time;
    }

    /////////////////////////////////////////

    bool Clock::isRunning()
    {
        return this->m_running;
    }
}