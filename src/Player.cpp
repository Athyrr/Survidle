#include "Player.h"

Player::Player()
{
	Player::body.setPosition(sf::Vector2f(50, 50));
	Player::body.setRadius(50);
	Player::body.setFillColor(sf::Color::Red);
}

Player::~Player()
{
}


void Player::update(float delta) {
	Player::handleInputs();
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(Player::body);
}


void Player::handleInputs() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right))
	{
		sf::Vector2f position = body.getPosition();
		body.setPosition(position + (sf::Vector2f(1 * 2, 0)));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left))
	{
		sf::Vector2f position = body.getPosition();
		body.setPosition(position + (sf::Vector2f(-1 * 2, 0)));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up))
	{
		sf::Vector2f position = body.getPosition();
		body.setPosition(position + (sf::Vector2f(0 , -1 * 2)));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Down))
	{
		sf::Vector2f position = body.getPosition();
		body.setPosition(position + (sf::Vector2f(0, 1 * 2)));
	}
}