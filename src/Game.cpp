#include "Game.h"

#include <cstdio> 

#pragma region Lifecycle

Game::~Game() {}

Game::Game(sf::RenderWindow& window) : window(window) {

	//Spawn nmes (temp,create Spawn manager later)
	for (int i = 0; i < 5; i++)
	{
		Enemy e;
		e.body.setPosition(sf::Vector2f(10 + i * 50, 50));
		enemies.push_back(e);
	}
}

#pragma endregion


void Game::update(float delta) {

	Game::player.update(delta);

	sf::Vector2f playerPos = Game::player.body.getPosition();
	for (Enemy& enemy : Game::enemies)
		enemy.update(delta, playerPos);
}

void Game::render() {

	Game::player.draw(Game::window);

	for (Enemy& enemy : Game::enemies) {
		enemy.draw(Game::window);
	}
}