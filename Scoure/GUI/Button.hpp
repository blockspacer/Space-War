/*
**   Project: Space War
**   File: Button.hpp
*/

#ifndef _SpaceWar_Button_HPP_
#define _SpaceWar_Button_HPP_

#include <SFML/Graphics.hpp>
#include "../Config.hpp"

namespace GUI
{
    class Button : public sf::Text
    {
    private:


    public:
        Button() = default;
        Button(const sf::String& string, const sf::Font& font, unsigned int characterSize = 30);

        ~Button() = default;

        bool checkContainMouse(const sf::RenderWindow* window);

        bool checkMouseClick(const sf::RenderWindow* window, sf::Mouse::Button button = sf::Mouse::Button::Left);
    };
}

#endif  //   _SpaceWar_Button_HPP_