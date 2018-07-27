/*
**   Project: Space War
**   File: Application.cpp
*/

#include "Application.hpp"

namespace Sw
{
    Application::Application() :
        m_data(std::make_shared<ScreenData>())
    {
        this->m_data->m_window.create(sf::VideoMode(Screen_With, Screen_Height), Title_Game, sf::Style::Close);
        this->m_data->m_window.setFramerateLimit(Screen_Max_Frame);


        //   Add new Screen
        this->m_data->m_screen.addSreen(Engine::ScreenPtr(new SplashScreen(this->m_data)));
    }

    ////////////////////////////////////////////////

    Application::~Application()
    {
    }

    ////////////////////////////////////////////////

    void Application::run()
    {
        sf::Time timeLastFrame = sf::Time::Zero;

        sf::Clock timer;

        while (this->m_data->m_window.isOpen())
        {
            this->m_data->m_screen.handleEvent();

            timeLastFrame += timer.restart();

            while (timeLastFrame > Time_A_Frame)
            {
                timeLastFrame -= Time_A_Frame;

                this->m_data->m_screen.handleEvent();

                this->m_data->m_screen.update();
            }

            this->m_data->m_screen.draw();
        }
    }
}