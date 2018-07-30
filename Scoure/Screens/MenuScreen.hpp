/*
**   Project: Space War
**   File: MenuScreen.hpp
*/

#ifndef _SpaceWar_MenuScreen_HPP_
#define _SpaceWar_MenuScreen_HPP_

#include <SFML/Graphics.hpp>
#include "../Engine/ScreenManager/Screen.hpp"
#include "ScreenData.hpp"
#include "../Config.hpp"

namespace Sw
{
    class MenuScreen : public Engine::Screen
    {
    private:
        ScreenDataPtr               m_data;

        sf::Sprite                  m_title_game;

    public:
        MenuScreen(ScreenDataPtr data);


        void handleEvent() override;

        void update() override;

        void draw() override;

    };
}

#endif  //   _SpaceWar_MenuScreen_HPP_