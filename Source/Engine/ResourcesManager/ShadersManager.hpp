/*
**   Project: Space War
**   File: ShadersManager.hpp
*/

#ifndef _SpaceWar_ShadersManager_HPP_
#define _SpaceWar_ShadersManager_HPP_

#include <SFML/Graphics.hpp>
#include <map>
#include "../CommonFunction/CommonFunction.hpp"
#include "../../Config.hpp"

namespace Engine
{
    class ShadersManager
    {
    private:
        std::map<int, sf::Shader>       m_shaders;

    public:
        ShadersManager() = default;
        ~ShadersManager();


        void load(int ID, const char* Path, sf::Shader::Type type);


        void load(int ID, const char* PathVert, const char* PathFrag);

        
        sf::Shader* get(int ID);


        void remove(int ID);
    };
}

#endif  //   _SpaceWar_ShadersManager_HPP_