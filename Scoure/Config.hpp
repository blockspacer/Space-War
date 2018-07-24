/*
**   Project: Space War
**   File: Config.hpp
*/

#ifndef _SpaceWar_Config_HPP_
#define _SpaceWar_Config_HPP_

#include <string>

#define SpaceWarVersion    1.0.0
#define PI                 3.14

#if defined(_MSC_VER) || defined(__GNUC__)

    #include <Windows.h>

    #define API_WINDOW

#elif defined(__linux__)

    #define API_LINUX

#endif

//   Information of Screen
#define Screen_With           850
#define Screen_Height         500
#define Screen_Max_Frame      60


static const std::string Path_Texture = "";

#endif  //   _SpaceWar_Config_HPP_