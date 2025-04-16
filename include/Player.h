#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Player
{
public:
	Player();
	~Player();

	sf::CircleShape body;

	void draw(sf::RenderWindow& window);
	void update(float delta);

private:
	void handleInputs();
};

