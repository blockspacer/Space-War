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
        this->m_background.setTexture(Engine::TexturesManager::getInstance()->get(1));
    }

    //////////////////////////////////////////////////

    SplashScreen::~SplashScreen()
    {
    }


    //////////////////////////////////////////////////

    void SplashScreen::update()
    {
        
        if (this->m_timer.getElapsedTime().asSeconds() > 1.5f)
        {
            this->m_data->m_screen.addSreen(Engine::ScreenPtr(new MenuScreen(this->m_data)));
        }
        
    }

    //////////////////////////////////////////////////

    void SplashScreen::draw()
    {
        this->m_data->m_window.draw(this->m_background);

        this->m_data->m_gui.draw();
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

        this->m_data->m_gui.handleEvent(event);
    }
}