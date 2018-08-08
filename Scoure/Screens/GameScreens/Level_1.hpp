/*
**   Project: Space War
**   File: Level_1.hpp
*/

#ifndef _SpaceWar_Level_1_HPP_
#define _SpaceWar_Level_1_HPP_

#include <SFML/Graphics.hpp>
#include "GameScreenData.hpp"
#include "../../Engine/ScreenManager/Screen.hpp"
#include "../ScreenData.hpp"
#include "../../Config.hpp"

namespace Sw
{
    class Level_1 : public Engine::Screen
    {
    private:
        ScreenDataPtr                    m_data;

        GameScreenDataPtr               m_data_game;

    public:
        Level_1(ScreenDataPtr data, GameScreenDataPtr data_game);


        void handleEvent();

        void update();

        void draw();

    };
}

#endif  //   _SpaceWar_Level_1_HPP_