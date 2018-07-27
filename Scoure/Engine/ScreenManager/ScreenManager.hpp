/*
**   Project: Space War
**   File: ScreenManager.hpp
*/

#ifndef _SpaceWar_ScreenManager_HPP_
#define _SpaceWar_ScreenManager_HPP_

#include <iostream>
#include "Screen.hpp"
#include "../../Config.hpp"

namespace Engine
{
    class ScreenManager
    {
    private:
        ScreenPtr              m_belowScreen;
        ScreenPtr              m_currentScreen;

        bool                   m_drawOneScreen;

    public:
        ScreenManager();
        ~ScreenManager();



        //   Update the current Screen
        void update();

        //   Handle event in current Screen
        void handleEvent();

        //   Draw one or two Screen
        void draw();

        //   Add new Screen
        void addSreen(ScreenPtr screen, bool replace = true);

        //   Remove the current Screen
        void removeScreen();


        void setNumberScreenDraw(bool drawOneScreen = true);
    };
}

#endif  //   _SpaceWar_ScreenManager_HPP_