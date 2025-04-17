#include "MathUtils.h"

sf::Vector2f MathUtils::Normalize(const sf::Vector2f& v) {
	float len = std::sqrt(v.x * v.x + v.y * v.y);
	if (len != 0)
		return v / len;
	return sf::Vector2f(0.f, 0.f);
}

float MathUtils::Length(const sf::Vector2f& v) {
	return std::sqrt(v.x * v.x + v.y * v.y);
}