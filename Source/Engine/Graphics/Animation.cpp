/*
**   Project: Space War
**   File: Animation.cpp
*/

#include "Animation.hpp"

namespace Engine
{
    Animation::Animation(sf::IntRect sizeFrame, float time_next_frame, int count)
    {
        this->create(sizeFrame, time_next_frame, count);
    }

    ////////////////////////////////////////////////////////////////////////////////////

    Animation::~Animation()
    {
        this->m_all_frames.clear();
    }

    ////////////////////////////////////////////////////////////////////////////////////

    void Animation::create(sf::IntRect sizeFrame, float time_next_frame, int count)
    {
        this->m_time_next_frame = time_next_frame;

        this->m_current_frame = 0;

        if (!this->m_all_frames.empty())
            this->m_all_frames.clear();

        for (int i = 0; i < count; i++)
            this->m_all_frames.push_back(sf::IntRect(sizeFrame.left + i * sizeFrame.width, sizeFrame.top, sizeFrame.width, sizeFrame.height));

        this->m_clock.start();
    }

    ////////////////////////////////////////////////////////////////////////////////////

    sf::IntRect Animation::getFrame()
    {
        if (this->m_clock.getTime().asSeconds() >= this->m_time_next_frame)
        {
            this->m_current_frame++;

            if (this->m_current_frame == this->m_all_frames.size())
                this->m_current_frame = 0;

            this->m_clock.restart();
        }

        return this->m_all_frames[this->m_current_frame];
    }

    ////////////////////////////////////////////////////////////////////////////////////

    int Animation::getCurrentFrame() const
    {
        return this->m_current_frame;
    }

    ////////////////////////////////////////////////////////////////////////////////////

    void Animation::setCurrentFrame(int countFrame)
    {
        //if (countFrame >= 0 && countFrame < this->m_all_frames.size())
        //    this->m_current_frame = countFrame;

        this->m_current_frame = (countFrame >= 0 && countFrame < (int)this->m_all_frames.size()) ? countFrame : this->m_current_frame;
    }

    ////////////////////////////////////////////////////////////////////////////////////

    float Animation::getTimeNextFrame() const
    {
        return this->m_time_next_frame;
    }

    ////////////////////////////////////////////////////////////////////////////////////

    void Animation::setTimeNextFrame(float time_next_frame)
    {
        this->m_time_next_frame = (time_next_frame > 0.f) ? time_next_frame : this->m_time_next_frame;
    }

    ////////////////////////////////////////////////////////////////////////////////////

    void Animation::stop()
    {
        this->m_clock.stop();
    }

    ////////////////////////////////////////////////////////////////////////////////////

    void Animation::start()
    {
        this->m_clock.start();
    }
}