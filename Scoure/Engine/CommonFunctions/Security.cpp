/*
**   Project: Space War
**   File: Security.cpp
*/

#include "Security.hpp"

namespace Engine
{
    void Security::encode(const char* Path)
    {
        std::ifstream read(Path, std::ios_base::binary);

        if (read)
        {
            read.seekg(0, read.end);
            int length = (int)read.tellg();
            read.seekg(0, read.beg);

            char* bytes = new char[length];
            read.read(bytes, length);

            for (int i = 0; i < length; i++)
                bytes[i] += 1;

            read.close();

            std::ofstream write(Path, std::ios_base::binary);

            write.clear();

            write.write(bytes, length);

            write.close();
        }
        else
        {

#if defined(GAME_WINDOW)

    #if defined(UNICODE)

            MessageBox(nullptr, L"Có vẻ như không đủ dữ liệu để khởi động game !!!\nBạn vui lòng kiểm tra lại !!!", L"Thông Báo", MB_ICONHAND);

    #elif !defined(UNICODE)

            MessageBox(nullptr, "Looks like there is not enough data to start the game !!!\nYou should check again !!!", "Notification", MB_ICONHAND);

    #endif

#elif defined(GAME_LINUX) || defined(GAME_FREEBSD) || defined(GAME_OPENBSD)
      
            std::cout << "Looks like there is not enough data to start the game !!!\nYou should check again !!!" std::endl;

            std::cin.get();

#endif

            exit(EXIT_FAILURE);
        }
    }

    ////////////////////////////////////////////////////////////////////

    void Security::decode(const char* Path)
    {
        std::ifstream read(Path, std::ios_base::binary);

        if (read)
        {
            read.seekg(0, read.end);
            int length = (int)read.tellg();
            read.seekg(0, read.beg);

            char* bytes = new char[length];
            read.read(bytes, length);

            for (int i = 0; i < length; i++)
                bytes[i] -= 1;

            read.close();

            std::ofstream write(Path, std::ios_base::binary);

            write.clear();

            write.write(bytes, length);

            write.close();
        }
        else
        {

#if defined(GAME_WINDOW)

#if defined(UNICODE)

            MessageBox(nullptr, L"Có vẻ như không đủ dữ liệu để khởi động game !!!\nBạn vui lòng kiểm tra lại !!!", L"Thông Báo", MB_ICONHAND);

#elif !defined(UNICODE)

            MessageBox(nullptr, "Looks like there is not enough data to start the game !!!\nYou should check again !!!", "Notification", MB_ICONHAND);

#endif

#elif defined(GAME_LINUX) || defined(GAME_FREEBSD) || defined(GAME_OPENBSD)

            std::cout << "Looks like there is not enough data to start the game !!!\nYou should check again !!!" std::endl;

            std::cin.get();

#endif

            exit(EXIT_FAILURE);
        }
    }
}