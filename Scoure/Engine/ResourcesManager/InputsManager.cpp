/*
**   Project: Space War
**   File: InputsManager.cpp
*/

#include "InputsManager.hpp"

namespace Engine
{
    bool InputsManager::checkTextContainMouse(const sf::RenderWindow* window, const sf::Text& text)
    {
        if (window->hasFocus())
        {
            int x = (int)window->getView().getCenter().x - window->getSize().x / 2;
            int y = (int)window->getView().getCenter().y - window->getSize().y / 2;

            x = int(text.getGlobalBounds().left) - x;
            y = int(text.getGlobalBounds().top) - y;

            sf::IntRect temp(x, y, int(text.getGlobalBounds().width), int(text.getGlobalBounds().height));

            if (temp.contains(sf::Mouse::getPosition(*window)))
                return true;
        }

        return false;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////

    bool InputsManager::checkClickText(const sf::RenderWindow* window, const sf::Text& text, sf::Mouse::Button button)
    {
        if (checkTextContainMouse(window, text))
        {
            if (sf::Mouse::isButtonPressed(button))
                return true;
        }

        return false;
    }
}