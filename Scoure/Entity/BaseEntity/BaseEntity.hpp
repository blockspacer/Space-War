/*
**   Project: Space War
**   File: BaseEntity.hpp
*/

#ifndef _SpaceWar_BaseEntity_HPP_
#define _SpaceWar_BaseEntity_HPP_

#include <SFML/Graphics.hpp>
#include "../../Engine/Graphics/Hitbox.hpp"
#include "../../Engine/Graphics/Animation.hpp"

namespace Sw
{
    
    class BaseEntity : public sf::Sprite
    {
    protected:
        int                        m_currentHP;
        int                        m_maxHP;

        float                      m_speedMove;

        Engine::Hitbox             m_hitbox;

    public:
        BaseEntity();
        BaseEntity(const sf::Texture& texture) = delete;
        BaseEntity(const sf::Texture& texture, const sf::IntRect& rectangle);

        
        /*
        **   This function is used to update data of this
        */
        virtual void update() = 0;


        //   Return the pointer of Engine::Hitbox
        const Engine::Hitbox* getHitbox() const;


        //   Delete functions
        void setScale(float factorX, float factorY) = delete;
        void setScale(const sf::Vector2f& factors) = delete;
        void scale(float factorX, float factorY) = delete;
        void scale(const sf::Vector2f& factor) = delete;
    };


    typedef BaseEntity* EntityPtr;
}

#endif  //   _SpaceWar_BaseEntity_HPP_