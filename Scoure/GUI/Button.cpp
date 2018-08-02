/*
**   Project: Space War
**   File: Button.cpp
*/

#include "Button.hpp"

namespace GUI
{
    Button::Button(const sf::Texture& texture, const sf::IntRect& rectangle) :
        sf::Sprite(texture, rectangle)
    {
    }

    //////////////////////////////////////////////////////

    bool Button::checkContainMouse(const sf::RenderWindow* window)
    {
        if (window->hasFocus())
        {
            int x = int(window->getView().getCenter().x) - int(window->getSize().x / 2);
            int y = int(window->getView().getCenter().y) - int(window->getSize().y / 2);

            x = int(this->getGlobalBounds().left) - x;
            y = int(this->getGlobalBounds().top) - y;

            sf::IntRect temp(x, y, int(this->getGlobalBounds().width), int(this->getGlobalBounds().height));

            if (temp.contains(sf::Mouse::getPosition(*window)))
                return true;
        }

        return false;
    }

    //////////////////////////////////////////////////////

    bool Button::checkMouseClick(const sf::RenderWindow* window, sf::Mouse::Button button)
    {
        if (window->hasFocus() && sf::Mouse::isButtonPressed(button) && this->checkContainMouse(window))
            return true;

        return false;
    }
}