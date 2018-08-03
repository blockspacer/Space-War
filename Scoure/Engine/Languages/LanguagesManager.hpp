/*
**   Project: Space War
**   File: LanguagesManager.hpp
*/

#ifndef _SpaceWar_LanguagesManager_HPP_
#define _SpaceWar_LanguagesManager_HPP_

#include <string>
#include "LanguageValue.hpp"
#include "../../Config.hpp"

namespace Engine
{
    class LanguagesManager
    {
    public:
        static SwString getString(int ID);
    };
}

#endif  //   _SpaceWar_LanguagesManager_HPP_