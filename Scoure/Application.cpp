/*
**   Project: Space War
**   File: Application.cpp
*/

#include "Application.hpp"

namespace Sw
{
    Application::Application() :
        m_data(std::make_shared<ScreenData>())
    {
        //   Load Data
        this->loadData();

        //   Data Transmission
        this->m_data->m_languages   = &s_languages;
        this->m_data->m_textures    = &s_textures;
        this->m_data->m_fonts       = &s_fonts;
        this->m_data->m_shaders     = &s_shaders;
        this->m_data->m_audio       = &s_audio;


        this->m_data->m_window.create(sf::VideoMode(Screen_With, Screen_Height), Title_Game, sf::Style::Close);
        this->m_data->m_window.setFramerateLimit(Screen_Max_Frame);


        //   Set mouse
        this->m_mouse.loadFromPixels(s_normal_mouse.pixel_data, sf::Vector2u(s_normal_mouse.width, s_normal_mouse.height), sf::Vector2u(0u, 0u));
        this->m_data->m_window.setMouseCursor(this->m_mouse);


        //   Set Icon
        this->m_data->m_window.setIcon(s_icon.width, s_icon.height, s_icon.pixel_data);



        //   Add new Screen
        this->m_data->m_screen.addSreen(Engine::ScreenPtr(new SplashScreen(this->m_data)));


        
    }

    ////////////////////////////////////////////////

    Application::~Application()
    {
    }

    ////////////////////////////////////////////////

    void Application::loadData()
    {
        this->loadTextures();

        this->loadFonts();

        this->loadShaders();

        this->loadAudio();

    }

    ////////////////////////////////////////////////

    void Application::loadTextures()
    {
        //Engine::Security::decode("Data/Textures.xml");

        tinyxml2::XMLDocument document;

        if (document.LoadFile("Data/Textures.xml") == tinyxml2::XMLError::XML_ERROR_FILE_NOT_FOUND)
            exit(EXIT_FAILURE);

        tinyxml2::XMLElement* root = document.FirstChildElement();

        for (auto texture = root->FirstChildElement(); texture != nullptr; texture = texture->NextSiblingElement())
        {
            int ID;

            texture->QueryIntAttribute("ID", &ID);

            s_textures.load(ID, texture->GetText());
        }

        //Engine::Security::encode("Data/Textures.xml");
    }

    ////////////////////////////////////////////////

    void Application::loadFonts()
    {
        //Engine::Security::decode("Data/Fonts.xml");

        tinyxml2::XMLDocument document;
        
        if (document.LoadFile("Data/Fonts.xml") == tinyxml2::XMLError::XML_ERROR_FILE_NOT_FOUND)
            exit(EXIT_FAILURE);

        tinyxml2::XMLElement* root = document.FirstChildElement();

        for (auto font = root->FirstChildElement(); font != nullptr; font = font->NextSiblingElement())
        {
            int ID;

            font->QueryIntAttribute("ID", &ID);

            s_fonts.load(ID, font->GetText());
        }

        //Engine::Security::encode("Data/Fonts.xml");
    }

    ////////////////////////////////////////////////

    void Application::loadAudio()
    {


    }

    ////////////////////////////////////////////////

    void Application::loadShaders()
    {

    }

    ////////////////////////////////////////////////

    void Application::run()
    {
        sf::Time timeLastFrame = sf::Time::Zero;

        sf::Clock timer;

        while (this->m_data->m_window.isOpen())
        {
            this->m_data->m_screen.handleEvent();

            timeLastFrame += timer.restart();

            while (timeLastFrame > Time_A_Frame)
            {
                timeLastFrame -= Time_A_Frame;

                this->m_data->m_screen.handleEvent();

                this->m_data->m_screen.update();
            }

            this->m_data->m_screen.draw();
        }
    }
}