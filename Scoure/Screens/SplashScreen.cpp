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

    void SplashScreen::update()
    {

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