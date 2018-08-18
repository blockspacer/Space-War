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

#ifdef DEBUG_GAME

        this->m_box.setSize(sf::Vector2f(this->m_region.width, this->m_region.height));

        this->m_box.setPosition(this->m_region.left, this->m_region.top);

#endif


        this->m_node_1 = nullptr;

        this->m_node_2 = nullptr;

        this->m_node_3 = nullptr;

        this->m_node_4 = nullptr;


        this->m_list_entity = new std::vector<Sw::EntityPtr>;
    }

    /////////////////////////////////////////////////////////

    void QuadTree::slip()
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

    /////////////////////////////////////////////////////////

    bool QuadTree::isContain(Sw::EntityPtr entity)
    {
        sf::FloatRect bound = entity->getGlobalBounds();

        return !(   bound.left + bound.width < this->m_region.left ||
                    bound.top + bound.height < this->m_region.top ||
                    bound.left > this->m_region.left + this->m_region.width ||
                    bound.top > this->m_region.top + this->m_region.height  );
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
            this->m_node_1 = nullptr;

            delete this->m_node_2;
            this->m_node_2 = nullptr;

            delete this->m_node_3;
            this->m_node_3 = nullptr;

            delete this->m_node_4;
            this->m_node_4 = nullptr;
        }

        this->m_list_entity->clear();
    }

    void QuadTree::insertEntity(Sw::EntityPtr entity)
    {
        if (this->m_node_1 != nullptr)
        {
            if (this->m_node_1->isContain(entity))
                this->m_node_1->insertEntity(entity);

            if (this->m_node_2->isContain(entity))
                this->m_node_2->insertEntity(entity);

            if (this->m_node_3->isContain(entity))
                this->m_node_3->insertEntity(entity);

            if (this->m_node_4->isContain(entity))
                this->m_node_4->insertEntity(entity);

            return;
        }


        if (this->isContain(entity))
            this->m_list_entity->push_back(entity);


        //   Slip Node
        if (this->m_list_entity->size() > MAX_ENTITY && this->m_level < MAX_LEVEL)
        {
            this->slip();

            while (!this->m_list_entity->empty())
            {
                if (this->m_node_1->isContain(this->m_list_entity->back()))
                    this->m_node_1->insertEntity(this->m_list_entity->back());

                if (this->m_node_2->isContain(this->m_list_entity->back()))
                    this->m_node_2->insertEntity(this->m_list_entity->back());

                if (this->m_node_3->isContain(this->m_list_entity->back()))
                    this->m_node_3->insertEntity(this->m_list_entity->back());

                if (this->m_node_4->isContain(this->m_list_entity->back()))
                    this->m_node_4->insertEntity(this->m_list_entity->back());

                this->m_list_entity->pop_back();
            }
        }
    }

    /////////////////////////////////////////////////////////

    QuadTree* QuadTree::create(sf::FloatRect region)
    {
        QuadTree* quadtree = new QuadTree(1, region);

        auto list = Sw::EntityManager::getInstance()->getListEntity();

        for (auto it = list->begin(); it != list->end(); it++)
            quadtree->insertEntity(*it);

        return quadtree;
    }

    /////////////////////////////////////////////////////////

#ifdef DEBUG_GAME

    void QuadTree::draw(sf::RenderTarget& target)
    {
        target.draw(this->m_box);

        if (this->m_node_1 != nullptr)
        {
            this->m_node_1->draw(target);

            this->m_node_2->draw(target);

            this->m_node_3->draw(target);

            this->m_node_4->draw(target);
        }
    }

#endif

}