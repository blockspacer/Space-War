/*
**   Project: Space War
**   File: MenuScreen.cpp
*/

#include "MenuScreen.hpp"

namespace Sw
{
    MenuScreen::MenuScreen(ScreenDataPtr data) :
        m_data(data),
        m_button_play(m_data->m_textures->get(4), sf::IntRect(0, 0, 120, 60))
    {

#if defined(UNICODE)

        this->m_title_game.setTexture(this->m_data->m_textures->get(2));

#elif !defined(UNICODE)

        this->m_title_game.setTexture(this->m_data->m_textures->get(3));

#endif

        this->m_title_game.setOrigin(this->m_title_game.getGlobalBounds().width / 2, this->m_title_game.getGlobalBounds().height / 2);
        this->m_title_game.setPosition(Screen_With / 2, 80);


        //   Setup Button
        this->m_button_play.setOrigin(this->m_button_play.getGlobalBounds().width / 2, this->m_button_play.getGlobalBounds().height / 2);
        this->m_button_play.setPosition(Screen_With / 2, 220);


        //   Play sound
        this->m_data->m_audio->getMusic(1)->setLoop(true);
        this->m_data->m_audio->getMusic(1)->play();
    }

    ////////////////////////////////////////////

    MenuScreen::~MenuScreen()
    {
        this->m_data->m_audio->getMusic(1)->stop();
    }

    ////////////////////////////////////////////

    void MenuScreen::update()
    {
        if (this->m_button_play.checkContainMouse(&this->m_data->m_window))

            this->m_button_play.setTextureRect(sf::IntRect(120, 0, 120, 60));

        else this->m_button_play.setTextureRect(sf::IntRect(0, 0, 120, 60));

    }

    ////////////////////////////////////////////

    void MenuScreen::draw()
    {
        this->m_data->m_window.clear();

        this->m_data->m_window.draw(this->m_title_game);

        this->m_data->m_window.draw(this->m_button_play);

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