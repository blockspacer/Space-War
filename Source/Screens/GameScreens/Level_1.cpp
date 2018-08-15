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

    void Level_1::setView()
    {
        if (this->m_data_game->m_view.getCenter().x <= 200.f)
            this->m_data_game->m_view.setCenter(200.f, this->m_data_game->m_view.getCenter().y);
        else if (this->m_data_game->m_view.getCenter().x >= Screen_Play_Width_Max - 200.f)
            this->m_data_game->m_view.setCenter(Screen_Play_Width_Max - 200.f, this->m_data_game->m_view.getCenter().y);

        if (this->m_data_game->m_view.getCenter().y <= 200.f)
            this->m_data_game->m_view.setCenter(this->m_data_game->m_view.getCenter().x, 200.f);
        else if (this->m_data_game->m_view.getCenter().y >= Screen_Play_Height_Max - 200.f)
            this->m_data_game->m_view.setCenter(this->m_data_game->m_view.getCenter().x, Screen_Play_Height_Max - 200.f);
    }

    void Level_1::update()
    {
        if (this->m_data->m_window.hasFocus())
        {
            this->m_data_game->m_player->update();
            this->m_data_game->m_player->setPositionMouse(sf::Mouse::getPosition(this->m_data->m_window) + 
                sf::Vector2i(int(this->m_data_game->m_view.getCenter().x - this->m_data->m_window.getDefaultView().getCenter().x),
                    int(this->m_data_game->m_view.getCenter().y - this->m_data->m_window.getDefaultView().getCenter().y)));
        }

        this->m_data_game->m_view.setCenter(this->m_data_game->m_player->getPosition());

        this->setView();

        this->m_data->m_window.setView(this->m_data_game->m_view);
    }

    //////////////////////////////////////////////

    void Level_1::draw()
    {
        this->m_data->m_window.draw(this->m_data_game->m_background);

        this->m_data->m_gui.draw();

        this->m_data->m_window.draw(*this->m_data_game->m_player);

        this->m_data_game->m_player->drawGun(this->m_data->m_window);
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