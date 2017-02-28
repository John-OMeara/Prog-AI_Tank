#include "components/Position.h"

Position::Position()
: m_position()
, m_rotation(0.0)
{
}

Position::Position(const sf::Vector2f& position)
: m_position(position)
, m_rotation(0.0)
{
}

Position::Position(const sf::Vector2f& position, double rotation)
	: m_position(position)
	, m_rotation(rotation)
{
}

