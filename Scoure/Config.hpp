/*
**   Project: Space War
**   File: Config.hpp
*/

#ifndef _SpaceWar_Config_HPP_
#define _SpaceWar_Config_HPP_

#include <SFML/System.hpp>
#include <string>


#if (SFML_VERSION_MAJOR == 2)

    #if (SFML_VERSION_MINOR != 5)

        #error You have to use SFML 2.5.x

    #endif

#else

    #error You have to use SFML 2.5.x

#endif

#define Space_War_Version    1.0
#define PI                   3.14
#define DegToRad             PI / 180.0
#define RadToDeg             180.0 / PI


//   Should add define UNICODE if you want to use Unicode


#if defined(_WIN32)

    #include <Windows.h>

    #include <iostream>

    #define GAME_WINDOW

#else

    #if defined(__unix__)

        #include <iostream>

        #if defined(__linux__)

            #define GAME_LINUX

        #elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)

            #define GAME_FREEBSD

        #elif defined(__OpenBSD__)

            #define GAME_OPENBSD

        #else

            #error This game is not support this UNIX operating system

        #endif

    #endif

#endif


//   Information of Screen
#define Screen_Width          900
#define Screen_Height         550
#define Screen_Max_Frame      60
#define Time_A_Frame          sf::seconds(1.f / 60.f)

#define Screen_Play_Width_Min        0
#define Screen_Play_Height_Min       0
#define Screen_Play_Width_Max        4500
#define Screen_Play_Height_Max       2750


//   Define Language
#if defined(UNICODE)            //  Vietnamese

    #define Title_Game L"Chiến Tranh Vũ Trụ"

    #if (_MSC_VER == 1900)

        #define To_SwString std::to_wstring

    #elif (_MSC_VER != 1900) && defined(_MSC_VER)

        #error The version of Visual Studio is not support C++ 14

    #elif (__GNUC__ >= 6)

        #define To_SwString std::to_wstring

    #else

        #error The version of GNU is not support function std::to_wstring

    #endif

    #define SwString std::wstring

#elif !defined(UNICODE)          //   English

    #define Title_Game "Space War"

    #if (_MSC_VER == 1900)

        #define To_SwString std::to_string

    #elif (_MSC_VER != 1900) && defined(_MSC_VER)

        #error The version of Visual Studio is not support C++ 14

    #elif (__GNUC__ >= 5)

        #define To_SwString std::to_string

    #else

        #error The version of GNU is not support function std::to_string

    #endif

    #define SwString std::string

#endif

#endif  //   _SpaceWar_Config_HPP_