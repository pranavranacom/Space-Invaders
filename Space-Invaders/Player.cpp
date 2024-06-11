#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Player {
private:
    int health = 3;
    sf::Vector2f position = sf::Vector2f(200.0f, 100.0f);
    int movement_speed = 5;
    int player_score = 0;

public:
    // Properties
    sf::Texture player_texture;
    sf::Sprite player_sprite;

    // Functions
    void move(float offsetX) {
        position.x += offsetX;
    }

    int getMoveSpeed() {
        return movement_speed;
    }

    sf::Vector2f getPosition() {
        return position;
    }
};