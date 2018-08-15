/*
**   Project: Space War
**   File: FontsManager.cpp
*/

#ifndef _SpaceWar_FontsManager_HPP_
#define _SpaceWar_FontsManager_HPP_

#include <SFML/Graphics.hpp>
#include <map>
#include "../CommonFunction/CommonFunction.hpp"
#include "../../Config.hpp"

namespace Engine
{
    class FontsManager
    {
    private:
        std::map<int, sf::Font>         m_font;

    public:
        FontsManager() = default;
        ~FontsManager();


        //   Used to load sf::Texture
        void load(int ID, const char* Path);


        //   Used to get sf::Texture
        sf::Font& get(int ID);


        //   Remove sf::Texture
        void remove(int ID);

    };
}

#endif  //   _SpaceWar_FontsManager_HPP_