#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"

int main()
{
    // Define the video mode (dimensions)
    sf::VideoMode videoMode = sf::VideoMode(800, 600);

    // Create a window object with specific dimensions and a title
    sf::RenderWindow window(videoMode, "SFML Window");

    // the Player class
    Player player;
    // std::cout << player.movement_speed << "\\n";

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)  window.close();
        }


        // Clear the window
        window.clear(sf::Color::Magenta);

        // Display whatever you draw
        window.display();
    }

    return 0;
}