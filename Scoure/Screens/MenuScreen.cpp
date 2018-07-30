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

#if defined(UNICODE)

        this->m_title_game.setTexture(this->m_data->m_texture->get(2));

#elif !defined(UNICODE)

        this->m_title_game.setTexture(this->m_data->m_texture->get(3));

#endif

        this->m_title_game.setOrigin((float)this->m_title_game.getTexture()->getSize().x / 2, (float)this->m_title_game.getTexture()->getSize().y / 2);

        this->m_title_game.setPosition(Screen_With / 2, Screen_Height / 2 - 180);
    }

    ////////////////////////////////////////////

    void MenuScreen::update()
    {

    }

    ////////////////////////////////////////////

    void MenuScreen::draw()
    {
        this->m_data->m_window.clear();

        this->m_data->m_window.draw(this->m_title_game);

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