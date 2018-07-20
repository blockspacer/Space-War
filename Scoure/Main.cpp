#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity/BaseEntity/BaseEntity.hpp"

int main(int argc, char* argv[])
{
    sf::RenderWindow window(sf::VideoMode(850, 500), "Space War", sf::Style::Close);
    window.setFramerateLimit(60);

    sf::Texture tx;
    tx.loadFromFile("Image.jpg");

    Sw::BaseEntity ba;
    ba.setTexture(tx);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed)
                window.close();
        }

        window.clear();

        window.draw(ba);

        window.display();
    }

    return EXIT_SUCCESS;
}