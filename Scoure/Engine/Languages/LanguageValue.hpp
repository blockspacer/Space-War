/*
**   Project: Space War
**   File: LanguageValue.hpp
*/

#ifndef _SpaceWar_LanguageValue_HPP_
#define _SpaceWar_LanguageValue_HPP_

#include <string>
#include "../../Config.hpp"

#if defined(UNICODE)

static std::wstring s_language_value[9] = {
    L"Vào Chơi",
    L"Thông Tin Game",
    L"Cài Đặt",
    L"Thoát",
    L"Trở Về",
    L"1.0",
    L"Harding Adonis",
    L"Github",
};

#elif !defined(UNICODE)

static std::string s_language_value[9] = {
    "Play Game",
    "About Game",
    "Setting",
    "Exit",
    "Back",
    "1.0",
    "Harding Adonis",
    "Github",
};

#endif

#endif  //   _SpaceWar_LanguageValue_HPP_