/*
**   Project: Space War
**   File: InputsManager.hpp
*/

#ifndef _SpaceWar_InputsManager_HPP_
#define _SpaceWar_InputsManager_HPP_

#include <SFML/Graphics.hpp>
#include "../../Config.hpp"

namespace Engine
{
    class InputsManager
    {
    public:
        static bool checkTextContainMouse(const sf::RenderWindow* window, const sf::Text& text);

        static bool checkClickText(const sf::RenderWindow* window, const sf::Text& text, sf::Mouse::Button button = sf::Mouse::Button::Left);
    };
}

#endif  //   _SpaceWar_InputsManager_HPP_