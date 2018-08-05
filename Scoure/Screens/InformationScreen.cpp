/*
**   Project: Space War
**   File: InformationScreen.cpp
*/

#include "InformationScreen.hpp"

namespace Sw
{
    InformationScreen::InformationScreen(ScreenDataPtr data) :
        m_data(data),
        m_background(m_data->m_textures->get(4)),
        m_button_back(tgui::Button::create(Engine::LanguagesManager::getString(5))),
        m_version(Engine::LanguagesManager::getString(6), m_data->m_fonts->get(1), 25),
        m_author(Engine::LanguagesManager::getString(7), m_data->m_fonts->get(1), 25),
        m_source_code(Engine::LanguagesManager::getString(8), m_data->m_fonts->get(1), 25)
    {

#if defined(UNICODE)

        this->m_title.setTexture(this->m_data->m_textures->get(5));

        this->m_infor.setTexture(this->m_data->m_textures->get(9));

#else

        this->m_title.setTexture(this->m_data->m_textures->get(6));

        this->m_infor.setTexture(this->m_data->m_textures->get(10));

#endif
        this->m_title.setOrigin(this->m_title.getGlobalBounds().width / 2, this->m_title.getGlobalBounds().height / 2);
        this->m_title.setPosition(Screen_With / 2, 100);


        this->m_infor.setOrigin(this->m_infor.getGlobalBounds().width / 2, this->m_infor.getGlobalBounds().height / 2);
        this->m_infor.setPosition(Screen_With / 2, Screen_Height / 2 + 30);

        //   Version
        this->m_version.setOrigin(this->m_version.getGlobalBounds().width / 2, this->m_version.getGlobalBounds().height / 2);
        this->m_version.setPosition(Screen_With / 2 + 30, Screen_Height / 2 - 60);


        //   Author
        this->m_author.setOrigin(this->m_author.getGlobalBounds().width / 2, this->m_author.getGlobalBounds().height / 2);
        this->m_author.setPosition(Screen_With / 2 + 30, Screen_Height / 2 + 25);


        //   Source Code
        this->m_source_code.setOrigin(this->m_source_code.getGlobalBounds().width / 2, this->m_source_code.getGlobalBounds().height / 2);
        this->m_source_code.setPosition(Screen_With / 2 + 30, Screen_Height / 2 + 105);

        this->setupButton();
    }

    ///////////////////////////////////////////////////////////

    InformationScreen::~InformationScreen()
    {
        this->m_data->m_gui.remove(this->m_button_back);
    }

    ///////////////////////////////////////////////////////////

    void InformationScreen::setupButton()
    {
        this->m_button_back->setSize(120.f, 30.f);
        this->m_button_back->setTextSize(20);
        this->m_button_back->setPosition(50.f, 480.f);
        this->m_button_back->showWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.3f));
        this->m_button_back->connect("pressed", [&]() { this->m_data->m_screen.removeScreen(); });

        this->m_data->m_gui.add(this->m_button_back);
    }

    ///////////////////////////////////////////////////////////

    void InformationScreen::update()
    {



        //   Author
        if (Engine::InputsManager::checkTextContainMouse(&this->m_data->m_window, this->m_author))
        {
            this->m_author.setFillColor(sf::Color::Red);

#if defined(GAME_WINDOW)

            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && this->m_timer.getElapsedTime().asSeconds() >= 0.1f)
            {

    #if defined(UNICODE)

                ShellExecute(nullptr, nullptr, L"https://www.facebook.com/adonis.harding", nullptr, nullptr, SW_SHOWNORMAL);

                ShellExecute(nullptr, nullptr, L"https://www.youtube.com/channel/UCnYMYeV2Y_2bGxoyDBKdT-A?view_as=subscriber", nullptr, nullptr, SW_SHOWNORMAL);

    #else

                ShellExecute(nullptr, nullptr, "https://www.facebook.com/adonis.harding", nullptr, nullptr, SW_SHOWNORMAL);

                ShellExecute(nullptr, nullptr, "https://www.youtube.com/channel/UCnYMYeV2Y_2bGxoyDBKdT-A?view_as=subscriber", nullptr, nullptr, SW_SHOWNORMAL);

    #endif

                this->m_timer.restart();
            }

#endif

        }
        else this->m_author.setFillColor(sf::Color::White);


        //   Source Code
        if (Engine::InputsManager::checkTextContainMouse(&this->m_data->m_window, this->m_source_code))
        {
            this->m_source_code.setFillColor(sf::Color::Red);

#if defined(GAME_WINDOW)

            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && this->m_timer.getElapsedTime().asSeconds() >= 0.1f)
            {

    #if defined(UNICODE)

                ShellExecute(nullptr, nullptr, L"https://github.com/hardingadonis/Space-War", nullptr, nullptr, SW_SHOWNORMAL);

    #else

                ShellExecute(nullptr, nullptr, "https://github.com/hardingadonis/Space-War", nullptr, nullptr, SW_SHOWNORMAL);

    #endif

                this->m_timer.restart();
            }

#endif

        }
        else this->m_source_code.setFillColor(sf::Color::White);



    }

    ///////////////////////////////////////////////////////////

    void InformationScreen::draw()
    {
        this->m_data->m_window.draw(this->m_background);

        this->m_data->m_window.draw(this->m_title);

        this->m_data->m_window.draw(this->m_infor);

        this->m_data->m_window.draw(this->m_version);

        this->m_data->m_window.draw(this->m_author);

        this->m_data->m_window.draw(this->m_source_code);

        this->m_data->m_gui.draw();
    }

    ///////////////////////////////////////////////////////////

    void InformationScreen::handleEvent()
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