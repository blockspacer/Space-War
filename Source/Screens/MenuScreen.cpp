/*
**   Project: Space War
**   File: MenuScreen.cpp
*/

#include "MenuScreen.hpp"

namespace Sw
{
    MenuScreen::MenuScreen(ScreenDataPtr data) :
        m_data(data),
        m_data_game(std::make_shared<GameScreenData>()),
        m_background(Engine::TexturesManager::getInstance()->get(4)),
        m_button_play(tgui::Button::create(Engine::LanguagesManager::getString(1))),
        m_button_infor(tgui::Button::create(Engine::LanguagesManager::getString(2))),
        m_button_setting(tgui::Button::create(Engine::LanguagesManager::getString(3))),
        m_button_exit(tgui::Button::create(Engine::LanguagesManager::getString(4)))
    {

#if defined(UNICODE)

        this->m_title_game.setTexture(Engine::TexturesManager::getInstance()->get(2));

#elif !defined(UNICODE)

        this->m_title_game.setTexture(this->m_data->m_textures->get(3));

#endif

        this->m_title_game.setOrigin(this->m_title_game.getGlobalBounds().width / 2, this->m_title_game.getGlobalBounds().height / 2);
        this->m_title_game.setPosition(Screen_Width / 2, 100);

        this->setupButton();

        //   Play sound
        Engine::AudioManager::getInstance()->getMusic(1)->setLoop(true);
        Engine::AudioManager::getInstance()->getMusic(1)->play();
    }

    ////////////////////////////////////////////

    MenuScreen::~MenuScreen()
    {
        Engine::AudioManager::getInstance()->getMusic(1)->stop();
    }

    ////////////////////////////////////////////

    void MenuScreen::setupButton()
    {
        this->m_button_play->setSize(200, 30);
        this->m_button_play->setTextSize(20);
        this->m_button_play->setPosition(Screen_Width / 2 - 100, 200);
        this->m_button_play->showWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.3f));
        this->m_button_play->connect("pressed", [&]() {

            s_mouse.loadFromPixels(s_mouse_shoot.pixel_data, sf::Vector2u(s_mouse_shoot.width, s_mouse_shoot.height), sf::Vector2u(s_mouse_shoot.width / 2, s_mouse_shoot.height / 2));
            this->m_data->m_window.setMouseCursor(s_mouse);
            this->m_data->m_window.setMouseCursorGrabbed(true);

            Engine::AudioManager::getInstance()->getMusic(1)->stop();

            this->m_data_game->m_background.setTexture(Engine::TexturesManager::getInstance()->get(13));
            this->m_data_game->m_background.setOrigin(this->m_data_game->m_background.getGlobalBounds().width / 2, this->m_data_game->m_background.getGlobalBounds().height / 2);
            this->m_data_game->m_background.setPosition(Screen_Width * 2.5f, Screen_Height * 2.5f);

            this->m_data_game->m_player = new Player(Engine::TexturesManager::getInstance()->get(14), Engine::TexturesManager::getInstance()->get(15));
            this->m_data_game->m_world = new b2World(b2Vec2(0.f, 0.f));

            this->m_data_game->m_view = this->m_data->m_window.getView();

            this->m_data->m_screen.addSreen(Engine::ScreenPtr(new Level_1(this->m_data, this->m_data_game)), false);

        } );

        this->m_button_infor->setSize(200, 30);
        this->m_button_infor->setTextSize(20);
        this->m_button_infor->setPosition(Screen_Width / 2 - 100, 270);
        this->m_button_infor->showWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.3f));
        this->m_button_infor->connect("pressed", [&]() { this->m_data->m_screen.addSreen(Engine::ScreenPtr(new InformationScreen(this->m_data)), false); });

        this->m_button_setting->setSize(200, 30);
        this->m_button_setting->setTextSize(20);
        this->m_button_setting->setPosition(Screen_Width / 2 - 100, 340);
        this->m_button_setting->showWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.3f));
        this->m_button_setting->connect("pressed", [&]() { this->m_data->m_screen.addSreen(Engine::ScreenPtr(new SettingScreen(this->m_data)), false); });

        this->m_button_exit->setSize(200, 30);
        this->m_button_exit->setTextSize(20);
        this->m_button_exit->setPosition(Screen_Width / 2 - 100, 410);
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