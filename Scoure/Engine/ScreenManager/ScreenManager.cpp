/*
**   Project: Space War
**   File: ScreenManager.cpp
*/

#include "ScreenManager.hpp"

namespace Engine
{
    ScreenManager::ScreenManager() :
        m_belowScreen(nullptr),
        m_currentScreen(nullptr),
        m_drawOneScreen(false)
    {
    }

    /////////////////////////////////////////

    ScreenManager::~ScreenManager()
    {
        if (this->m_belowScreen != nullptr)
            delete this->m_belowScreen;

        if (this->m_currentScreen != nullptr)
            delete this->m_currentScreen;
    }

    /////////////////////////////////////////

    void ScreenManager::update()
    {
        this->m_currentScreen->update();
    }

    /////////////////////////////////////////

    void ScreenManager::handleEvent()
    {
        this->m_currentScreen->handleEvent();
    }

    /////////////////////////////////////////

    void ScreenManager::draw()
    {
        if (!this->m_drawOneScreen && this->m_belowScreen != nullptr)
            this->m_belowScreen->draw();

        this->m_currentScreen->draw();
    }

    /////////////////////////////////////////

    void ScreenManager::addSreen(ScreenPtr screen, bool replace)
    {
        if (!replace)
        {
            this->m_currentScreen->pause();

            if (this->m_belowScreen != nullptr)
                delete this->m_belowScreen;

            this->m_belowScreen = this->m_currentScreen;

            this->m_currentScreen = screen;
        }
        else
        {
            delete this->m_currentScreen;

            this->m_currentScreen = screen;
        }
    }

    void ScreenManager::setNumberScreenDraw(bool drawOneScreen)
    {
        this->m_drawOneScreen = drawOneScreen;
    }
}