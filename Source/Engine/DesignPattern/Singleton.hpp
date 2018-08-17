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
    template<class Template>
    class Singleton
    {
    protected:
        static Template*              m_instance;

    public:
        Singleton() = default;
        ~Singleton() = default;

        static void init()
        {
            if (m_instance == nullptr)
                m_instance = new Template();
        }

        ///////////////////////////////////////

        static void release()
        {
            if (m_instance != nullptr)
            {
                delete m_instance;

                m_instance = nullptr;
            }
        }

        ///////////////////////////////////////

        static Template* getInstance()
        {
            return m_instance;
        }
    };

    template<class Template>
    Template* Singleton<Template>::m_instance = nullptr;
}

#endif  //   _SpaceWar_Singleton_HPP_