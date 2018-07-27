/*
**   Project: Space War
**   File: SplashScreen.cpp
*/

#include "SplashScreen.hpp"

namespace Sw
{
    SplashScreen::SplashScreen(ScreenDataPtr data) :
        m_data(data)
    {
    }

    //////////////////////////////////////////////////

    SplashScreen::~SplashScreen()
    {
    }

    //////////////////////////////////////////////////

    void SplashScreen::update()
    {
        if (this->m_timer.getElapsedTime().asSeconds() > 2.f)
        {
            this->m_data->m_screen.addSreen(Engine::ScreenPtr(new MenuScreen(this->m_data)));
        }
    }

    //////////////////////////////////////////////////

    void SplashScreen::draw()
    {
        this->m_data->m_window.clear();

        this->m_data->m_window.display();
    }

    //////////////////////////////////////////////////

    void SplashScreen::handleEvent()
    {
        sf::Event event;

        while (this->m_data->m_window.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed)
                this->m_data->m_window.close();
        }
    }
}