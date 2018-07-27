/*
**   Project: Space War
**   File: MenuScreen.cpp
*/

#include "MenuScreen.hpp"

namespace Sw
{
    MenuScreen::MenuScreen(ScreenDataPtr data) :
        m_data(data)
    {
    }

    ////////////////////////////////////////////

    void MenuScreen::update()
    {

    }

    ////////////////////////////////////////////

    void MenuScreen::draw()
    {
        this->m_data->m_window.clear();

        this->m_data->m_window.display();
    }

    ////////////////////////////////////////////

    void MenuScreen::handleEvent()
    {
        sf::Event event;

        while (this->m_data->m_window.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed)
                this->m_data->m_window.close();
        }
    }
}