/*
**   Project: Space War
**   File: StaticValue.hpp
*/

#ifndef _SpaceWar_StaticValue_HPP_
#define _SpaceWar_StaticValue_HPP_

#include "Engine/ResourcesManager/TexturesManager.hpp"
#include "Engine/ResourcesManager/FontsManager.hpp"
#include "Engine/ResourcesManager/ShadersManager.hpp"
#include "Engine/ResourcesManager/AudioManager.hpp"
#include "Engine/Languages/LanguagesManager.hpp"
#include "Config.hpp"

namespace Sw
{
    static Engine::LanguagesManager  s_languages;

    static Engine::TexturesManager   s_textures;

    static Engine::FontsManager      s_fonts;

    static Engine::ShadersManager    s_shaders;

    static Engine::AudioManager      s_audio;
}

#endif  //   _SpaceWar_StaticValue_HPP_