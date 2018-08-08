/*
**   Project: Space War
**   File: TexturesManager.cpp
*/

#include "TexturesManager.hpp"

namespace Engine
{
    TexturesManager::~TexturesManager()
    {
        this->m_texture.clear();
    }

    /////////////////////////////////////////

    void TexturesManager::load(int ID, const char* Path)
    {
        if (!this->m_texture[ID].loadFromFile(Path))
            Engine::ExitMissingData();

        this->m_texture[ID].setSmooth(true);

#ifdef _DEBUG

        std::cout << "Load Texture Success: " << Path << std::endl;

#endif
    }

    /////////////////////////////////////////

    sf::Texture& TexturesManager::get(int ID)
    {
        return this->m_texture[ID];
    }

    /////////////////////////////////////////

    void TexturesManager::remove(int ID)
    {
        this->m_texture.erase(this->m_texture.find(ID));
    }
}