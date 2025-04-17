#include <cstdio> 
#include <MathUtils.h>
#include "Enemy.h"

Enemy::Enemy()
{
	Enemy::speed = 10;
	Enemy::health = 100;

	Enemy::body.setRadius(20);
	Enemy::body.setFillColor(sf::Color::Blue);
}

Enemy::~Enemy()
{
}

void Enemy::update(float delta, const sf::Vector2f& playerPosition) {

	sf::Vector2f direction = playerPosition - Enemy::body.getPosition();

	sf::Vector2f normalizedDir = MathUtils::Normalize(direction);
	body.move(normalizedDir * Enemy::speed * delta);
}

void Enemy::draw(sf::RenderWindow& window) const{
	window.draw(Enemy::body);
}

bool Enemy::takeDamage(int amount) {
	//health -= amount;
	health -= 100;
	return true;
}

bool Enemy::isDead() const {
	return health <= 0;
}