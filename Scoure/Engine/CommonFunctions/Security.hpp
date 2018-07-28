/*
**   Project: Space War
**   File: Security.hpp
*/

#ifndef _SpaceWar_Security_HPP_
#define _SpaceWar_Security_HPP_

#include <fstream>
#include "../../Config.hpp"

namespace Engine
{
    class Security
    {
    public:
        //   Encode files
        static void encode(const char* Path);

        //   Decode files
        static void decode(const char* Path);
    };
}

#endif  //   _SpaceWar_Security_HPP_