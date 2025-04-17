#pragma once

#include <SFML/Graphics.hpp>

class Enemy
{
public:
	Enemy();
	~Enemy();

	sf::CircleShape body;
	float speed;
	int health;

	void update(float delta, const sf::Vector2f& playerPosition);
	void draw(sf::RenderWindow& window) const;

	bool takeDamage(int amount); //@todo set precalculate dmg amount
	bool isDead() const;
};
