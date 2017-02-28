#include "components/Display.h"

Display::Display()
: m_coord()
{
}

Display::Display(const sf::IntRect& coord)
: m_coord(coord)
, m_color(sf::Color(255, 255, 255, 255))
{
}

Display::Display(const sf::IntRect& coord, sf::Color color)
: m_coord(coord)
, m_color(color)
{
}

