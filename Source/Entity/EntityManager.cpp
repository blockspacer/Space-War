/*
**   Project: Space War
**   File: EntityManager.cpp
*/

#include "EntityManager.hpp"

namespace Sw
{
    EntityManager::EntityManager()
    {
        this->m_list_entity = new std::vector<EntityPtr>;
    }

    /////////////////////////////////////////////////////

    std::vector<EntityPtr>* EntityManager::getListEntity()
    {
        return this->m_list_entity;
    }
}