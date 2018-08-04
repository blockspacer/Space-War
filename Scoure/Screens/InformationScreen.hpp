/*
**   Project: Space War
**   File: InformationScreen.hpp
*/

#ifndef _SpaceWar_InformationScreen_HPP_
#define _SpaceWar_InformationScreen_HPP_

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
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