/*
**   Project: Space War
**   File: ScreenData.hpp
*/

#ifndef _SpaceWar_ScreenData_HPP_
#define _SpaceWar_ScreenData_HPP_

#include <SFML/Graphics.hpp>
#include <memory>
#include "../Engine/ScreenManager/ScreenManager.hpp"
#include "../Engine/Languages/LanguagesManager.hpp"
#include "../StaticValue.hpp"
#include "../Config.hpp"

namespace Sw
{
    struct ScreenData
    {
        sf::RenderWindow                m_window;
        Engine::ScreenManager           m_screen;
        Engine::LanguagesManager*       m_language;
        Engine::TexturesManager*        m_texture;
    };

    typedef std::shared_ptr<ScreenData> ScreenDataPtr;
}

#endif  //   _SpaceWar_ScreenData_HPP_
