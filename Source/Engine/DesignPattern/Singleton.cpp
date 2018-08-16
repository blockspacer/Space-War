/*
**   Project: Space War
**   File: Singleton.cpp
*/

#include "Singleton.hpp"

namespace Engine
{
    template<typename Template>
    Template* Singleton<Template>::m_instance = nullptr;

    ////////////////////////////////////////////////////

    template<typename Template>
    static Template* Singleton<Template>::getInstance()
    {
        if (m_instance == nullptr)
            m_instance = new Template();

        return m_instance;
    }
}