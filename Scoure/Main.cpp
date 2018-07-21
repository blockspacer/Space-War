#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity/BaseEntity/BaseEntity.hpp"

int main(int argc, char* argv[])
{
    sf::RenderWindow window(sf::VideoMode(850, 500), "Space War", sf::Style::Close);
    window.setFramerateLimit(60);

    Engine::Hitbox A(sf::Vector2f(200.f, 100.f));
    A.setPosition(300.f, 250.f);

    Engine::Hitbox B(sf::Vector2f(300.f, 200.f));
    B.setPosition(500.f, 250.f);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed)
                window.close();
        }

        window.clear();

        window.draw(A);

        window.draw(B);

        window.display();

        A.rotate(1);

        B.rotate(-1.5);
    }

    return EXIT_SUCCESS;
}