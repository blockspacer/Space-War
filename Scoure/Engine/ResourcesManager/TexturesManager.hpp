/*
**   Project: Space War
**   File: TexturesManager.hpp
*/

#ifndef _SpaceWar_TexturesManager_HPP_
#define _SpaceWar_TexturesManager_HPP_

#include <SFML/Graphics.hpp>
#include <map>
#include "../../Config.hpp"

namespace Sw
{
    class TexturesManager
    {
    private:
        std::map<int, sf::Texture>         m_texture;

    public:
        TexturesManager() = default;
        ~TexturesManager();


        void load(int ID, const char* Path);

        
    };
}

#endif  //   _SpaceWar_TexturesManager_HPP_