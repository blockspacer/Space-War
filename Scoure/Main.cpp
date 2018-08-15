#include <SFML/Graphics.hpp>
#include <iostream>
#include "Application.hpp"
#include "Config.hpp"
#include "Engine/CommonFunction/CommonFunction.hpp"
int main(int argc, char* argv[])
{
    
#ifdef _DEBUG

    #ifdef UNICODE

    SetConsoleTitle(L"Chiến Tranh Vũ Trụ");

    #else

    SetConsoleTitle("Space War");

    #endif

    Engine::HideCursor();

#endif

    if (!sf::Shader::isAvailable() || sf::Texture::getMaximumSize() < MaxSizeTexture)
    {

#ifdef GAME_WINDOW

    #if defined(UNICODE)

        MessageBox(nullptr, L"Máy tính bạn không được Game hỗ trợ !!!\nNên bạn không thể chơi game này !!!", L"Thông Báo", MB_ICONHAND);

    #elif !defined(UNICODE)

        MessageBox(nullptr, "Your computer is not supported !!!\nYou can't play this game !!!", "Notification", MB_ICONHAND);

    #endif

#else

    #if defined(GAME_LINUX) || defined(GAME_FREEBSD) || defined(GAME_OPENBSD)

        std::cout << "Your computer is not supported !!!\nYou can't play this game !!!" << std::endl;

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