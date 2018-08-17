/*
**   Project: Space War
**   File: SettingScreen.cpp
*/

#include "SettingScreen.hpp"

namespace Sw
{
    SettingScreen::SettingScreen(ScreenDataPtr data) :
        m_data(data),
        m_background(Engine::TexturesManager::getInstance()->get(4)),
        m_button_back(tgui::Button::create(Engine::LanguagesManager::getString(5))),
        m_value_music(To_SwString((int)Engine::AudioManager::getInstance()->getVolumeMusics()), Engine::FontsManager::getInstance()->get(1), 25),
        m_value_sound(To_SwString((int)Engine::AudioManager::getInstance()->getVolumeSounds()), Engine::FontsManager::getInstance()->get(1), 25),
        m_slider_music(tgui::Slider::create(0.f, 100.f)),
        m_slider_sound(tgui::Slider::create(0.f, 100.f))
    {

#if defined(UNICODE)

        this->m_title.setTexture(Engine::TexturesManager::getInstance()->get(7));

        this->m_set.setTexture(Engine::TexturesManager::getInstance()->get(11));

#else

        this->m_title.setTexture(this->m_data->m_textures->get(8));

        this->m_set.setTexture(this->m_data->m_textures->get(12));

#endif

        this->m_title.setOrigin(this->m_title.getGlobalBounds().width / 2, this->m_title.getGlobalBounds().height / 2);
        this->m_title.setPosition(Screen_Width / 2, 100);

        this->m_set.setOrigin(this->m_set.getGlobalBounds().width / 2, this->m_set.getGlobalBounds().height / 2);
        this->m_set.setPosition(Screen_Width / 2, Screen_Height / 2 + 30);


        this->m_value_music.setPosition(Screen_Width / 2 - 120, Screen_Height / 2 - 33);


        this->m_value_sound.setPosition(Screen_Width / 2 - 120, Screen_Height / 2 + 60);

        this->setupButton();
    }

    ///////////////////////////////////////////////////

    SettingScreen::~SettingScreen()
    {
        this->m_data->m_gui.remove(this->m_button_back);

        this->m_data->m_gui.remove(this->m_slider_music);

        this->m_data->m_gui.remove(this->m_slider_sound);
    }

    ///////////////////////////////////////////////////

    void SettingScreen::setupButton()
    {
        this->m_button_back->setSize(120.f, 30.f);
        this->m_button_back->setTextSize(20);
        this->m_button_back->setPosition(50.f, 480.f);
        this->m_button_back->showWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.3f));
        this->m_button_back->connect("pressed", [&]() { 

            this->saveData();

            this->m_data->m_screen.removeScreen(); 
        });



        this->m_slider_music->setSize(300, 15);
        this->m_slider_music->setPosition(Screen_Width / 2 - 60, Screen_Height / 2 - 25);
        this->m_slider_music->setValue(Engine::AudioManager::getInstance()->getVolumeMusics());

        this->m_slider_sound->setSize(300, 15);
        this->m_slider_sound->setPosition(Screen_Width / 2 - 60, Screen_Height / 2 + 70);
        this->m_slider_sound->setValue(Engine::AudioManager::getInstance()->getVolumeSounds());


        this->m_data->m_gui.add(this->m_button_back);

        this->m_data->m_gui.add(this->m_slider_music);

        this->m_data->m_gui.add(this->m_slider_sound);
    }
    
    ///////////////////////////////////////////////////

    void SettingScreen::saveData()
    {
        tinyxml2::XMLDocument document_music;

        if (document_music.LoadFile("Data/Musics.xml") == tinyxml2::XMLError::XML_ERROR_FILE_NOT_FOUND)
            exit(EXIT_FAILURE);


        int volume_music = (int)this->m_slider_music->getValue();
        document_music.FirstChildElement()->SetAttribute("volume", volume_music);

        document_music.SaveFile("Data/Musics.xml");





        tinyxml2::XMLDocument document_sound;

        if (document_sound.LoadFile("Data/Sounds.xml") == tinyxml2::XMLError::XML_ERROR_FILE_NOT_FOUND)
            exit(EXIT_FAILURE);


        int volume_sound = (int)this->m_slider_music->getValue();
        document_sound.FirstChildElement()->QueryIntAttribute("volume", &volume_sound);

        document_sound.SaveFile("Data/Sounds.xml");

    }

    ///////////////////////////////////////////////////

    void SettingScreen::update()
    {
        
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && this->m_data->m_window.hasFocus())
        {
            this->m_value_music.setString(To_SwString((int)this->m_slider_music->getValue()));

            Engine::AudioManager::getInstance()->setVolumeMusics(this->m_slider_music->getValue());


            this->m_value_sound.setString(To_SwString((int)this->m_slider_sound->getValue()));

            Engine::AudioManager::getInstance()->setVolumeSounds(this->m_slider_sound->getValue());
        }

    }

    ///////////////////////////////////////////////////

    void SettingScreen::draw()
    {
        this->m_data->m_window.draw(this->m_background);

        this->m_data->m_window.draw(this->m_set);

        this->m_data->m_window.draw(this->m_value_music);

        this->m_data->m_window.draw(this->m_value_sound);

        this->m_data->m_window.draw(this->m_title);

        this->m_data->m_gui.draw();
    }

    ///////////////////////////////////////////////////

    void SettingScreen::handleEvent()
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