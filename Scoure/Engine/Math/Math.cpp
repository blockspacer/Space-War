/*
**   Project: Space War
**   File: Math.cpp
*/

#include "Math.hpp"

namespace Engine
{
    double Math::sin(int degrees)
    {
        while (degrees > 359)
        {
            degrees -= 360;
        }

        while (degrees < 0)
        {
            degrees += 360;
        }

        return s_sin_value[degrees];
    }

    //////////////////////////////////////////

    double cos(int degrees)
    {
        while (degrees > 359)
        {
            degrees -= 360;
        }

        while (degrees < 0)
        {
            degrees += 360;
        }

        return s_cos_value[degrees];
    }
}