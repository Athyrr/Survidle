#include "Player.h"
#include "MathUtils.h"


Player::Player()
{
	Player::speed = 100.f;
	Player::attackTimer = 0.f;
	Player::cooldown = 2.f;
	Player::attackRange = 200.f;

	Player::body.setPosition(sf::Vector2f(50, 50));
	Player::body.setRadius(50);
	Player::body.setFillColor(sf::Color::Red);
}

Player::~Player() {}


#pragma region Public API

void Player::update(float delta) {
	//Timers
	Player::attackTimer += delta;

	//Movement
	sf::Vector2f mvt = Player::handleInputs();
	Player::body.move(mvt * Player::speed * delta);

	//Attack
	if (Player::attackTimer >= Player::cooldown)
		Player::attack();
}

void Player::draw(sf::RenderWindow& window) const {
	window.draw(Player::body);

	//debug
	sf::CircleShape rangeCircle;
	rangeCircle.setRadius(Player::attackRange);
	auto x = Player::getPosition().x;
	auto y = Player::getPosition().y;
	rangeCircle.setOrigin(sf::Vector2f(x, y));
	rangeCircle.setPosition(Player::body.getPosition());
	rangeCircle.setFillColor(sf::Color::Transparent);
	rangeCircle.setOutlineColor(sf::Color::Yellow);
	rangeCircle.setOutlineThickness(1.f);
	window.draw(rangeCircle);
}

sf::Vector2f Player::getPosition() const
{
	return body.getPosition();
}

#pragma endregion


#pragma region Private API

sf::Vector2f Player::handleInputs() {

	sf::Vector2f dir(0.f, 0.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right))
		dir.x += 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left))
		dir.x -= 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up))
		dir.y -= 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Down))
		dir.y += 1;

	sf::Vector2f normalizedDir = MathUtils::Normalize(dir);
	return normalizedDir;
}

bool Player::attack() {

	if (!enemies || enemies->empty())
		return false;

	Enemy* target = Player::calculateNearestEnemy();

	if (target == nullptr || !target)
		return false;

	Player::attackTimer = 0;
	target->takeDamage(100); //@todo damage dealt
	printf("Attack\n");
	return true;
}

Enemy* Player::calculateNearestEnemy() {
	if (!enemies || enemies->empty())
		return nullptr;

	Enemy* closest = nullptr;
	float minDistSq = attackRange * attackRange;
	sf::Vector2f pos = body.getPosition();

	for (Enemy* e : *enemies) {
		sf::Vector2f distance = e->body.getPosition() - pos;
		float distSq = distance.x * distance.x + distance.y * distance.y;

		if (distSq > minDistSq)
			continue;

		minDistSq = distSq;
		closest = e;
	}

	return closest;
}


void Player::setEnemies(std::vector<Enemy*>* enemyList) {
	enemies = enemyList;
}

#pragma endregion
