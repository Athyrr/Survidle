#include "Game.h"

#include <cstdio> 

#pragma region Lifecycle

Game::Game(sf::RenderWindow& window) : window(window) {

	//@todo Spawn nmes (temp,create Spawn manager later)
	for (int i = 0; i < 5; i++)
	{
		Enemy* e = new Enemy();
		e->body.setPosition(sf::Vector2f(10 + i * 50, 50));
		enemies.push_back(e);
	}

	player.setEnemies(&enemies);
}

Game::~Game() {

	for (Enemy* e : enemies)
		delete e;
	enemies.clear();
}

#pragma endregion


void Game::update(float delta) {

	//Update player
	Game::player.update(delta);

	// Delete dead enemies
	enemies.erase(
		std::remove_if(enemies.begin(), enemies.end(),
			[](Enemy* e) {
				if (e->isDead()) {
					printf("Enemy died\n");
					delete e;
					return true;
				}
				return false;
			}),
		enemies.end()
	);

	//Update enemies
	sf::Vector2f playerPos = Game::player.getPosition();
	for (Enemy* enemy : enemies)
		enemy->update(delta, playerPos);
}

void Game::render() {

	Game::player.draw(Game::window);

	for (Enemy* enemy : enemies)
		enemy->draw(window);
}