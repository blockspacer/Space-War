/*
**   Project: Space War
**   File: Application.hpp
*/

#ifndef _SpaceWar_Application_HPP_
#define _SpaceWar_Application_HPP_

#include <SFML/Graphics.hpp>
#include "Screens/ScreenData.hpp"
#include "Screens/SplashScreen.hpp"
#include "TinyXML/tinyxml2.h"
#include "Config.hpp"
#include "Icon.hpp"

namespace Sw
{
    class Application
    {
    private:
        ScreenDataPtr         m_data;

        sf::Cursor            m_mouse;

    private:
        void loadData();

        void loadTextures();

        void loadFonts();

        void loadAudio();

        void loadShaders();

    public:
        Application();
        ~Application();

        //   The main loop of this game
        void run();

    };
}

#endif  //   _SpaceWar_Application_HPP_