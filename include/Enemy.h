#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"

class Enemy
{
public:
	sf::CircleShape body;
	float speed;

	Enemy();
	~Enemy();

	void update(float delta,const sf::Vector2f& playerPosition);
	void draw(sf::RenderWindow& window);
};
