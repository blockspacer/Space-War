/*
**   Project: Space War
**   File: AudioManager.cpp
*/

#include "AudioManager.hpp"

namespace Engine
{
    AudioManager::~AudioManager()
    {
        for (auto it = this->m_sounds.begin(); it != this->m_sounds.end(); it++)
            it->second.stop();

        for (auto it = this->m_musics.begin(); it != this->m_musics.end(); it++)
            it->second.stop();


        this->m_buffers.clear();

        this->m_sounds.clear();

        this->m_musics.clear();
    }

    ///////////////////////////////////////

    void AudioManager::loadMusic(int ID, const char* Path)
    {
        if (!this->m_musics[ID].openFromFile(Path))
            Engine::ExitMissingData();

#ifdef DEBUG_GAME

        std::cout << " + Load Music Success:   " << Path << std::endl;

#endif

    }
    
    ///////////////////////////////////////

    void AudioManager::loadSound(int ID, const char* Path)
    {
        if (!this->m_buffers[ID].loadFromFile(Path))
            Engine::ExitMissingData();

        this->m_sounds[ID].setBuffer(this->m_buffers[ID]);

#ifdef DEBUG_GAME

        std::cout << " + Load Sound Success: " << Path << std::endl;

#endif

    }

    ///////////////////////////////////////

    sf::Music* AudioManager::getMusic(int ID)
    {
        return &this->m_musics[ID];
    }

    ///////////////////////////////////////

    sf::Sound* AudioManager::getSound(int ID)
    {
        return &this->m_sounds[ID];
    }

    ///////////////////////////////////////

    void AudioManager::removeMusic(int ID)
    {
        this->m_musics.erase(this->m_musics.find(ID));
    }

    ///////////////////////////////////////

    void AudioManager::removeSound(int ID)
    {
        this->m_buffers.erase(this->m_buffers.find(ID));

        this->m_sounds.erase(this->m_sounds.find(ID));
    }

    ///////////////////////////////////////

    void AudioManager::setVolumeMusics(float volume)
    {
        this->m_volume_musics = volume;

        if (this->m_musics.size() > 0)
        {
            for (auto music = this->m_musics.begin(); music != this->m_musics.end(); music++)
                music->second.setVolume(this->m_volume_musics);
        }
    }

    ///////////////////////////////////////

    void AudioManager::setVolumeSounds(float volume)
    {
        this->m_volume_sounds = volume;

        if (this->m_sounds.size() > 0)
        {
            for (auto sound = this->m_sounds.begin(); sound != this->m_sounds.end(); sound++)
                sound->second.setVolume(this->m_volume_sounds);
        }
    }

    ///////////////////////////////////////

    float AudioManager::getVolumeMusics() const
    {
        return this->m_volume_musics;
    }

    ///////////////////////////////////////

    float AudioManager::getVolumeSounds() const
    {
        return this->m_volume_sounds;
    }
}