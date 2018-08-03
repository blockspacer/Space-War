/*
**   Project: Space War
**   File: LanguagesManager.cpp
*/

#include "LanguagesManager.hpp"

namespace Engine
{
    SwString LanguagesManager::getString(int ID)
    {
        return s_language_value[ID - 1];
    }
}