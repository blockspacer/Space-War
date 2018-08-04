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
        m_button_back(tgui::Button::create(Engine::LanguagesManager::getString(5)))
    {
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
        this->m_button_back->showWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.8f));
        this->m_button_back->connect("pressed", [&]() { this->m_data->m_screen.removeScreen(); });

        this->m_data->m_gui.add(this->m_button_back);
    }

    ///////////////////////////////////////////////////////////

    void InformationScreen::update()
    {

    }

    ///////////////////////////////////////////////////////////

    void InformationScreen::draw()
    {
        this->m_data->m_window.clear();

        this->m_data->m_window.draw(this->m_background);

        this->m_data->m_gui.draw();

        this->m_data->m_window.display();
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