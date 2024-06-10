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
	sf::Texture player_texture;
	sf::Sprite player_sprite;

	// Public Getter & Setter methods
	int getScore() {
		return player_score;
	};

	void setScore(int newScore) {
		player_score = newScore;
	};

	sf::Vector2f getPosition() {
		return position;
	}

	void setPosition(sf::Vector2f newPos) {
		position = newPos;
	}

	// New methods
	void takeDamage() {};
	void move() {};
	void shootBullets() {};
};