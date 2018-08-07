/*
**   Project: Space War
**   File: MenuScreen.hpp
*/

#ifndef _SpaceWar_MenuScreen_HPP_
#define _SpaceWar_MenuScreen_HPP_

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include "GameScreens/Level_1.hpp"
#include "InformationScreen.hpp"
#include "SettingScreen.hpp"
#include "ScreenData.hpp"
#include "../Engine/ScreenManager/Screen.hpp"
#include "../Config.hpp"
#include "../Icon.hpp"

namespace Sw
{
    class MenuScreen : public Engine::Screen
    {
    private:
        ScreenDataPtr               m_data;

        sf::Sprite                  m_title_game;

        sf::Sprite                  m_background;

        tgui::Button::Ptr           m_button_play;

        tgui::Button::Ptr           m_button_infor;

        tgui::Button::Ptr           m_button_setting;

        tgui::Button::Ptr           m_button_exit;

    private:
        void setupButton();

    public:
        MenuScreen(ScreenDataPtr data);
        ~MenuScreen();

        void handleEvent() override;

        void update() override;

        void draw() override;

        void pause() override;

        void resume() override;

    };
}

#endif  //   _SpaceWar_MenuScreen_HPP_