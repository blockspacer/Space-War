/*
**   Project: Space War
**   File: EntityManager.hpp
*/

#ifndef _SpaceWar_EntityManager_HPP_
#define _SpaceWar_EntityManager_HPP_

#include <iostream>
#include <vector>
#include "BaseEntity/BaseEntity.hpp"
#include "../Engine/DesignPattern/Singleton.hpp"
#include "../Config.hpp"

namespace Sw
{
    class EntityManager : public Engine::Singleton<EntityManager>
    {
    private:
        std::vector<EntityPtr>*        m_list_entity = nullptr;

    public:
        EntityManager();
        ~EntityManager();


        std::vector<EntityPtr>* getListEntity();
    };
}

#endif  //   _SpaceWar_EntityManager_HPP_