/*
**   Project: Space War
**   File: TexturesManager.hpp
*/

#ifndef _SpaceWar_TexturesManager_HPP_
#define _SpaceWar_TexturesManager_HPP_

#include <SFML/Graphics.hpp>
#include <map>
#include "../../Config.hpp"

namespace Engine
{
    class TexturesManager
    {
    private:
        std::map<int, sf::Texture>         m_texture;

    public:
        TexturesManager() = default;
        ~TexturesManager();

        //   Used to load sf::Texture
        void load(int ID, const char* Path);


        //   Used to get sf::Texture
        sf::Texture& get(int ID);


        //   Remove sf::Texture
        void remove(int ID);
    };
}

#endif  //   _SpaceWar_TexturesManager_HPP_