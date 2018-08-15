/*
**   Project: Space War
**   File: QuadTree.cpp
*/

#include "QuadTree.hpp"

namespace Engine
{
    QuadTree::QuadTree(int level, sf::FloatRect region) :
        m_level(level),
        m_region(region)
    {

        this->m_node_1 = nullptr;

        this->m_node_2 = nullptr;

        this->m_node_3 = nullptr;

        this->m_node_4 = nullptr;

    }

    /////////////////////////////////////////////////////////

    void QuadTree::slip()
    {

    }
}