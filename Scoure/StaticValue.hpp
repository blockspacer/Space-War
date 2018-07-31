/*
**   Project: Space War
**   File: StaticValue.hpp
*/

#ifndef _SpaceWar_StaticValue_HPP_
#define _SpaceWar_StaticValue_HPP_

#include "Engine/ResourcesManager/TexturesManager.hpp"
#include "Engine/ResourcesManager/FontsManager.hpp"
#include "Engine/Languages/LanguagesManager.hpp"
#include "Config.hpp"

namespace Sw
{
    static Engine::LanguagesManager  s_languages;

    static Engine::TexturesManager   s_textures;

    static Engine::FontsManager      s_fonts;
}

#endif  //   _SpaceWar_StaticValue_HPP_