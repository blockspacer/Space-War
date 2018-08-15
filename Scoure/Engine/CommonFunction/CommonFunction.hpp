/*
**   Project: Space War
**   File: CommonFunction.hpp
*/

#ifndef _SpaceWar_CommonFunction_HPP_
#define _SpaceWar_CommonFunction_HPP_

#include <iostream>
#include "../../Config.hpp"

namespace Engine
{
    inline void ExitMissingData()
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

    inline void SetTextColor(int color)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }

    inline void HideCursor()
    {
        CONSOLE_CURSOR_INFO Infor;

        Infor.bVisible = FALSE;

        Infor.dwSize = 10;

        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Infor);
    }

#endif

}

#endif  //   _SpaceWar_CommonFunction_HPP_