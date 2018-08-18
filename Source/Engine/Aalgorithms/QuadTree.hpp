/*
**   Project: Space War
**   File: QuadTree.hpp
*/

#ifndef _SpaceWar_QuadTree_HPP_
#define _SpaceWar_QuadTree_HPP_

#include <SFML/Graphics.hpp>
#include <vector>
#include "../../Entity/EntityManager.hpp"
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
        int                           m_level;

        sf::FloatRect                 m_region;


        QuadTree*                     m_node_1;
        QuadTree*                     m_node_2;
        QuadTree*                     m_node_3;
        QuadTree*                     m_node_4;

#ifdef DEBUG_GAME

        FrameBox                       m_box;

#endif


        std::vector<Sw::EntityPtr>*   m_list_entity;

    private:
        void slip();

        bool isContain(Sw::EntityPtr entity);

    public:
        QuadTree(int level, sf::FloatRect region);

        //   Clear all nodes
        void clear();

        //   Insert a new Entity
        void insertEntity(Sw::EntityPtr entity);

#ifdef DEBUG_GAME

        void draw(sf::RenderTarget& target);

#endif

        //   Creat a new Quadtree
        static QuadTree* create(sf::FloatRect region);
    };
}

#endif  //   _SpaceWar_QuadTree_HPP_