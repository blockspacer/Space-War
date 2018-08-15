/*
**   Project: Space War
**   File: Animation.hpp
*/

#ifndef _SpaceWar_Animation_HPP_
#define _SpaceWar_Animation_HPP_

#include <SFML/Graphics.hpp>
#include <vector>
#include "../System/Clock.hpp"
#include "../../Config.hpp"

namespace Engine
{
    class Animation
    {
    private:
        std::vector<sf::IntRect>       m_all_frames;

        Engine::Clock                  m_clock;

        float                          m_time_next_frame;

        int                            m_current_frame;

    public:
        Animation() = default;
        Animation(sf::IntRect sizeFrame, float time_next_frame, int count);
        ~Animation();

        void create(sf::IntRect sizeFrame, float time_next_frame, int count);

        //   Return the current Frame
        sf::IntRect getFrame();


        //   Return the number of current Frame
        int getCurrentFrame() const;


        //   Set current frame
        void setCurrentFrame(int countFrame);


        //   Return the time next frame
        float getTimeNextFrame() const;


        //   Set time next frame
        void setTimeNextFrame(float time_next_frame);

        //   Stop Clock
        void stop();


        //   Continue Clock if it stoped
        void start();
    };
}

#endif  //   _SpaceWar_Animation_HPP_