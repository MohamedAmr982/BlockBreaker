#include <iostream>
#include <SFML/Graphics.hpp>


#include "GameObject.h"
#include "Paddle.h"
#include "World.h"

int main()
{
    std::cout << "Hello World!\n";
    sf::RenderWindow window(sf::VideoMode(800, 600), "Block Breaker");

    Input::setWindow(&window);

    World world;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        world.updateAll();

        world.checkForCollisions();
        
        window.clear();

        world.drawAll(window);

        window.display();

        sf::sleep(sf::milliseconds(10.0f));
    }

}
