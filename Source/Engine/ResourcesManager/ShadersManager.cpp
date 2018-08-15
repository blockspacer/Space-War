/*
**   Project: Space War
**   File: ShadersManager.cpp
*/

#include "ShadersManager.hpp"

namespace Engine
{
    ShadersManager::~ShadersManager()
    {
        this->m_shaders.clear();
    }

    /////////////////////////////////////////////////

    void ShadersManager::load(int ID, const char* Path, sf::Shader::Type type)
    {
        if (!this->m_shaders[ID].loadFromFile(Path, type))
            Engine::ExitMissingData();

#ifdef _DEBUG

        std::cout << "Load Shader Success: " << Path << std::endl;

#endif

    }

    /////////////////////////////////////////////////

    void ShadersManager::load(int ID, const char* PathVert, const char* PathFrag)
    {
        if (!this->m_shaders[ID].loadFromFile(PathVert, PathFrag))
            Engine::ExitMissingData();

#ifdef _DEBUG

        std::cout << "Load Shader Success: " << PathVert << "  " << PathFrag << std::endl;

#endif

    }

    /////////////////////////////////////////////////

    sf::Shader* ShadersManager::get(int ID)
    {
        return &this->m_shaders[ID];
    }

    /////////////////////////////////////////////////

    void ShadersManager::remove(int ID)
    {
        this->m_shaders.erase(this->m_shaders.find(ID));
    }
}