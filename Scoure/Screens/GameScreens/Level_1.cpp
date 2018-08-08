/*
**   Project: Space War
**   File: Level_1.cpp
*/

#include "Level_1.hpp"

namespace Sw
{
    Level_1::Level_1(ScreenDataPtr data, GameScreenDataPtr data_game) :
        m_data(data),
        m_data_game(data_game)
    {
    }

    //////////////////////////////////////////////

    void Level_1::update()
    {

    }

    //////////////////////////////////////////////

    void Level_1::draw()
    {

    }

    //////////////////////////////////////////////
    
    void Level_1::handleEvent()
    {
        sf::Event event;

        while (this->m_data->m_window.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed)
                this->m_data->m_window.close();
        }

        this->m_data->m_gui.handleEvent(event);
    }
}