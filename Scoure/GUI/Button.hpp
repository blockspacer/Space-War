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
    class Button : public sf::Sprite
    {
    private:


    public:
        Button() = default;
        Button(const sf::Texture& texture, const sf::IntRect& rectangle);

        ~Button() = default;

        bool checkContainMouse(const sf::RenderWindow* window);

        bool checkMouseClick(const sf::RenderWindow* window, sf::Mouse::Button button = sf::Mouse::Button::Left);
    };
}

#endif  //   _SpaceWar_Button_HPP_