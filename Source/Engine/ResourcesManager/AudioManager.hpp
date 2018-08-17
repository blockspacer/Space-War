/*
**   Project: Space War
**   File: AudioManager.hpp
*/

#ifndef _SpaceWar_AudioManager_HPP_
#define _SpaceWar_AudioManager_HPP_

#include <SFML/Audio.hpp>
#include <map>
#include "../CommonFunction/CommonFunction.hpp"
#include "../DesignPattern/Singleton.hpp"
#include "../../Config.hpp"

namespace Engine
{
    class AudioManager : public Singleton<AudioManager>
    {
    private:
        std::map<int, sf::Music>           m_musics;
        std::map<int, sf::SoundBuffer>     m_buffers;
        std::map<int, sf::Sound>           m_sounds;


    private:
        float         m_volume_musics;
        float         m_volume_sounds;

    public:
        AudioManager() = default;
        ~AudioManager();

        void loadMusic(int ID, const char* Path);

        void loadSound(int ID, const char* Path);

        sf::Music* getMusic(int ID);

        sf::Sound* getSound(int ID);

        void removeMusic(int ID);

        void removeSound(int ID);

        void setVolumeMusics(float volume);

        void setVolumeSounds(float volume);

        float getVolumeMusics() const;

        float getVolumeSounds() const;
    };
}

#endif  //   _SpaceWar_AudioManager_HPP_