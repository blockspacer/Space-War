/*
**   Project: Space War
**   File: SettingScreen.hpp
*/

#ifndef _SpaceWar_SettingScreen_HPP_
#define _SpaceWar_SettingScreen_HPP_

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include "../Engine/ScreenManager/Screen.hpp"
#include "../TinyXML/tinyxml2.h"
#include "ScreenData.hpp"
#include "../Config.hpp"

namespace Sw
{
    class SettingScreen : public Engine::Screen
    {
    private:
        ScreenDataPtr               m_data;

        sf::Sprite                  m_background;

        sf::Sprite                  m_title;

        sf::Sprite                  m_set;

        sf::Text                    m_value_music;

        sf::Text                    m_value_sound;

        tgui::Slider::Ptr           m_slider_music;

        tgui::Slider::Ptr           m_slider_sound;

        tgui::Button::Ptr           m_button_back;

    private:
        void setupButton();

        void saveData();

    public:
        SettingScreen(ScreenDataPtr data);
        ~SettingScreen();

        void handleEvent() override;

        void update() override;

        void draw() override;

    };
}

#endif  //   _SpaceWar_SettingScreen_HPP_