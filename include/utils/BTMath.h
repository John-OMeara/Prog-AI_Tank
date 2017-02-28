#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <Thor/Vectors.hpp>

namespace Math
{

	double distance(sf::Vector2f v1, sf::Vector2f v2);

	bool lineIntersectsCircle(sf::Vector2f ahead, sf::Vector2f halfAhead, sf::CircleShape circle);

	sf::Vector2f truncate(sf::Vector2f v, float const num);
}

