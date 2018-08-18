/*
**   Project: Space War
**   File: GameScreenData.hpp
*/

#ifndef _SpaceWar_GameScreenData_HPP_
#define _SpaceWar_GameScreenData_HPP_

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <memory>
#include "../../Engine/Aalgorithms/QuadTree.hpp"
#include "../../Entity/SpaceShip/Player.hpp"
#include "../../Config.hpp"

namespace Sw
{
    struct GameScreenData
    {
        sf::Sprite             m_background;

        sf::View               m_view;

        Engine::QuadTree*      m_quadtree;

        Player*                m_player;

        b2World*               m_world;
    };

    typedef std::shared_ptr<GameScreenData> GameScreenDataPtr;
}

#endif  //   _SpaceWar_GameScreenData_HPP_