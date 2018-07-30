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