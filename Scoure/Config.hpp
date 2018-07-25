/*
**   Project: Space War
**   File: Config.hpp
*/

#ifndef _SpaceWar_Config_HPP_
#define _SpaceWar_Config_HPP_

#include <string>

#define SpaceWarVersion    1.0.0
#define PI                 3.14
#define DegToRad           PI / 180.0


//   Should add define UNICODE


#if defined(_MSC_VER) || defined(__GNUC__)

    #include <Windows.h>

    #define GAME_WINDOW

#else

    #if defined(__unix__)

        #if defined(__linux__)

            #define GAME_LINUX

        #elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)

            #define GAME_FREEBSD

        #elif defined(__OpenBSD__)

            #define GAME_OPENBSD

        #else

            #error This game isn't supported this UNIX operating system

        #endif

    #endif

#endif

//   Information of Screen
#define Screen_With           850
#define Screen_Height         500
#define Screen_Max_Frame      60


static const std::string Path_Texture = "";

#endif  //   _SpaceWar_Config_HPP_