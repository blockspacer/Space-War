/*
**   Project: Space War
**   File: ScreenData.hpp
*/

#ifndef _SpaceWar_ScreenData_HPP_
#define _SpaceWar_ScreenData_HPP_

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <memory>
#include "../Engine/Engine.hpp"
#include "../Entity/Entity.hpp"
#include "../Config.hpp"

namespace Sw
{
    struct ScreenData
    {
        sf::RenderWindow                m_window;

        tgui::Gui                       m_gui;
    };

    typedef std::shared_ptr<ScreenData> ScreenDataPtr;
}

#endif  //   _SpaceWar_ScreenData_HPP_
