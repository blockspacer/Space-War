#include <SFML/Graphics.hpp>
#include <iostream>
#include "Application.hpp"
#include "Config.hpp"

int main(int argc, char* argv[])
{
    if (!sf::Shader::isAvailable())
    {

#ifdef GAME_WINDOW
    #if defined(UNICODE)

        MessageBox(nullptr, L"Máy tính bạn không hỗ trợ Shader !!!\nNên bạn không thể chơi game này !!!", L"Thông Báo", MB_ICONHAND);

    #elif !defined(UNICODE)

        MessageBox(nullptr, "Your computer doesn't support Shader !!!\nYou can't play this game !!!", "Notification", MB_ICONHAND);

    #endif
#else
    #if defined(GAME_LINUX) || defined(GAME_FREEBSD) || defined(GAME_OPENBSD)

        std::cout << "Your computer doesn't support Shader !!!\nYou can't play this game !!!" << std::endl;

        std::cin.get();

    #endif
#endif

        exit(EXIT_FAILURE);
    }

    Sw::Application* application = new Sw::Application;

    application->run();

    delete application;

    return EXIT_SUCCESS;
}