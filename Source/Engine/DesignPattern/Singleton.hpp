/*
**   Project: Space War
**   File: Singleton.hpp
*/

#ifndef _SpaceWar_Singleton_HPP_
#define _SpaceWar_Singleton_HPP_

#include <iostream>
#include "../../Config.hpp"

namespace Engine
{
    template<typename Template>
    class Singleton
    {
    protected:
        static Template*              m_instance;

    public:
        Singleton() = default;
        ~Singleton() = default;


        static Template* getInstance();
    };
}

#endif  //   _SpaceWar_Singleton_HPP_