#include <SFML/Graphics.hpp>
#include <iostream>


int main(int argc, char* argv[])
{
    sf::RenderWindow window(sf::VideoMode(850, 500), "Space War", sf::Style::Close);
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed)
                window.close();
        }

        window.clear();

        window.display();
    }

    return EXIT_SUCCESS;
}