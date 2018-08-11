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
        this->m_data->m_textures    = &s_textures;
        this->m_data->m_fonts       = &s_fonts;
        this->m_data->m_shaders     = &s_shaders;
        this->m_data->m_audio       = &s_audio;


        //   Create Window
        this->m_data->m_window.create(sf::VideoMode(Screen_Width, Screen_Height), Title_Game, sf::Style::Close);
        this->m_data->m_window.setFramerateLimit(Screen_Max_Frame);


        //   Set GUI
        this->m_data->m_gui.setTarget(this->m_data->m_window);
        this->m_data->m_gui.setFont(this->m_data->m_fonts->get(1));


        //   Set mouse
        s_mouse.loadFromPixels(s_normal_mouse.pixel_data, sf::Vector2u(s_normal_mouse.width, s_normal_mouse.height), sf::Vector2u(5u, 5u));
        this->m_data->m_window.setMouseCursor(s_mouse);


        //   Set Icon
        this->m_data->m_window.setIcon(s_icon.width, s_icon.height, s_icon.pixel_data);


        //   Add new Screen
        this->m_data->m_screen.addSreen(Engine::ScreenPtr(new SplashScreen(this->m_data)));
    }

    ////////////////////////////////////////////////

    Application::~Application()
    {
        this->m_data->m_gui.removeAllWidgets();
    }

    ////////////////////////////////////////////////

    void Application::loadData()
    {

#ifdef _DEBUG

        std::cout << "Space War - DEBUG: Load Data\n";

#endif

        this->loadTextures();

        this->loadFonts();

        this->loadShaders();

        this->loadAudio();

    }

    ////////////////////////////////////////////////

    void Application::loadTextures()
    {
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
    }

    ////////////////////////////////////////////////

    void Application::loadFonts()
    {
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
    }

    ////////////////////////////////////////////////

    void Application::loadAudio()
    {
        tinyxml2::XMLDocument document_music;

        if (document_music.LoadFile("Data/Musics.xml") == tinyxml2::XMLError::XML_ERROR_FILE_NOT_FOUND)
            exit(EXIT_FAILURE);

        tinyxml2::XMLElement* Volume_music = document_music.FirstChildElement();
        
        int volume_music;
        Volume_music->QueryIntAttribute("volume", &volume_music);

        tinyxml2::XMLElement* root_music = Volume_music->NextSiblingElement();

        for (auto music = root_music->FirstChildElement(); music != nullptr; music = music->NextSiblingElement())
        {
            int ID;

            music->QueryIntAttribute("ID", &ID);

            s_audio.loadMusic(ID, music->GetText());
        }

        s_audio.setVolumeMusics((float)volume_music);


        tinyxml2::XMLDocument document_sound;

        if (document_sound.LoadFile("Data/Sounds.xml") == tinyxml2::XMLError::XML_ERROR_FILE_NOT_FOUND)
            exit(EXIT_FAILURE);

        tinyxml2::XMLElement* Volume_sound = document_sound.FirstChildElement();

        int volume_sound;
        Volume_sound->QueryIntAttribute("volume", &volume_sound);

        tinyxml2::XMLElement* root_sound = Volume_sound->NextSiblingElement();

        for (auto sound = root_sound->FirstChildElement(); sound != nullptr; sound = sound->NextSiblingElement())
        {
            int ID;

            sound->QueryIntAttribute("ID", &ID);

            s_audio.loadSound(ID, sound->GetText());
        }

        s_audio.setVolumeSounds((float)volume_sound);

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


            this->m_data->m_window.clear();

            this->m_data->m_screen.draw();

            this->m_data->m_window.display();
        }
    }
}