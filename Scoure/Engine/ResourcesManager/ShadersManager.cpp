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
        {

#if defined(GAME_WINDOW)

    #if defined(UNICODE)

            MessageBox(nullptr, L"Có vẻ như không đủ dữ liệu để khởi động game !!!\nBạn vui lòng kiểm tra lại !!!", L"Thông Báo", MB_ICONHAND);

    #else

            MessageBox(nullptr, "Looks like there is not enough data to start the game !!!\nYou should check again !!!", "Notification", MB_ICONHAND);

#endif

#elif !defined(GAME_LINUX) || defined(GAME_FREEBSD) || defined(GAME_OPENBSD)

            std::cout << "Looks like there is not enough data to start the game !!!\nYou should check again !!!" std::endl;

            std::cin.get();

#endif

            exit(EXIT_FAILURE);

        }

#ifdef _DEBUG

        std::cout << "Load Shader Success: " << Path << std::endl;

#endif

    }

    /////////////////////////////////////////////////

    void ShadersManager::load(int ID, const char* PathVert, const char* PathFrag)
    {
        if (!this->m_shaders[ID].loadFromFile(PathVert, PathFrag))
        {

#if defined(GAME_WINDOW)

    #if defined(UNICODE)

            MessageBox(nullptr, L"Có vẻ như không đủ dữ liệu để khởi động game !!!\nBạn vui lòng kiểm tra lại !!!", L"Thông Báo", MB_ICONHAND);

    #else

            MessageBox(nullptr, "Looks like there is not enough data to start the game !!!\nYou should check again !!!", "Notification", MB_ICONHAND);

    #endif

#elif !defined(GAME_LINUX) || defined(GAME_FREEBSD) || defined(GAME_OPENBSD)

            std::cout << "Looks like there is not enough data to start the game !!!\nYou should check again !!!" std::endl;

            std::cin.get();

#endif

            exit(EXIT_FAILURE);

        }

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