/*
**   Project: Space War
**   File: QuadTree.hpp
*/

#ifndef _SpaceWar_QuadTree_HPP_
#define _SpaceWar_QuadTree_HPP_

#include <SFML/Graphics.hpp>
#include <list>
#include "../../Entity/BaseEntity/BaseEntity.hpp"
#include "../Graphics/FrameBox.hpp"
#include "../../Config.hpp"

#define MAX_LEVEL   4
#define MAX_ENTITY  5

//   Diagram of nodes

/*************
**     *     *
**  1  *  2  *
**     *     *
**************
**     *     *
**  4  *  3  *
**     *     *
*************/

namespace Engine
{
    class QuadTree
    {
    private:
        int                 m_level;

        sf::FloatRect       m_region;


        QuadTree*           m_node_1;
        QuadTree*           m_node_2;
        QuadTree*           m_node_3;
        QuadTree*           m_node_4;



    private:
        void slip();


    public:
        QuadTree(int level, sf::FloatRect region);

    };
}

#endif  //   _SpaceWar_QuadTree_HPP_