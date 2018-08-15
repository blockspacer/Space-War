/*
**   Project: Space War
**   File: InformationScreen.hpp
*/

#ifndef _SpaceWar_InformationScreen_HPP_
#define _SpaceWar_InformationScreen_HPP_

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include "../Engine/ResourcesManager/InputsManager.hpp"
#include "../Engine/ScreenManager/Screen.hpp"
#include "ScreenData.hpp"
#include "../Config.hpp"

namespace Sw
{
    class InformationScreen : public Engine::Screen
    {
    private:
        ScreenDataPtr               m_data;

        sf::Sprite                  m_background;

        sf::Sprite                  m_title;

        sf::Sprite                  m_infor;

        sf::Text                    m_version;

        sf::Text                    m_author;

        sf::Text                    m_source_code;

        sf::Clock                   m_timer;

        tgui::Button::Ptr           m_button_back;

    private:
        void setupButton();

    public:
        InformationScreen(ScreenDataPtr data);
        ~InformationScreen();

        void handleEvent() override;

        void update() override;

        void draw() override;

    };
}

#endif  //   _SpaceWar_InformationScreen_HPP_