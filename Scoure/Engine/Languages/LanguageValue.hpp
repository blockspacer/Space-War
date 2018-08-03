/*
**   Project: Space War
**   File: LanguageValue.hpp
*/

#ifndef _SpaceWar_LanguageValue_HPP_
#define _SpaceWar_LanguageValue_HPP_

#include <string>
#include "../../Config.hpp"

#if defined(UNICODE)

static std::wstring s_language_value[5] = {
    L"Vào Chơi",
    L"Thông Tin Game",
    L"Cài Đặt",
    L"Thoát",
    L"Trở Về"
};

#elif !defined(UNICODE)

static std::string s_language_value[1] = {
    "Play Game",
};

#endif

#endif  //   _SpaceWar_LanguageValue_HPP_