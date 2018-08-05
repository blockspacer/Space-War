/*
**   Project: Space War
**   File: MenuScreen.cpp
*/

#include "MenuScreen.hpp"

namespace Sw
{
    MenuScreen::MenuScreen(ScreenDataPtr data) :
        m_data(data),
        m_background(m_data->m_textures->get(4)),
        m_button_play(tgui::Button::create(Engine::LanguagesManager::getString(1))),
        m_button_infor(tgui::Button::create(Engine::LanguagesManager::getString(2))),
        m_button_setting(tgui::Button::create(Engine::LanguagesManager::getString(3))),
        m_button_exit(tgui::Button::create(Engine::LanguagesManager::getString(4)))
    {

#if defined(UNICODE)

        this->m_title_game.setTexture(this->m_data->m_textures->get(2));

#elif !defined(UNICODE)

        this->m_title_game.setTexture(this->m_data->m_textures->get(3));

#endif

        this->m_title_game.setOrigin(this->m_title_game.getGlobalBounds().width / 2, this->m_title_game.getGlobalBounds().height / 2);
        this->m_title_game.setPosition(Screen_With / 2, 100);

        this->setupButton();

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

    void MenuScreen::setupButton()
    {
        this->m_button_play->setSize(200, 30);
        this->m_button_play->setTextSize(20);
        this->m_button_play->setPosition(Screen_With / 2 - 100, 200);
        this->m_button_play->showWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.3f));

        this->m_button_infor->setSize(200, 30);
        this->m_button_infor->setTextSize(20);
        this->m_button_infor->setPosition(Screen_With / 2 - 100, 270);
        this->m_button_infor->showWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.3f));
        this->m_button_infor->connect("pressed", [&]() { this->m_data->m_screen.addSreen(Engine::ScreenPtr(new InformationScreen(this->m_data)), false); });

        this->m_button_setting->setSize(200, 30);
        this->m_button_setting->setTextSize(20);
        this->m_button_setting->setPosition(Screen_With / 2 - 100, 340);
        this->m_button_setting->showWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.3f));

        this->m_button_exit->setSize(200, 30);
        this->m_button_exit->setTextSize(20);
        this->m_button_exit->setPosition(Screen_With / 2 - 100, 410);
        this->m_button_exit->showWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.3f));
        this->m_button_exit->connect("pressed", [&]() { this->m_data->m_window.close(); });


        //   Add button
        this->m_data->m_gui.add(this->m_button_play);
        this->m_data->m_gui.add(this->m_button_infor);
        this->m_data->m_gui.add(this->m_button_setting);
        this->m_data->m_gui.add(this->m_button_exit);
    }

    ////////////////////////////////////////////

    void MenuScreen::update()
    {
    }

    ////////////////////////////////////////////

    void MenuScreen::draw()
    {
        this->m_data->m_window.draw(this->m_background);

        this->m_data->m_window.draw(this->m_title_game);

        this->m_data->m_gui.draw();
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

        this->m_data->m_gui.handleEvent(event);
    }

    ////////////////////////////////////////////

    void MenuScreen::pause()
    {
        this->m_data->m_gui.remove(this->m_button_play);
        this->m_data->m_gui.remove(this->m_button_infor);
        this->m_data->m_gui.remove(this->m_button_setting);
        this->m_data->m_gui.remove(this->m_button_exit);
    }

    ////////////////////////////////////////////

    void MenuScreen::resume()
    {
        this->m_button_play->showWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.3f));
        this->m_button_infor->showWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.3f));
        this->m_button_setting->showWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.3f));
        this->m_button_exit->showWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.3f));

        this->m_data->m_gui.add(this->m_button_play);
        this->m_data->m_gui.add(this->m_button_infor);
        this->m_data->m_gui.add(this->m_button_setting);
        this->m_data->m_gui.add(this->m_button_exit);
    }
}