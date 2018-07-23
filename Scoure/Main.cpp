#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Entity/BaseEntity/BaseEntity.hpp"
#include <Windows.h>
#include "Engine/Math/Math.hpp"

#define PI 3.1415928

int main(int argc, char* argv[])
{
    /*
    sf::RenderWindow window(sf::VideoMode(850, 500), "Space War", sf::Style::Close);
    window.setFramerateLimit(60);
    sf::Texture tx;
    tx.loadFromFile("File.jpg");
    
    //sf::Sprite sp;

    Sw::BaseEntity sp;

    sp.setTexture(tx);

    sp.setOrigin(200.f, 200.f);

    sp.setPosition(850 / 2 - 200, 250);

    //sp.rotate(30);

    Sw::BaseEntity spa;

    spa.setTexture(tx);

    spa.setOrigin(200.f, 200.f);

    spa.setPosition(850 / 2 + 300, 250);

    spa.rotate(-60);

    std::cout << std::sin(1.0*3.14159265 /180);
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed)
                window.close();
        }

        window.clear();

        window.draw(sp);

        window.draw(spa);

        window.display();

        //std::cout << sp.getGlobalBounds().left << "     " << sp.getGlobalBounds().top << std::endl;

        sp.rotate(1);

        //spa.rotate(-1.5);

        //std::cout << sp.getRotation() << std::endl;
    }
    return EXIT_SUCCESS;
    */

    //std::cout << std::cos(90 * PI / 180.0);

    std::cout << Engine::Math::sin(1);

    std::cin.get();

}