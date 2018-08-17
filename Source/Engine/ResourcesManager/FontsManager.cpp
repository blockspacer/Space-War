/*
**   Project: Space War
**   File: FontsManager.cpp
*/

#include "FontsManager.hpp"

namespace Engine
{
    FontsManager::~FontsManager()
    {
        this->m_font.clear();
    }

    /////////////////////////////////////////

    void FontsManager::load(int ID, const char* Path)
    {
        if (!this->m_font[ID].loadFromFile(Path))
            Engine::ExitMissingData();

#ifdef _DEBUG

        std::cout << " + Load Font Success:    " << Path << std::endl;

#endif

    }

    /////////////////////////////////////////

    sf::Font& FontsManager::get(int ID)
    {
        return this->m_font[ID];
    }

    /////////////////////////////////////////

    void FontsManager::remove(int ID)
    {
        this->m_font.erase(this->m_font.find(ID));
    }
}