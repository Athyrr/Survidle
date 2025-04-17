#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "Enemy.h"

class Player
{
public:

	Player();
	~Player();


	void update(float delta);
	void draw(sf::RenderWindow& window) const;

	sf::Vector2f getPosition() const;

	void setEnemies(std::vector<Enemy*>* enemyList);

private:

	// general
	sf::CircleShape body;
	float speed;

	//Attack settings
	float cooldown; //currently used for 1 attack. //@todo create vector<Attack>
	float attackTimer;
	float attackRange;

	//Enemies ref
	std::vector<Enemy*>* enemies = nullptr;

	sf::Vector2f handleInputs();
	Enemy* calculateNearestEnemy();
	bool attack();
};

