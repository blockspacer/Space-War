/*
**   Project: Space War
**   File: Math.hpp
*/

#ifndef _SpaceWar_Math_HPP_
#define _SpaceWar_Math_HPP_

#include <cmath>
#include "Trigonometric/CosValue.hpp"
#include "Trigonometric/SinValue.hpp"
#include "Trigonometric/TanValue.hpp"
#include "../../Config.hpp"

namespace Engine
{
    class Math
    {
    public:
        static double sin(int degrees);

        static double cos(int degrees);

        static double tan(int degrees);
    };
}

#endif  //   _SpaceWar_Math_HPP_