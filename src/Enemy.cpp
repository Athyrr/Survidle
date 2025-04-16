#include <cstdio> 
#include "Enemy.h"

Enemy::Enemy()
{
	Enemy::speed = 10;
	Enemy::body.setRadius(20);
	Enemy::body.setFillColor(sf::Color::Blue);
}

Enemy::~Enemy()
{
}

void Enemy::update(float delta, const sf::Vector2f& playerPosition) {

	sf::Vector2f direction = playerPosition - Enemy::body.getPosition();


	auto s = direction.normalized();

	//direction = Normalize(direction);
	body.move(s * Enemy::speed * delta);
}

void Enemy::draw(sf::RenderWindow& window) {
	window.draw(Enemy::body);
}

//@todo add to math lib
sf::Vector2f Normalize(const sf::Vector2f& v) {
	float length = std::sqrt(v.x * v.x + v.y * v.y);
	if (length != 0)
		return v / length;
	return sf::Vector2f(0.f, 0.f);
}
