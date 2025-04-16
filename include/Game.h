#pragma once

#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Enemy.h"

class Game {

public:

	Game(sf::RenderWindow& window);
	~Game();

	void update(float delta);
	void render();

private:
	sf::RenderWindow& window;

	Player player;

	std::vector<Enemy> enemies;
};