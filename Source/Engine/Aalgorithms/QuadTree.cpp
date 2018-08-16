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


        this->m_list_entity = new std::vector<Sw::EntityPtr>;
    }

    /////////////////////////////////////////////////////////

    void QuadTree::slip()
    {
        if (this->m_level < MAX_LEVEL)
        {
            this->m_node_1 = new QuadTree(this->m_level + 1,
                sf::FloatRect(this->m_region.left, this->m_region.top, this->m_region.width / 2, this->m_region.height / 2));

            this->m_node_2 = new QuadTree(this->m_level + 1,
                sf::FloatRect(this->m_region.left + this->m_region.width / 2, this->m_region.top, this->m_region.width / 2, this->m_region.height / 2));

            this->m_node_3 = new QuadTree(this->m_level + 1,
                sf::FloatRect(this->m_region.left + this->m_region.width / 2, this->m_region.top + this->m_region.height / 2, this->m_region.width / 2, this->m_region.height / 2));

            this->m_node_4 = new QuadTree(this->m_level + 1,
                sf::FloatRect(this->m_region.left, this->m_region.top + this->m_region.height / 2, this->m_region.width / 2, this->m_region.height / 2));
        }
    }

    /////////////////////////////////////////////////////////

    bool QuadTree::isContain(Sw::EntityPtr entity)
    {
        sf::FloatRect bound = entity->getGlobalBounds();

        return  bound.left + bound.width < this->m_region.left ||
                bound.top + bound.height < this->m_region.top ||
                bound.left > this->m_region.left + this->m_region.width ||
                bound.top > this->m_region.top + this->m_region.height;
    }

    /////////////////////////////////////////////////////////

    void QuadTree::clear()
    {
        if (this->m_node_1 != nullptr)
        {
            this->m_node_1->clear();
            this->m_node_2->clear();
            this->m_node_3->clear();
            this->m_node_4->clear();


            delete this->m_node_1;

            delete this->m_node_2;

            delete this->m_node_3;

            delete this->m_node_4;
        }

        this->m_list_entity->clear();
    }

    QuadTree* QuadTree::create(sf::FloatRect region)
    {
        QuadTree* quadtree = new QuadTree(1, region);

        return quadtree;
    }
}