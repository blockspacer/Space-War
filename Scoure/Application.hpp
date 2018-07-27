/*
**   Project: Space War
**   File: Application.hpp
*/

#ifndef _SpaceWar_Application_HPP_
#define _SpaceWar_Application_HPP_

#include <SFML/Graphics.hpp>
#include "Screens/ScreenData.hpp"
#include "Screens/SplashScreen.hpp"
#include "Config.hpp"

namespace Sw
{
    class Application
    {
    private:
        ScreenDataPtr         m_data;


    public:
        Application();
        ~Application();

        //   The main loop of this game
        void run();

    };
}

#endif  //   _SpaceWar_Application_HPP_