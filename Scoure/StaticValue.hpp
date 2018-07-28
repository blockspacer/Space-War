/*
**   Project: Space War
**   File: StaticValue.hpp
*/

#ifndef _SpaceWar_StaticValue_HPP_
#define _SpaceWar_StaticValue_HPP_

#include "Engine/ResourcesManager/TexturesManager.hpp"
#include "Engine/Languages/LanguagesManager.hpp"
#include "Config.hpp"

namespace Sw
{
    static Engine::LanguagesManager s_language;

    static Engine::TexturesManager s_textures;
}

#endif  //   _SpaceWar_StaticValue_HPP_