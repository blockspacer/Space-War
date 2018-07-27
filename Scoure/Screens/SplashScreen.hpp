/*
**   Project: Space War
**   File: SplashScreen.hpp
*/

#ifndef _SpaceWar_SplashScreen_HPP_
#define _SpaceWar_SplashScreen_HPP_

#include <SFML/Graphics.hpp>
#include "../Engine/ScreenManager/Screen.hpp"
#include "ScreenData.hpp"
#include "../Config.hpp"

namespace Sw
{
    class SplashScreen : public Engine::Screen
    {
    private:
        ScreenDataPtr               m_data;

    public:
        SplashScreen(ScreenDataPtr data);


        void handleEvent() override;

        void update() override;

        void draw() override;

    };
}

#endif  //   _SpaceWar_SplashScreen_HPP_