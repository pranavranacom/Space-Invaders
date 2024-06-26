#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.cpp"
#include "Header/GameService.h"

int main() {
    /*// Define the video mode (dimensions)
    sf::VideoMode videoMode = sf::VideoMode(800, 600);

    // Create a window object with specific dimensions and a title
    sf::RenderWindow window(videoMode, "SFML Window");

    // Using default constructor
    Player player;

    // Load the player ship texture  
    player.player_texture.loadFromFile("assets/textures/player_ship.png");

    // Set the player sprite variable to the player ship texture
    player.player_sprite.setTexture(player.player_texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Handle keyboard input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.move(-0.05f * player.getMoveSpeed());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.move(0.05f * player.getMoveSpeed());
        }

        // Clear the window
        window.clear(sf::Color::Blue);

        // Set the position of the player sprite
        player.player_sprite.setPosition(player.getPosition());

        // Draw the player sprite
        window.draw(player.player_sprite);

        // Display what was drawn
        window.display();
    }*/

    GameService* game_service = new GameService();

    game_service->ignite();

    while (game_service->isRunning())
    {
        game_service->update();
        game_service->render();
    }
    
    return 0;
}