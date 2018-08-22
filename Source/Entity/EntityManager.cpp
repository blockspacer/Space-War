/*
**   Project: Space War
**   File: EntityManager.cpp
*/

#include "EntityManager.hpp"

namespace Sw
{
    EntityManager::EntityManager()
    {
        if (this->m_list_entity == nullptr)
            this->m_list_entity = new std::vector<EntityPtr>;
    }

    /////////////////////////////////////////////////////

    EntityManager::~EntityManager()
    {
        this->m_list_entity->clear();

        delete this->m_list_entity;

        this->m_list_entity = nullptr;
    }

    /////////////////////////////////////////////////////

    std::vector<EntityPtr>* EntityManager::getListEntity()
    {
        return this->m_list_entity;
    }
}